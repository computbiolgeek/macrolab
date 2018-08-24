//
// Created by Bian on 1/24/2017.
//

#ifndef MACROLAB_COORD3D_H
#define MACROLAB_COORD3D_H


#include <iosfwd>
#include "../macros.h"
#include <stdexcept>
#include <vector>

namespace math
{

    class Coord3D
    {

    private:

        //! x coordinate
        double m_x;

        //! y coordinate
        double m_y;

        //! z coordinate
        double m_z;

    public:

        //////////////////////////////////
        // Construction and Destruction //
        //////////////////////////////////

        /**
         * @brief Constructor.
         * @param m_x
         * @param p_y
         * @param p_z
         */
        Coord3D(double m_x = 0.0, double p_y = 0.0, double p_z = 0.0);

        /**
         * @brief Copy constructor
         * @param rhs
         */
        Coord3D(const Coord3D &rhs);


        /**
         * @brief Assignment operator
         * @param p_rhs
         * @return
         */
        Coord3D &operator=(const Coord3D &p_rhs);


        /////////////////
        // Data Access //
        /////////////////

        /**
         *
         * @return
         */
        double get_x() const;

        /**
         * @brief
         * @param p_x
         */
        void set_x(double p_x);

        /**
         *
         * @return
         */
        double get_y() const;

        /**
         *
         * @param p_y
         */
        void set_y(double p_y);

        /**
         *
         * @return
         */
        double get_z() const;

        /**
         * @brief
         * @param p_z
         */
        void set_z(double p_z);

        //////////////////////////
        // Operator Overloading //
        //////////////////////////


        /**
         * Compound assignment
         * @param p_rhs
         * @return
         */
        inline Coord3D &operator+=(const Coord3D &p_rhs)
        {
            m_x += p_rhs.m_x;
            m_y += p_rhs.m_y;
            m_z += p_rhs.m_z;
            return *this;
        }

        /**
         *
         * @param p_rhs
         * @return
         */
        inline Coord3D &operator-=(const Coord3D &p_rhs)
        {
            m_x -= p_rhs.m_x;
            m_y -= p_rhs.m_y;
            m_z -= p_rhs.m_z;
            return *this;
        }

        /**
         * Compound assignment
         * @param p_rhs
         * @return
         */
        inline Coord3D &operator*=(const Coord3D &p_rhs)
        {
            m_x *= p_rhs.m_x;
            m_y *= p_rhs.m_y;
            m_z *= p_rhs.m_z;
            return *this;
        }

        /**
         * Compound assignment
         * @param p_rhs
         * @return
         */
        inline Coord3D &operator/=(const Coord3D &p_rhs)
        {
            ASSERT(!(p_rhs.m_x == 0 || p_rhs.m_y == 0 || p_rhs.m_z == 0), "division by zero");
            m_x /= p_rhs.m_x;
            m_y /= p_rhs.m_y;
            m_z /= p_rhs.m_z;
            return *this;
        }

        /**
         *
         * @param i
         * @return
         */
        inline double &operator[](size_t i)
        {
            if (i >= 3)
            {
                throw std::out_of_range("Coord3D subscript out of range");
            }
            switch (i)
            {
                case 0:
                    return m_x;
                case 1:
                    return m_y;
                case 2:
                    return m_z;
            }
        }


        /**
         *
         * @param i
         * @return
         */
        inline const double &operator[](size_t i) const
        {
            if (i >= 3)
            {
                throw std::out_of_range("Coord3D subscript out of range");
            }
            switch (i)
            {
                case 0:
                    return m_x;
                case 1:
                    return m_y;
                case 2:
                    return m_z;
            }
        }

        /**
         * @brief Overloads the insertion operator >>.
         * @param o_stream an object of type std::ostream
         * @param rhs an object of type Vector3D
         * @return reference to o_stream whose state is modified
         */
        friend std::ostream &operator<<(std::ostream &o_stream, const Coord3D &rhs);

        //////////////////////
        // Member Functions //
        //////////////////////


        /**
         * Translate a vector
         * @param p_vector_3d
         */
        void translate(const Coord3D &p_vector_3d);


        /**
         * @TODO
         * @param t_matrix
         */
        void TransformRigid(const double t_matrix);

        /**
         * @TODO
         * @param factor
         */
        void scale(double factor);

        /***
         *
         */
        void normalize();

        /**
         *
         * @param p
         * @return
         */
        double pnorm(double p) const;


        /***
         *
         * @return
         */
        double norm() const;

        /**
         * @brief Test to see whether the vector is zero
         * @return
         */
        bool is_zero_vector() const;

        /**
         * @brief Compute the dot product with a given vector.
         * @param p_vector_3d Given vector.
         * @return The dot product of this vector with the given vector.
         */
        double dot(const Coord3D &p_vector_3d) const;

        /**
         *
         * @param vector_3d
         * @return
         */
        bool is_orthogonal(const Coord3D &vector_3d) const;

        /**
         * @brief Compute the angle in radians between this vector and a given vector
         * @param vector_3d
         * @return
         */
        double angle(const Coord3D &vector_3d) const;

    };


    //////////////////////////
    // Operator Overloading //
    //////////////////////////


    /**
     *
     * @param lhs
     * @param rhs
     * @return
     */
    inline Coord3D operator+(const Coord3D &lhs, const Coord3D &rhs)
    {
        Coord3D local_copy(lhs);
        local_copy += rhs;
        return local_copy;
    }


    /**
     *
     * @param lhs
     * @param rhs
     * @return
     */
    inline Coord3D operator-(const Coord3D &lhs, const Coord3D &rhs)
    {
        Coord3D local_copy(lhs);
        local_copy -= rhs;
        return local_copy;
    }

    /**
     *
     * @param lhs
     * @param rhs
     * @return
     */
    inline Coord3D operator*(const Coord3D &lhs, const Coord3D &rhs)
    {
        Coord3D local_copy(lhs);
        local_copy *= rhs;
        return local_copy;
    }

    /**
     *
     * @param rhs
     * @return
     */
    inline Coord3D operator*(const Coord3D &lhs, double rhs)
    {
        return Coord3D(lhs.get_x() * rhs, lhs.get_y() * rhs, lhs.get_z() * rhs);
    }

    /**
     *
     * @param lhs
     * @param rhs
     * @return
     */
    inline Coord3D operator*(double lhs, const Coord3D &rhs)
    {
        return Coord3D(lhs * rhs.get_x(), lhs * rhs.get_y(), lhs * rhs.get_z());
    }

    /**
     *
     * @param lhs
     * @param rhs
     * @return
     */
    inline Coord3D operator/(const Coord3D &lhs, const Coord3D &rhs)
    {
        Coord3D local_copy(lhs);
        local_copy /= rhs;
        return local_copy;
    }

    /**
     *
     * @param lhs
     * @param rhs
     * @return
     */
    inline Coord3D operator/(const Coord3D &lhs, double rhs)
    {
        ASSERT(rhs != 0, "division by zero");
        return lhs * (1 / rhs);
    }


    /**
     *
     * @param lhs
     * @param rhs
     * @return
     */
    inline bool operator==(const Coord3D &lhs, const Coord3D &rhs)
    {
        return lhs.get_x() == rhs.get_x() && lhs.get_y() && rhs.get_y() && lhs.get_z() && rhs.get_z();
    }


    /**
     *
     * @param lhs
     * @param rhs
     * @return
     */
    inline bool operator!=(const Coord3D &lhs, const Coord3D &rhs)
    {
        return !(lhs == rhs);
    }
} // end of namespace math

#endif //MACROLAB_COORD3D_H
