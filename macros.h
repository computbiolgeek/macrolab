//
// Created by Bian on 1/25/2017.
//

#include <iostream>

#ifndef ASSERT
#define ASSERT(condition, message) do \
{ \
    if (!(condition)) \
    { \
        std::cerr << "Assertion `" #condition "` failed in " << __FILE__ << " line " \
            << __LINE__ << ": " << message << std::endl; \
        std::terminate(); \
    } \
} while (false)
#endif