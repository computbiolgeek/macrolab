//
// Created by Bian on 1/27/2017.
//

#include "matrix.h"
#include "../macros.h"
#include <stdexcept>

namespace math
{

    //////////////////////////////////
    // Construction and Destruction //
    //////////////////////////////////


    /**
     * @brief Default constructor
     * @tparam t_DataType
     * @param p_num_rows
     * @param p_num_columns
     * @param p_inital_value
     */
    template<typename t_DataType>
    Matrix<t_DataType>::Matrix(size_t p_num_rows, size_t p_num_columns, const t_DataType &p_inital_value):
        m_num_rows(p_num_rows),
        m_num_columns(p_num_columns),
        m_num_elements(m_num_rows * m_num_columns)
    {
        m_matrix.resize(p_num_rows);
        for
        (
            size_t i = 0; i != m_num_rows; ++i
        )
        {
            m_matrix[i].resize(m_num_columns, p_inital_value);
        }
    }

    /**
     * @brief Copy constructor
     * @param p_matrix
     */
    template <typename t_DataType>
    Matrix<t_DataType>::Matrix(const Matrix<t_DataType> &p_matrix):
	    m_matrix(p_matrix.m_matrix),
        m_num_rows(p_matrix.m_num_rows),
        m_num_columns(p_matrix.m_num_columns),
        m_num_elements(m_num_rows * m_num_columns)
    {
		// nothing else to do
    }

	/**
	 * @brief Assignment operator
	 * @param p_rhs
	 * @return
	 */
	template <typename t_DataType>
	Matrix<t_DataType> &Matrix<t_DataType>::operator=(const Matrix &p_rhs)
	{
		if (this != &p_rhs)
		{
			m_matrix = p_rhs.m_matrix;
			m_num_rows = p_rhs.m_num_rows;
			m_num_columns = p_rhs.m_num_columns;
			m_num_elements = m_num_rows * m_num_columns;
		}
		return *this;
	}


	/////////////////
	// Data Access //
	/////////////////

	/**
	 *
	 * @return
	 */
	template <typename t_DataType>
	size_t Matrix<t_DataType>::get_rows() const
	{
		return m_num_rows;
	}

	/**
	 *
	 * @return
	 */
	template <typename t_DataType>
	size_t Matrix<t_DataType>::get_columns() const
	{
		return m_num_columns;
	}

	/**
	 *
	 * @return
	 */
	template <typename t_DataType>
	size_t Matrix<t_DataType>::GetSize() const
	{
		return m_num_elements;
	}


	/**
	 *
	 * @return
	 */
	template <typename t_DataType>
	const std::pair<size_t, size_t> Matrix<t_DataType>::GetDimension() const
	{
		return std::pair<size_t, size_t>(m_num_rows, m_num_columns);
	};

	/**
	 *
	 * @return
	 */
	template <typename t_DataType>
	const std::vector<std::vector<t_DataType> > &Matrix<t_DataType>::GetMatrix() const
	{
		return m_matrix;
	}


	////////////////
	// Operations //
	////////////////


	/**
	 * @brief Take the transpose of this matrix
	 */
	template <typename t_DataType>
	Matrix<t_DataType> Matrix<t_DataType>::Transpose() const
	{
		Matrix<t_DataType> transpose(m_num_columns, m_num_rows, 0.0);
		for (size_t i = 0; i != m_num_columns; ++i)
		{
			for (size_t j = 0; j != m_num_rows ; ++j)
			{
				transpose(i, j) = m_matrix[j][i];
			}
		}
		return transpose;
	}


	/**
	 * @brief Test whether this matrix is square
	 * @return
	 */
	template <typename t_DataType>
	bool Matrix<t_DataType>::IsSquareMatrix() const
	{
		return m_num_elements != 0 && m_num_rows == m_num_columns;
	}


	/**
	 *
	 * @param rhs
	 * @return
	 */
	template <typename t_DataType>
	Matrix<t_DataType> &Matrix<t_DataType>::operator+=(const Matrix<t_DataType> &rhs)
	{
		ASSERT
		(
            m_num_rows == rhs.m_num_rows && m_num_columns == rhs.m_num_columns,
            "matrix dimensions do not match"
		);
		for (size_t i = 0; i != m_num_rows; ++i)
		{
			for (size_t j = 0; j != m_num_columns; ++j)
			{
				m_matrix[i][j] += rhs.m_matrix[i][j];
			}
		}
		return *this;
	}

	/**
	 *
	 * @param rhs
	 * @return
	 */
	template <typename t_DataType>
	Matrix<t_DataType> &Matrix<t_DataType>::operator-=(const Matrix<t_DataType> &rhs)
	{
		ASSERT
		(
			m_num_rows == rhs.m_num_rows && m_num_columns == rhs.m_num_columns,
			"matrix dimensions do not match"
		);
		for (size_t i = 0; i != m_num_rows; ++i)
		{
			for (size_t j = 0; j != m_num_columns; ++j)
			{
				m_matrix[i][j] -= rhs.m_matrix[i][j];
			}
		}
		return *this;
	}


	/**
	 *
	 * @param rhs
	 * @return
	 */
	template <typename t_DataType>
	Matrix<t_DataType> &Matrix<t_DataType>::operator*=(const Matrix<t_DataType> &rhs)
	{
		Matrix<t_DataType> matrix_local(*this);

		// resize this matrix
		m_num_columns = rhs.m_num_columns;
		for (size_t i = 0; i != m_num_rows ; ++i)
		{
			m_matrix[i].resize(m_num_columns, 0.0);
		}

		// populate each entry of this matrix
		size_t running_indices = rhs.m_num_rows;
		for (size_t i = 0; i != m_num_rows; ++i)
		{
			for (size_t j = 0; j != m_num_columns; ++j)
			{
				t_DataType sum(0.0);
				for (size_t k = 0; k != running_indices ; ++k)
				{
					sum += matrix_local.m_matrix[i][k] * rhs.m_matrix[k][j];
				}
				m_matrix[i][j] = sum;
			}
		}
		return *this;
	}

	/**
	 *
	 * @param i
	 * @param j
	 * @return
	 */
	template <typename t_DataType>
	t_DataType &Matrix<t_DataType>::operator()(size_t i, size_t j)
	{
		if (i >= m_num_rows || j >= m_num_columns)
		{
			throw std::out_of_range("Matrix subscript out of bounds");
		}
		return m_matrix[i][j];
	}

	/**
	 *
	 * @param i
	 * @param j
	 * @return
	 */
	template <typename t_DataType>
	const t_DataType &Matrix<t_DataType>::operator()(size_t i, size_t j) const
	{
		if (i >= m_num_rows || j >= m_num_columns)
		{
			throw std::out_of_range("Matrix subscript out of bounds");
		}
		return m_matrix[i][j];
	}



} // end of namespace math