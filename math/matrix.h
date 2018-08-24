//
// Created by Bian on 1/27/2017.
//

#ifndef PDOCK_MATRIX_H
#define PDOCK_MATRIX_H


#include <cstddef>
#include <utility>
#include <vector>
#include "coord3d.h"

namespace math
{
    template <typename t_data_type>
    class Matrix
    {
    private:

        // the actual data structure that holds the matrix
        std::vector<std::vector<t_data_type> > m_matrix;

        // number of rows
        size_t  m_num_rows;

        // number of columns
        size_t m_num_columns;

        // size
        size_t m_num_elements;

    public:


        /**
         * @brief Default constructor
         * @param p_num_rows
         * @param columns
         * @param inital_value
         */
        Matrix(size_t p_num_rows, size_t p_num_columns, const t_data_type &p_inital_value);


        /**
         * @brief Copy constructor
         * @param p_matrix
         */
        Matrix(const Matrix<t_data_type> &p_matrix);


        /**
         * @brief Assignment operator
         * @param p_rhs
         * @return
         */
	    Matrix &operator=(const Matrix &p_rhs);


        /**
         *
         * @return
         */
        size_t get_rows() const;


        /**
         *
         * @return
         */
        size_t get_columns() const;


        /**
         *
         * @return
         */
        size_t GetSize() const;


	    /**
	     *
	     * @return
	     */
	    const std::pair<size_t, size_t> GetDimension() const;


        /**
         *
         * @return
         */
        const std::vector<std::vector<t_data_type> > &GetMatrix() const;


	    /**
	     * @brief Take the transpose of this matrix
	     */
	    Matrix Transpose() const;


	    /**
	     * @brief Test whether this matrix is square
	     * @return
	     */
	    bool IsSquareMatrix() const;


        /**
         *
         * @param rhs
         * @return
         */
        Matrix &operator+=(const Matrix &rhs);

        /**
         *
         * @param rhs
         * @return
         */
        Matrix &operator-=(const Matrix &rhs);


	    /**
	     *
	     * @param rhs
	     * @return
	     */
	    Matrix &operator*=(const Matrix &rhs);


	    /**
	     *
	     * @param i
	     * @param j
	     * @return
	     */
	    t_data_type &operator()(size_t i, size_t j);


	    /**
	     *
	     * @param i
	     * @param j
	     * @return
	     */
	    const t_data_type &operator()(size_t i, size_t j) const;

    }; // end of class matrix

    /**
	 *
	 * @param lhs
	 * @param rhs
	 * @return
	 */
    template <typename t_DataType>
    Matrix<t_DataType> operator+(const Matrix<t_DataType> &lhs, const Matrix<t_DataType> &rhs)
    {
        Matrix<t_DataType> matrix_copy(lhs);
        matrix_copy += rhs;
        return matrix_copy;
    }


    /**
	 *
	 * @param lhs
	 * @param rhs
	 * @return
	 */
    template <typename t_DataType>
    Matrix<t_DataType> operator-(const Matrix<t_DataType> &lhs, const Matrix<t_DataType> &rhs)
    {
        Matrix<t_DataType> matrix_copy(lhs);
        matrix_copy -= rhs;
        return matrix_copy;
    }


	/**
	 *
	 * @tparam t_DataType
	 * @param lhs
	 * @param rhs
	 * @return
	 */
	template <typename t_DataType>
	Matrix<t_DataType> operator*(const Matrix<t_DataType> &lhs, const Matrix<t_DataType> &rhs)
	{
		Matrix<t_DataType> matrix_copy(lhs);
		matrix_copy *= rhs;
		return matrix_copy;
	}


	/**
	 *
	 * @param lhs
	 * @param rhs
	 * @return
	 */
	math::Coord3D operator*(const Matrix<double> &lhs, const math::Coord3D &rhs)
	{
		std::vector<double> vector(lhs.get_rows());
		for (size_t i = 0; i != lhs.get_rows(); ++i)
		{
			for (size_t j = 0; j != 3 ; ++j)
			{
				vector[i] += lhs(i, j) * rhs[j];
			}
		}
		return math::Coord3D(vector[0], vector[1], vector[2]);
	}

	/**
	 *
	 * @tparam t_DataType
	 * @param matrix
	 * @return
	 */
	template <typename t_DataType>
	std::ostream &operator<<(std::ostream &o_stream, const Matrix<t_DataType> &matrix)
	{
		for (size_t i = 0; i != matrix.get_rows() ; ++i)
		{
			o_stream << matrix.GetMatrix()[i][0];
			for (size_t j = 1; j != matrix.get_columns() ; ++j)
			{
				o_stream << "," << matrix.GetMatrix()[i][j];
			}
			o_stream << std::endl;
		}
		return o_stream;
	}
} // end of namespace math

#include "matrix.cpp"

#endif //PDOCK_MATRIX_H
