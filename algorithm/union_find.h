//
// Created by Bian Li on 8/26/18.
//

#ifndef MACROLAB_UNION_FIND_H
#define MACROLAB_UNION_FIND_H

#include <vector>

namespace algorithm
{
    class UnionFind
    {
    private:

        // pointer to a dynamic array that holds component IDs
        int * m_ids;

        // number of items
        size_t m_length;

        // the number of components.
        size_t m_count;

    public:

        /**
         * @brief Initialize a UnionFind data structure.
         * @param n
         */
        UnionFind(size_t n);

        /**
         * @brief
         * @param p
         * @param q
         */
        void make_union(size_t p, size_t q);

        /**
         * @brief Find the component ID of the given element.
         * @param p
         * @return The component ID of the given element.
         */
        size_t find(size_t p) const;

        /**
         * @brief Check whether the two given elements are connected.
         * @param p
         * @param q
         * @return True if the two given elements are connected.
         */
        bool connected(size_t p, size_t q) const;

        /**
         * @brief Count the number of components.
         * @return The number of components.
         */
        size_t count() const;

        /**
         * @brief Count the number of objects.
         * @return The number of objects.
         */
        size_t length() const;

    };
}

#endif //MACROLAB_UNION_FIND_H
