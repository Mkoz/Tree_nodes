// NodeHandler.h: Interface for NodeHandler class
#pragma once
#include "stdafx.h"
#include <Node.h>

class Tree
{
public:
	Tree();
	~Tree();
	bool add_node_Tr(Node* aRoot, string *aTag, string *aTagC);
	bool remove_node_Tr(Node* aNode);

	Node* get_node_by_id_Tr(string* anId);
	inline vector<vector<Node*>>* get_level_container_Tr() { return &level_container_Tr; };
	inline Node* get_root_Tr() { return *(get_level_container_Tr()->begin()->begin()); };

	void print_tree_Tr();
	void print_node_Tr();

	string create_id_Tr(Node* aRoot, string aTag);

private:
	//vector<Node*> node_list_NH;
	vector<vector<Node *>> level_container_Tr;
	void remove_symbol(string * aTag, string aSymbol);
/*
	level_container_NH(lvl_0, level_1, level_2, ..)
	lvl 0	N
			| \
	lvl 1	N  N
			| \  \
	lvl 2	N  N  N
*/

};
