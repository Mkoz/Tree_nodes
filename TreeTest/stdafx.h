// stdafx.h: Headers list
// Project "Node" should be associated as link for this proj
#pragma once

#include "targetver.h"
#include <iostream>

#include "CppUnitTest.h"

// Redirect cout
static std::ostringstream out;
static std::streambuf* orig_buf(std::cout.rdbuf(out.rdbuf()));

