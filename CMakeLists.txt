cmake_minimum_required(VERSION 3.10)
project(macrolab)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        math/coord3d.h
        math/coord3d.cpp
        math/matrix.h
        math/matrix.cpp
        )

add_executable(macrolab main.cpp biol/biol.h biol/amino_acid_constants.h biol/atom_constants.h)