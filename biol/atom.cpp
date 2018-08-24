#include "atom.h"
#include "../math/coord3d.h"

namespace biol
{

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
    Atom::Atom
    (
        const constants::AtomTypes &p_atom_type,
        const constants::AminoAcidTypes &p_residue_type,
        double p_atomic_weight,
        const math::Coord3D &p_coords,
        double p_partial_charge,
        double p_bfactor,
        double p_occupancy,
        bool p_altloc
    ) :
        m_atom_type(p_atom_type),
        m_residue_type(p_residue_type),
        m_atomic_weight(p_atomic_weight),
        m_coord(p_coords),
        m_partial_charge(p_partial_charge),
        m_bfactor(p_bfactor),
        m_occupancy(p_occupancy),
        m_altloc(p_altloc)
    {
        // nothing else to do
    }


    /**
     * @brief Get the type of this atom.
     * @return The type of this atom.
     */
    const constants::AtomTypes &Atom::get_atom_type() const
    {
        return m_atom_type;
    }


    /**
     * @brief Set the type of this atom.
     * @param p_atom_type New atom type.
     */
    void Atom::set_atom_type(const constants::AtomTypes &p_atom_type)
    {
        m_atom_type = p_atom_type;
    }


    /**
     * @brief Get the name of this atom.
     * @return The name of this atom.
     */
    const std::string &Atom::get_atom_name() const
    {
        return constants::PDB_ATOM_NAMES[m_atom_type];
    }


    /**
     * @brief Get the type of the residue to which this atom belongs.
     * @return The type of the residue to which this atom belongs.
     */
    const constants::AminoAcidTypes &Atom::get_residue_type() const
    {
        return m_residue_type;
    }


    /**
     * @brief Set the type of the residue to which this atom belongs.
     * @param p_residue_type New residue type.
     */
    void Atom::set_residue_type(const constants::AminoAcidTypes &p_residue_type)
    {
        m_residue_type = p_residue_type;
    }


    /**
     * @brief Get the atomic weight of this atom.
     * @return The atomic weight of this atom.
     */
    double Atom::get_atomic_weight() const
    {
        return m_atomic_weight;
    }


    /**
     * @brief Set the atomic weight of this atom.
     * @param p_atomic_weight New atomic weight.
     */
    void Atom::set_atomic_weight(double p_atomic_weight)
    {
        m_atomic_weight = p_atomic_weight;
    }


    /**
     * @brief Get the Cartesian coordinates of this atom.
     * @return The Cartesian coordinates of this atom.
     */
    const math::Coord3D &Atom::get_coord() const
    {
        return m_coord;
    }


    /**
     * @brief Set the Cartesian coordinates of this atom.
     * @param p_coord New Cartesian coordinates.
     */
    void Atom::set_coord(const math::Coord3D &p_coord)
    {
        m_coord = p_coord;
    }


    /**
     * @brief Get the partial charge of this atom.
     * @return The partial charge of this atom.
     */
    double Atom::get_partial_charge() const
    {
        return m_partial_charge;
    }


    /**
     * @brief Set the partial charge of this atom.
     * @param p_partial_charge New partial charge.
     */
    void Atom::set_partial_charge(double p_partial_charge)
    {
        m_partial_charge = p_partial_charge;
    }


    /**
     * @brief Get the b-factor of this atom.
     * @return The b-factor of this atom.
     */
    double Atom::get_bfactor() const
    {
        return m_bfactor;
    }


    /**
     * @brief Set the b-factor of this atom.
     * @param p_bfactor New b-factor.
     */
    void Atom::set_bfactor(double p_bfactor)
    {
        m_bfactor = p_bfactor;
    }


    /**
     * @brief Get the occupancy value of this atom.
     * @return The occupancy value of this atom.
     */
    double Atom::get_occupancy() const
    {
        return m_occupancy;
    }


    /**
     * @brief Set the occupancy value of this atom.
     * @param p_occupancy New occupancy value.
     */
    void Atom::set_occupancy(double p_occupancy)
    {
        m_occupancy = p_occupancy;
    }


    /**
     * @brief Overload the - operator for calculating the Euclidean distance between two atoms.
     * @param p_rhs The right-hand atom.
     * @return The Euclidean distance between the two atoms.
     */
    double Atom::operator-(const Atom &p_rhs) const
    {
        return (m_coord - p_rhs.m_coord).norm();
    }


    /**
     * @brief Translate this atom along a given vector.
     * @param p_vector_3d A given vector.
     */
    void Atom::translate(const math::Coord3D &p_vector_3d)
    {
        m_coord + p_vector_3d;
    }


    /**
     * @brief Get the status of alternative location.
     * @return The status of alternative location.
     */
    bool Atom::has_altloc() const
    {
        return m_altloc;
    }

} // end of namespace biol
