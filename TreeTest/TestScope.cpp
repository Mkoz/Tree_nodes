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

	TEST_MODULE_CLEANUP(ModuleCleanUp)
	{
		Logger::WriteMessage("In Module Cleanup\n");
		GET_COUT
		PRINT_TO_FILE(COUT);
	}
	TEST_CLASS(NodeTest)
	{
	public:

		TEST_METHOD(CheckNodeCreation)
		{
			TEST_PRINT << "============ Start =================" << endl;
			Node* testNode = CREATE_ROOT();
			CHECK_ROOT(testNode);
			testNode->print_node();
			TEST_PRINT << "============ END =================" << endl;
		}

		TEST_METHOD(CheckCompletnesOfCreatedNodes)
		{
			TEST_PRINT << "============ Start =================" << endl;
			Node* testNode = CREATE_ROOT();
			CHECK_ROOT(testNode);
			testNode->print_node();
			CREATE_CHILDS(8, testNode);
			testNode->print_node();
			CHECK_CHILDS(testNode);

			TEST_PRINT << "============ END =================" << endl;
		}

	};
}