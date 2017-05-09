
#include "stdafx.h"
#include "Tree.h"
#include <Defs.h>

int main()
{

	string Tag = "<body>";
	string TagC = "<AAAAAAAAAAA>";
	string Id = "root";
	string ChTag = "<child>";
	string ChTagC = "<CHILDDDDD>";
	string ChId = "root.child";
	Tree* myTree = new Tree();
	myTree->add_node_Tr(nullptr, &Tag, &TagC);
	auto rootNode = myTree->get_node_by_id_Tr(&Id);
	myTree->add_node_Tr(rootNode, &ChTag, &ChTagC);
	myTree->print_tree_Tr();
	return 0;
}