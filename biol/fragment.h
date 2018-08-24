//
// Created by Bian on 1/26/2017.
//

#ifndef PDOCK_FRAGMENT_H
#define PDOCK_FRAGMENT_H


#include <vector>
#include "../math/coord3d.h"

namespace biol
{

    class Fragment
    {

    private:

        //!
        std::vector<math::Vector3D> m_ReferenceCoords;

        //! modifiable by const member functions
        mutable std::vector<math::Vector3D> m_MovedCoords;

        //! rotation matrix
        double m_RotationMatrix[4][4];

        //!


    public:

        //////////////////////////////////
        // Construction and Destruction //
        //////////////////////////////////

        /**
         *
         */
        Fragment();


        /**
         * @brief Copy constructor
         * @param fragment
         */
        Fragment(const Fragment &fragment);


        /**
         * @brief Translate this fragment
         * @param vector
         */
        void Translate(const math::Vector3D &vector);


        /**
         * @brief Get the length of this fragment
         * @return
         */
        inline size_t GetLength() const
        {
            return m_ReferenceCoords.size();
        }


    }; // end of class Fragment
} // end of namespace biol

#endif //PDOCK_FRAGMENT_H
