//
// Created by Bian on 2/1/2017.
//

#include "amino_acid.h"
#include "amino_acid_constants.h"

namespace biol
{

    /**
     *
     * @param p_amino_acid_type
     * @param p_atoms
     * @param p_properties
     */
    AminoAcid::AminoAcid
    (
        const constants::AminoAcidTypes p_amino_acid_type,
        const std::set<Atom> &p_atoms,
        double p_properties[i_number_of_properties]
    ) :
        m_type(p_amino_acid_type),
        m_atoms(p_atoms)
    {
        for (int i = 0; i < i_number_of_properties; ++i) {
            m_properties[i] = p_properties[i];
        }
    }

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
	AminoAcid::AminoAcid
	(
        const std::string &p_three_letter_code,
        double p_molecular_weight,
        double p_hydrophobicity,
        double p_polarizability,
        double p_charge,
        double p_volume,
        double p_asa,
        double p_natural_occurrence
	) :
        m_type
        (
            constants::THREE_LETTER_CODES_TO_TYPES.find(p_three_letter_code)->second
        )
	{
		// initialize the property array
		m_properties[e_molecular_weight] = p_molecular_weight;
		m_properties[e_hydrophobicity] = p_hydrophobicity;
		m_properties[e_polarizability] = p_polarizability;
		m_properties[e_charge] = p_charge;
		m_properties[e_volume] = p_volume;
		m_properties[e_asa] = p_asa;
		m_properties[e_natural_occurrence] = p_natural_occurrence;
	}

	/**
	 * @brief Get the three letter code of this amino acid
	 * @return the three letter code of this amino acid
	 */
	const std::string &AminoAcid::get_three_letter_code() const
	{
		return constants::AMINO_ACID_THREE_LETTER_CODES[m_type];
	}

	/**
	 * @brief Get the one letter code of this amino acid
	 * @return the one letter code of this amino acid
	 */
	unsigned char AminoAcid::get_one_letter_code() const
	{
	    constants::ONE_LETTER_CODE_TO_TYPES.find(m_type)->first;
	}

	/**
	 * @brief Get all atoms of this amino acid
	 * @return all atoms of this amino acid
	 */
	const std::set<biol::Atom> &AminoAcid::get_atoms() const
	{
		return m_atoms;
	}

	/**
	 * @brief Get the requested property of this amino acid
	 * @param p_property the requested property
	 * @return the requested property
	 */
	double AminoAcid::get_property(Property p_property) const
	{
		// recall that Property is an enum type
		return m_properties[p_property];
	}


    /**
     * @brief Set the atoms for this amino acid.
     * @param p_atoms Atoms for this amino acid.
     */
	void AminoAcid::set_atoms(const std::set<Atom> &p_atoms)
	{
		m_atoms = p_atoms;
	}


    /**
     * @brief Get the alpha carbon of this amino acid.
     * @return The alpha carbon of this amino acid.
     */
	const biol::Atom &AminoAcid::get_ca() const
	{
		for (auto itr(m_atoms.begin()), itr_end(m_atoms.end()); itr != itr_end; ++itr) {
			if (itr->get_atom_type() == constants::e_CA)
			{
				return *itr;
			}
		}
	}


    /**
     * @brief Get the alpha carbon of this amino acid. For GLY, return the alpha carbon instead.
     * @return The alpha carbon of this amino acid.
     */
	const biol::Atom& AminoAcid::get_cb() const
    {
        if (m_type == constants::e_GLY) {
            return get_ca();
        }
        for (auto itr(m_atoms.begin()), itr_end(m_atoms.end()); itr != itr_end; ++itr) {
            if (itr->get_atom_type() == constants::e_CB) {
                return *itr;
            }
        }
    }


    /**
     * @todo To be implemented!
     * @brief Compute the Cartesian coordinates of sidechain centroid.
     * @return The Cartesian coordinates of sidechain centroid.
     */
    math::Coord3D AminoAcid::compute_sidechain_centroid() const
    {
        return math::Coord3D(0.0, 0.0, 0.0);
    }
} // end of namespace biol
