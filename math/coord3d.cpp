//
// Created by Bian on 1/24/2017.
//

#include "coord3d.h"
#include <math.h>
#include "../macros.h"


namespace math
{

    /**
     *
     * @param p_x
     * @param p_y
     * @param p_z
     */
    Coord3D::Coord3D(double p_x, double p_y, double p_z) :
        m_x(p_x),
        m_y(p_y),
        m_z(p_z)
    {
        // nothing else to do
    }

    /**
     * @brief Copy constructor
     * @param rhs
     */
    Coord3D::Coord3D(const Coord3D &rhs) :
        m_x(rhs.m_x),
        m_y(rhs.m_y),
        m_z(rhs.m_z)
    {
        // nothing else to do
    }

    /**
     * @brief Assignment operator
     * @param p_rhs
     * @return
     */
    Coord3D &Coord3D::operator=(const Coord3D &p_rhs)
    {
        if (this != &p_rhs) {
            m_x = p_rhs.m_x;
            m_y = p_rhs.m_y;
            m_z = p_rhs.m_z;
        }
        return *this;
    }

    /**
     *
     * @return
     */
    double Coord3D::get_x() const
    {
        return m_x;
    }

    /**
     *
     * @param X
     */
    void Coord3D::set_x(double p_x)
    {
        m_x = p_x;
    }

    /**
     *
     * @return
     */
    double Coord3D::get_y() const
    {
        return m_y;
    }

    /**
     *
     * @param Y
     */
    void Coord3D::set_y(double p_y)
    {
        m_y = p_y;
    }

    /**
     *
     * @return
     */
    double Coord3D::get_z() const
    {
        return m_z;
    }

    /**
     *
     * @param p_z
     */
    void Coord3D::set_z(double p_z)
    {
        m_z = p_z;
    }


    /**
     * @brief Overloads the insertion operator >>.
     * @param o_stream an object of type std::ostream
     * @param p_rhs an object of type Vector3D
     * @return reference to o_stream whose state is modified
     */
    std::ostream &operator<<(std::ostream &o_stream, const Coord3D &p_rhs)
    {
        o_stream << "(" << p_rhs.m_x << ", " << p_rhs.m_y << ", " << p_rhs.m_z << ")";
        return o_stream;
    }


    //////////////////////
    // Member Functions //
    //////////////////////


    /**
     * Translate a vector
     * @param t_matrix A 4 by 4 translation matrix
     */
    void Coord3D::translate(const Coord3D &p_vector_3d)
    {
        (*this) += p_vector_3d;
    }

    /**
     * Rotate a vector
     * @param angle
     */
    void rotate(double theta);

    /**
     *
     * @param factor
     */
    void Coord3D::scale(double factor)
    {
        m_x *= factor;
        m_y *= factor;
        m_z *= factor;
    }

    /***
     *
     */
    void Coord3D::normalize()
    {
        scale(1 / norm());
    }

    /**
     *
     * @param p
     * @return
     */
    double Coord3D::pnorm(double p) const
    {
        return pow(pow(m_x, p) + pow(m_y, p) + pow(m_z, p), 1 / p);
    }

    /***
     *
     * @return
     */
    double Coord3D::norm() const
    {
        return pnorm(2.0);
    }

    /**
     * @brief Test to see whether the vector is zero
     * @return
     */
    bool Coord3D::is_zero_vector() const
    {
        return *this == Coord3D(0.0, 0.0, 0.0);
    }

    /**
     * @brief Compute the dot product with a given vector.
     * @param p_vector_3d Given vector.
     * @return The dot product of this vector with the given vector.
     */
    double Coord3D::dot(const Coord3D &p_vector_3d) const
    {
        return m_x * p_vector_3d.m_x + m_y * p_vector_3d.m_y + m_z * p_vector_3d.m_z;
    }


    /**
     *
     * @param vector_3d
     * @return
     */
    bool Coord3D::is_orthogonal(const Coord3D &vector_3d) const
    {
        return this->dot(vector_3d) == 0;
    }

    /**
     * @brief Compute the angle in radians between this vector and a given vector
     * @param vector_3d
     * @return
     */
    double Coord3D::angle(const Coord3D &vector_3d) const
    {
        return acos((*this).dot(vector_3d) / ((*this).norm() * vector_3d.norm()));
    }

} // end of namespace math
