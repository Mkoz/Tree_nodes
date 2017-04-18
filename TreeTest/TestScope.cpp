#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Tree/Node.h"
#include "Stubs/Node_stubs.h"

//#pragma comment(lib, "../Tree/Debug/*")

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeTest
{

	TEST_MODULE_INITIALIZE(ModuleInitializer)
	{
		Logger::WriteMessage("In Module Initializer\n");
		DELETE_LOG_FILE
	}

	TEST_CLASS(NodeTest)
	{
	public:

		TEST_METHOD(CheckCompletnesOfCreatedNodes)
		{

			Node* testNode = CREATE_ROOT();
			testNode->print_node();
			CREATE_CHILDS(8, testNode);
			testNode->print_node();
			GET_COUT
			PRINT_TO_FILE(COUT);

			Assert::AreEqual(testNode->get_tag().c_str(),"<root>");
			Assert::AreEqual(1,1);
		}
	};
}