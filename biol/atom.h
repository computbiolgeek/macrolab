#ifndef MACROLAB_ATOM_H
#define MACROLAB_ATOM_H

#include <string>
#include "../math/coord3d.h"
#include "atom_constants.h"
#include "amino_acid_constants.h"

namespace biol
{

    class Atom
    {

        private:

            // type of the atom
            constants::AtomTypes m_atom_type;

            // type of the residue to which this atom belongs
            constants::AminoAcidTypes m_residue_type;

            // atomic weight of this atom
            double m_atomic_weight;

            // Cartesian coordinates of this atom
            math::Coord3D m_coord;

            // partial charge of this atom
            double m_partial_charge;

            // crystallography b-factor associated with this atom
            double m_bfactor;

            // crystallographt occupancy associated with this atom
            double m_occupancy;

            // whether this is an alternative location
            bool m_altloc;

        public:

            /**
             * @brief Constructor.
             * @param p_atom_type Type of the atom.
             * @param p_residue_type The residue to which this atom belongs.
             * @param p_atomic_weight Atomic weight.
             * @param p_coord Cartesian coordinates.
             * @param p_partial_charge Partial charge.
             * @param p_bfactor Crystallography b factor.
             * @param p_occupancy Crystallography occupancy.
             * @param p_altloc Whether this atom has alternative location.
             */
            Atom
            (
                const constants::AtomTypes &p_atom_type,
                const constants::AminoAcidTypes &p_residue_type,
                double p_atomic_weight = 0.0,
                const math::Coord3D &p_coords = math::Coord3D(),
                double p_partial_charge = 0.0,
                double p_bfactor = 0.0,
                double p_occupancy = 0.0,
                bool p_altloc = false
            );

            /**
             * @brief Get the type of this atom.
             * @return The type of this atom.
             */
            const constants::AtomTypes &get_atom_type() const;


            /**
             * @brief Set the type of this atom.
             * @param p_atom_type New atom type.
             */
            void set_atom_type(const constants::AtomTypes &p_atom_type);


            /**
             * @brief Get the name of this atom.
             * @return The name of this atom.
             */
            const std::string &get_atom_name() const;


            /**
             * @brief Get the type of the residue to which this atom belongs.
             * @return The type of the residue to which this atom belongs.
             */
            const constants::AminoAcidTypes &get_residue_type() const;


            /**
             * @brief Set the type of the residue to which this atom belongs.
             * @param p_residue_type New residue type.
             */
            void set_residue_type(const constants::AminoAcidTypes &p_residue_type);


            /**
             * @brief Get the atomic weight of this atom.
             * @return The atomic weight of this atom.
             */
            double get_atomic_weight() const;


            /**
             * @brief Set the atomic weight of this atom.
             * @param p_AtomicWeight New atomic weight.
             */
            void set_atomic_weight(double p_atomic_weight);


            /**
             * @brief Get the Cartesian coordinates of this atom.
             * @return The Cartesian coordinates of this atom.
             */
            const math::Coord3D &get_coord() const;


            /**
             * @brief Set the Cartesian coordinates of this atom.
             * @param p_coord New Cartesian coordinates.
             */
            void set_coord(const math::Coord3D &p_coord);


            /**
             * @brief Get the partial charge of this atom.
             * @return The partial charge of this atom.
             */
            double get_partial_charge() const;

            /**
             * @brief Set the partial charge of this atom.
             * @param p_partial_charge New partial charge.
             */
            void set_partial_charge(double p_partial_charge);


            /**
             * @brief Get the b-factor of this atom.
             * @return The b-factor of this atom.
             */
            double get_bfactor() const;


            /**
             * @brief Set the b-factor of this atom.
             * @param p_bfactor New b-factor.
             */
            void set_bfactor(double p_bfactor);


            /**
             * @brief Get the occupancy value of this atom.
             * @return The occupancy value of this atom.
             */
            double get_occupancy() const;


            /**
             * @brief Set the occupancy value of this atom.
             * @param p_occupancy New occupancy value.
             */
            void set_occupancy(double p_occupancy);


            /**
             * @brief Overload the - operator for calculating the Euclidean distance between two atoms.
             * @param p_rhs The right-hand atom.
             * @return The Euclidean distance between the two atoms.
             */
            double operator-(const Atom &p_rhs) const;


            /**
             * @brief Translate this atom along a given vector.
             * @param p_vector_3d A given vector.
             */
            void translate(const math::Coord3D &p_vector_3d);


            /**
             * @brief Get the status of alternative location.
             * @return The status of alternative location.
             */
            bool has_altloc() const;

    }; // end of class Atom

} // end of namespace biol


#endif //MACROLAB_ATOM_H
