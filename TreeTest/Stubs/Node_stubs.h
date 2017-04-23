#pragma once
#include "../stdafx.h"
#include "CppUnitTest.h"
#include "../../Tree/Node.h"
#include <iostream>
#include <fstream>

static char* logFile = "D:\\C++\\Tree\\test.log";
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
static string chTag;
static string chTagC;
static string chId;
static string rootTag = "<root>";
static string rootTagC = "for root";
static string rootId = "root";


//Create section
Node* CREATE_ROOT();
void CREATE_CHILDS(unsigned int aNumberOfChalds, Node* aRoot);
void construct_child(unsigned int * aCaunter);

//Check section


//Print section
#define TEST_PRINT cout << __FILE__ << ":" << __LINE__ << "->[" << __FUNCTION__ << "]  "
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
#define GET_COUT std::cout.rdbuf(orig_buf);
#define COUT out.str()

// Check section
void CHECK_ROOT(Node* aNode);
void CHECK_CHILDS(Node* aNode);

