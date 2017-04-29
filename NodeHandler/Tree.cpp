// NodeHandler.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tree.h"

using namespace std;
Tree::Tree():level_container_Tr(NULL)
{
	PRINT << "size: " << level_container_Tr.size() << endl;
}

bool Tree::add_node_Tr(Node* aRoot,string *aTag, string *aTagC, string *anId)
{
	if ( level_container_Tr.size() == 0 )
	{
		PRINT << "Root case" << endl;
		level_container_Tr.push_back(Node(nullptr, aTag, aTagC, anId));

		//boost::shared_ptr;
		//root_NH = nullptr;
	}
	return false;
}
