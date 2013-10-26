#include <iostream>
#include <string>
//#include "Node.h"
#include "CircularLinkedList.h"

using namespace std;

int main()
{

	Node* node = new Node;
	node->column = 5;
	node->row = 1;
	node->coefficient = 10;
	node->colLink = NULL;
	node->rowLink = NULL;

	Node* node2 = new Node;
	node2->column = 10;
	node2->row = 3;
	node2->coefficient = 15;
	node2->colLink = NULL;
	node2->rowLink = NULL;

	Node* node3 = new Node;
	node3->column = 15;
	node3->row = 2;
	node3->coefficient = 15;
	node3->colLink = NULL;
	node3->rowLink = NULL;

	Node* node4 = new Node;
	node4->column = 24;
	node4->row = 5;
	node4->coefficient = 15;
	node4->colLink = NULL;
	node4->rowLink = NULL;

	CircularLinkedList list(-1, 0);
	CircularLinkedList rowList(0, -1);
	
	list.insertInColumn(node3);
	list.insertInColumn(node);
	list.insertInColumn(node2);
	list.insertInColumn(node4);

	rowList.insertInRow(node3);
	rowList.insertInRow(node);
	rowList.insertInRow(node2);
	rowList.insertInRow(node4);
	
	list.printList();
	rowList.printRowList();
	
	
	return 0;
}