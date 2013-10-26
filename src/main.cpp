#include <iostream>
#include <string>
//#include "Node.h"
#include "CircularLinkedList.h"

using namespace std;

int main()
{
	// Node node(1,2,1);
	// Node node2(2,2,2);
	// Node node3(3,2,3);

	Node* node = new Node;
	node->column = 1;
	node->row = 2;
	node->coefficient = 10;
	node->colLink = NULL;
	node->rowLink = NULL;

	Node* node2 = new Node;
	node2->column = 2;
	node2->row = 2;
	node2->coefficient = 15;
	node2->colLink = NULL;
	node2->rowLink = NULL;

	CircularLinkedList list(-1, 500);
	
	list.insertInColumn(node);
	list.printList();
	list.insertInColumn(node2);
	list.printList();
	//list.insertInColumn(&node2);
	// list.insertInColumn(&node3);
	// list.printList(list.getHeadPtr());
	
	
	return 0;
}