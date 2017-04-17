#pragma once
#include "../stdafx.h"
#include "CppUnitTest.h"
#include "../../Tree/Node.h"
#include <iostream>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//Create section
Node* CREATE_ROOT();
Node* CREATE_CHILDS(unsigned int aNumberOfChalds, Node* aRoot);

//Check section


//Print section

template <typename... T, typename ARG>
void PRINT_TO_FILE(ARG agr, const T&... tail)
{
	ofstream out("D:\\C++\Tree\test.log");
	if (!out)
	{
		Assert::Fail();
	}

	out << 10 << " " << 123.23 << endl;
	out << "This is a short text file" << endl;
	out.close();
};

#define REDIRECT_COUT std::ostringstream out; std::streambuf* orig_buf(std::cout.rdbuf(out.rdbuf()));

