//
// Created by Bian on 2/4/2017.
//

#include "residue.h"

namespace biol
{

	/**
	 * @brief constructor
	 * @param ThreeLetterCode
	 * @param OneLetterCode
	 * @param SeqID
	 * @param ChainID
	 * @param PDBID
	 */
	biol::Residue::Residue
	(
		const std::string &ThreeLetterCode,
		char OneLetterCode,
		size_t SeqID,
		char ChainID,
	) :
		AminoAcid(ThreeLetterCode, OneLetterCode),
		m_seq_id(SeqID),
		m_chain_id(ChainID)
	{
		// nothing else to do
	}


	/////////////////
	// data access //
	/////////////////


	/**
	 * Get the sequence index of this amino acid residue.
	 * @return The sequence index of this amino acid residue.
	 */
	size_t Residue::get_seq_id() const
	{
		return m_seq_id;
	}

	/**
	 * Get the ID of the chain that contains this amino acid residue.
	 * @return The ID of the chain that contains this amino acid residue.
	 */
	char Residue::get_chain_id() const
	{
		return m_chain_id;
	}


	/**
	 * Set the sequence index of this amino acid residue.
	 * @param p_seq_id New sequence index.
	 */
	void Residue::set_seq_id(size_t p_seq_id)
	{
		m_seq_id = p_seq_id;
	}

	/**
	 * Set the ID of the chain that contains this amino acid residue.
	 * @param p_chain_id New chain ID.
	 */
	void Residue::set_chain_id(char p_chain_id)
	{
		m_chain_id = p_chain_id;
	}

} // end of namespace biol
