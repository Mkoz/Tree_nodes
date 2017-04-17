#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Tree/Node.h"
#include "Stubs/Node_stubs.h"

//#pragma comment(lib, "../Tree/Debug/*")

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(CheckCompletnesOfCreatedNodes)
		{

			cout << "aaaaaaaaaaa a" << endl;
			Node* testNode = CREATE_ROOT();
			testNode->print_node();
			CREATE_CHILDS(8, testNode);
			PRINT_TO_FILE("aaa", "bbb", "ccc");
			Assert::AreEqual(1,1);
		}
	};
}