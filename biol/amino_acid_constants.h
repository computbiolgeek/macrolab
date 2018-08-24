//
// Created by bian on 7/25/18.
//

#ifndef MACROLAB_AMINO_ACID_CONSTANTS_H
#define MACROLAB_AMINO_ACID_CONSTANTS_H

#include <string>
#include <map>

namespace biol
{
    namespace constants
    {
        enum AminoAcidTypes
        {
            e_ALA,
            e_ARG,
            e_ASN,
            e_ASP,
            e_CYS,
            e_GLN,
            e_GLU,
            e_GLY,
            e_HIS,
            e_ILE,
            e_LEU,
            e_LYS,
            e_MET,
            e_PHE,
            e_PRO,
            e_SER,
            e_THR,
            e_TRP,
            e_TYR,
            e_VAL,
            i_number_of_amino_acid_types,
        };

        const std::string AMINO_ACID_NAMES[i_number_of_amino_acid_types] = {
            "ALANINE",
            "ARGININE",
            "ASPARAGINE",
            "ASPARTIC ACID",
            "CYSTEINE",
            "GLUTAMINE",
            "GLUTAMIC ACID",
            "GLYCINE",
            "HISTIDINE",
            "ISOLEUCINE",
            "LEUCINE",
            "LYSINE",
            "METHIONINE",
            "PHENYLALANINE",
            "PROLINE",
            "SERINE",
            "THREONINE",
            "TRYPTOPHAN",
            "TYROSINE",
            "VALINE"
        };


        const std::string AMINO_ACID_THREE_LETTER_CODES[i_number_of_amino_acid_types] = {
            "ALA",
            "ARG",
            "ASN",
            "ASP",
            "CYS",
            "GLN",
            "GLU",
            "GLY",
            "HIS",
            "ILE",
            "LEU",
            "LYS",
            "MET",
            "PHE",
            "PRO",
            "SER",
            "THR",
            "TRP",
            "TYR",
            "VAL"
        };

        const std::map<std::string, AminoAcidTypes> THREE_LETTER_CODES_TO_TYPES = {
            {"ALA", e_ALA},
            {"ARG", e_ARG},
            {"ASN", e_ASN},
            {"ASP", e_ASP},
            {"CYS", e_CYS},
            {"GLN", e_GLN},
            {"GLU", e_GLU},
            {"GLY", e_GLY},
            {"HIS", e_HIS},
            {"ILE", e_ILE},
            {"LEU", e_LEU},
            {"LYS", e_LYS},
            {"MET", e_MET},
            {"PHE", e_PHE},
            {"PRO", e_PRO},
            {"SER", e_SER},
            {"THR", e_THR},
            {"TRP", e_TRP},
            {"TYR", e_TYR},
            {"VAL", e_VAL}
        };


        const std::map<unsigned char, AminoAcidTypes> ONE_LETTER_CODE_TO_TYPES = {
            {'A', e_ALA},
            {'R', e_ARG},
            {'N', e_ASN},
            {'D', e_ASP},
            {'C', e_CYS},
            {'Q', e_GLN},
            {'E', e_GLU},
            {'G', e_GLY},
            {'H', e_HIS},
            {'I', e_ILE},
            {'L', e_LEU},
            {'K', e_LYS},
            {'M', e_MET},
            {'F', e_PHE},
            {'P', e_PRO},
            {'S', e_SER},
            {'T', e_THR},
            {'W', e_TRP},
            {'W', e_TYR},
            {'V', e_VAL}
        };
    } // end of namespace constants
} // end of namespace biol


#endif //MACROLAB_AMINO_ACID_CONSTANTS_H
