//
// Created by Bian on 2/1/2017.
//

#ifndef PDOCK_AMINO_ACID_PDB_H
#define PDOCK_AMINO_ACID_PDB_H

#include <string>
#include <set>
#include "amino_acid.h"
#include "atom.h"

namespace biol
{
	class Residue:
		public AminoAcid
	{

	private:

		// ID number along the sequence
		int m_seq_id;

		// ID of the chain where the amino acid sits
		unsigned char m_chain_id;

	public:

		/**
		 * @brief constructor
		 * @param p_three_letter_code
		 * @param p_one_letter_code
		 * @param p_seq_id
		 * @param p_chain_id
		 */
		Residue
		(
			const std::string &p_three_letter_code,
			char p_one_letter_code,
			size_t p_seq_id,
			char p_chain_id
		);


		/**
		 *
		 * @return
		 */
		size_t get_seq_id() const;


		/**
		 *
		 * @return
		 */
		char get_chain_id() const;

		/**
		 *
		 * @param p_seq_id
		 */
		void set_seq_id(int p_seq_id);

		/**
		 *
		 * @param p_chain_id
		 */
		void set_chain_id(char p_chain_id);


	}; // end of class Residue
} // end of namespace biol


#endif //PDOCK_AMINO_ACID_PDB_H
