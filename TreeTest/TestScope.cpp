#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Tree/Node.h"
#include "Stubs/Node_stubs.h"

//#pragma comment(lib, "../Tree/Debug/*")

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeTest
{

	TEST_CLASS(NodeTest)
	{
	public:

		TEST_METHOD(CheckCompletnesOfCreatedNodes)
		{

			DELETE_LOG_FILE
			REDIRECT_COUT
			Node* testNode = CREATE_ROOT();
			testNode->print_node();
			CREATE_CHILDS(8, testNode);
			testNode->print_node();
			GET_COUT
			PRINT_TO_FILE(COUT);
			Assert::AreEqual(1,1);
		}
	};
}