// Main.cpp: main application file
// It is not used in case compilation as shared lib

#include "stdafx.h"
#include "Node.h"

int main()
{
    //1
	PRINT << endl;


	string tmpTag = "<root>";
	string tmpTagC = "for root";
	string tmpId = "root";
	Node* tmpNode = new Node(NULL, &tmpTag, &tmpTagC, &tmpId, 0);
	for (int i = 0; i < 3; i++)
	{
		string chTag = "<child" + to_string(i) + ">";
		string chTagC = "for child<" + to_string(i) + ">";
		string chId = "root.child" + to_string(i);
		//PRINT << "chTag: " << chTag << endl;
		tmpNode->add_child(new Node(tmpNode, &chTag, &chTagC, &chId, 0));
	}
	//tmpNode->print_child();
	//tmpNode->print_node();
	system("pause");
	return 0;
}

