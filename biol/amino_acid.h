//
// Created by Bian on 2/1/2017.
//

#ifndef PDOCK_AMINO_ACID_PROPERTY_H
#define PDOCK_AMINO_ACID_PROPERTY_H

#include <string>
#include <set>
#include "atom.h"
#include "amino_acid_constants.h"

namespace biol
{
    class AminoAcid
    {
        public:

            // an enum type (named integer constants): properties of amino acids
            enum Property
            {
                e_molecular_weight,
                e_hydrophobicity,
                e_polarizability,
                e_charge,
                e_volume, // amino acid van der Waals volume
                e_asa, // accessible surface area
                e_natural_occurrence,
                i_number_of_properties
            };

        private:

            // three letter code
            constants::AminoAcidTypes m_type;

            // the set of atoms
            std::set<biol::Atom> m_atoms;

            // array tha contains the physicochemical properties
            double m_properties[i_number_of_properties];

        public:

            /**
             *
             * @param p_amino_acid_type
             * @param p_atoms
             * @param p_properties
             */
            AminoAcid
            (
                const constants::AminoAcidTypes p_amino_acid_type,
                const std::set<Atom> &p_atoms,
                double p_properties[i_number_of_properties]
            );


            /**
             * @brief Constructor.
             * @param p_three_letter_code
             * @param p_molecular_weight
             * @param p_hydrophobicity
             * @param p_polarizability
             * @param p_charge
             * @param p_volume
             * @param p_asa
             * @param p_natural_occurrence
             */
            AminoAcid
            (
                const std::string &p_three_letter_code,
                double p_molecular_weight = 0.0,
                double p_hydrophobicity = 0.0,
                double p_polarizability = 0.0,
                double p_charge = 0.0,
                double p_volume = 0.0,
                double p_asa = 0.0,
                double p_natural_occurrence = 0.0
            );


            /**
             * @brief Get the three letter code of this amino acid
             * @return the three letter code of this amino acid
             */
            const std::string &get_three_letter_code() const;


            /**
             * @brief Get the one letter code of this amino acid
             * @return the one letter code of this amino acid
             */
            unsigned char get_one_letter_code() const;


            /**
             * @brief Get all atoms of this amino acid
             * @return all atoms of this amino acid
             */
            const std::set<biol::Atom> &get_atoms() const;


            /**
             * @brief Set the atoms for this amino acid.
             * @param p_atoms Atoms for this amino acid.
             */
            void set_atoms(const std::set<Atom> &p_atoms);


            /**
             * @brief Get the requested property of this amino acid
             * @param p_property the requested property
             * @return the requested property
             */
            double get_property(Property p_property) const;


            /**
             * @brief Get the alpha carbon of this amino acid.
             * @return The alpha carbon of this amino acid.
             */
            const biol::Atom &get_ca() const;


            /**
             * @brief Get the alpha carbon of this amino acid.
             * @return The alpha carbon of this amino acid.
             */
            const biol::Atom &get_cb() const;


            /**
             * @todo To be implemented!
             * @brief Compute the Cartesian coordinates of sidechain centroid.
             * @return The Cartesian coordinates of sidechain centroid.
             */
            math::Coord3D compute_sidechain_centroid() const;
    }; // end of class AminoAcid
} // end of namespace biol

#endif //PDOCK_AMINO_ACID_PROPERTY_H
