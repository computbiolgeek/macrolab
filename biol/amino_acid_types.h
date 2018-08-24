//
// Created by Bian on 2/1/2017.
//

#ifndef PDOCK_AMINO_ACID_TYPE_H
#define PDOCK_AMINO_ACID_TYPE_H

#include "amino_acid.h"
#include "../util/util_enumerate.h"
#include <set>

namespace biol
{
	//
	typedef util::EnumPointer<AminoAcid, AminoAcidTypes> AminoAcidType;


	class AminoAcidTypes:
		public util::Enumerate<AminoAcid, AminoAcidTypes>
	{

	public:

		//

		//! declare all natural amino acid types, ordered according to one letter code
		AminoAcidType ALA;
		AminoAcidType CYS;
		AminoAcidType ASP;
		AminoAcidType GLU;
		AminoAcidType PHE;
		AminoAcidType GLY;
		AminoAcidType HIS;
		AminoAcidType ILE;
		AminoAcidType LYS;
		AminoAcidType LEU;
		AminoAcidType MET;
		AminoAcidType ASN;
		AminoAcidType PRO;
		AminoAcidType GLN;
		AminoAcidType ARG;
		AminoAcidType SER;
		AminoAcidType THR;
		AminoAcidType VAL;
		AminoAcidType TRP;
		AminoAcidType TYR;

		/**
		 * @brief Get the AminoAcidType associated with the given three letter code
		 * @param p_tlc given three letter code
		 * @return
		 */
		const AminoAcidType &TypeFromThreeLetterCode(const std::string &p_tlc) const;

		/**
		 * @brief Get the AminoAcidType associated with the given one letter code
		 * @param p_olc given one letter code
		 * @return
		 */
		const AminoAcidType &TypeFromOneLetterCode(const std::string &p_olc) const;


		/**
		 * @brief Get the set of natural AminoAcidTypes
		 * @return the set of natural AminoAcidTypes
		 */
		const std::set<AminoAcidType> &GetNaturalAminoAcidTypes() const;
	}; // end of class AminoAcidTypes
} // end of namespace biol


#endif //PDOCK_AMINO_ACID_TYPE_H
