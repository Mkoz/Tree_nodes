// NodeHandler.h: Interface for NodeHandler class
#pragma once
#include "stdafx.h"
#include <Node.h>

class Tree
{
public:
	Tree();
	~Tree();
	bool add_node_Tr(Node* aRoot, string *aTag, string *aTagC, string *anId);
	bool remove_node_Tr();

	Node* get_node_by_id_Tr(string* anId);
	vector<vector<Node>*>* get_level_container_Tr();

	void print_tree_Tr();
	void print_node_Tr();

private:
	//vector<Node*> node_list_NH;
	vector<vector<Node>> level_container_Tr;
/*
	level_container_NH(lvl_0, level_1, level_2, ..)
	lvl 0	N
			| \
	lvl 1	N  N
			| \  \
	lvl 2	N  N  N
*/

};
