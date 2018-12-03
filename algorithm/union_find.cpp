//
// Created by Bian Li on 8/26/18.
//

#include "union_find.h"

namespace algorithm
{
    /**
     * @brief Initialize n sites with integer names (0 to n - 1)
     * @param n Number of sites.
     */
    UnionFind::UnionFind(size_t n):
        m_ids(new int[n]),
        m_length(n),
        m_count(n)
    {
        for (size_t i = 0; i < m_length; ++i) {
            m_ids[i] = i;
        }
    }


    /**
     * @brief Add connection between p and q.
     * @param p One element of the given pair.
     * @param q The other element of the given pair.
     */
    void UnionFind::make_union(size_t p, size_t q)
    {
        size_t p_id = find(p);
        size_t q_id = find(q);

        if (p_id == q_id) {
            return;
        }

        for (size_t i = 0; i < m_length; ++i) {
            if (m_ids[i] == p_id) {
                m_ids[i] = q_id;
            }
        }

        m_count--;
    }


    /**
     * @brief Find the component ID of the given element.
     * @param p
     * @return The component ID of the given element.
     */
    size_t UnionFind::find(size_t p) const
    {
        return m_ids[p];
    }

    /**
     * @brief Check whether the two given elements are connected.
     * @param p
     * @param q
     * @return True if the two given elements are connected.
     */
    bool UnionFind::connected(size_t p, size_t q) const
    {
        return find(p) == find(q);
    }

    /**
     * @brief Count the number of components.
     * @return The number of components.
     */
    size_t UnionFind::count() const
    {
        return m_count;
    }

    /**
     * @brief Count the number of objects.
     * @return The number of objects.
     */
    size_t UnionFind::length() const
    {
        return m_length;
    }
}
