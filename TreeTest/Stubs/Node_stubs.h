#pragma once
#include "../stdafx.h"
#include "CppUnitTest.h"
#include "../../Tree/Node.h"
#include <iostream>
#include <fstream>

static char* logFile = "D:\\C++\\Tree\\test.log";
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//Create section
Node* CREATE_ROOT();
Node* CREATE_CHILDS(unsigned int aNumberOfChalds, Node* aRoot);

//Check section


//Print section

template <typename T>
void PRINT_TO_FILE(const T arg)
{
	ofstream out;
	out.open(logFile, ios::app);
	if (!out)
	{
		Assert::Fail();
	}

	out << arg << endl ;

	/*FILE* f = fopen("D:\\C++\\Tree\\test.log", "w");
	fputs("fputs", f);
	fclose(f);*/
};

#define DELETE_LOG_FILE remove(logFile);

// cout redirection for verified object
#define REDIRECT_COUT std::ostringstream out; std::streambuf* orig_buf(std::cout.rdbuf(out.rdbuf()));
#define GET_COUT std::cout.rdbuf(orig_buf);
#define COUT out.str()

