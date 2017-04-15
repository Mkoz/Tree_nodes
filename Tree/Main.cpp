// Tree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Node.h"

int main()
{
    //1
	PRINT << endl;


	string tmpTag = "<root>";
	string tmpTagC = "for root";
	string tmpId = "root";
	Node* tmpNode = new Node(NULL, &tmpTag, &tmpTagC, &tmpId);
	for (int i = 0; i < 3; i++)
	{
		string chTag = "<child" + to_string(i) + ">";
		string chTagC = "for child<" + to_string(i) + ">";
		string chId = "root.child" + to_string(i);
		//PRINT << "chTag: " << chTag << endl;
		tmpNode->addChild(new Node(tmpNode, &chTag, &chTagC, &chId));
	}
	tmpNode->print_child();
	system("pause");
	return 0;
}

