#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include "../chem/protlab_atom.h"

class TestAtom:
    public CppUnit::TestFixture
{
    private:

        //
        chem::Atom *m_test_atom_a;

        //
        chem::Atom *m_test_atom_b;
        
    protected:

        /**
         *
         */
        void test_get_atom_type();

    public:

        /**
         *
         */
        void setUp();

        /**
         *
         */
        void tearDown();
};

/**
 *
 */
void TestAtom::setUp()
{
    m_test_atom_a = new chem::Atom("H", "H", 1.0, 1.0, math::Vector3D());
    m_test_atom_b = new chem::Atom("O", "O", 16.0, -2.0, math::Vector3D());
}

/**
 *
 */
void TestAtom::tearDown()
{
    delete m_test_atom_a;
    delete m_test_atom_b;
}

/**
 *
 */
void TestAtom::test_get_atom_type()
{
    CPPUNIT_ASSERT(m_test_atom_a->get_atomic_weight() == 1.0);
    CPPUNIT_ASSERT(m_test_atom_b->get_atomic_weight() == 16.0);
}
