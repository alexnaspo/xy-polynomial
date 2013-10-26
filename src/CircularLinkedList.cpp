#include "CircularLinkedList.h"
#include <string>
#include <iostream>

CircularLinkedList::CircularLinkedList(int headRow, int headColumn){
	//init head
	// Node node(NULL, headRow, headColumn);

	// this->setHeadPtr(&node);

	// head->toString();

	Node* headNode = new Node;
	headNode->column = headColumn;
	headNode->row = headRow;
	headNode->coefficient = NULL;
	headNode->colLink = headNode;
	headNode->rowLink = NULL;

	head = headNode;


}

void CircularLinkedList::insertInColumn(Node* node){
	node->colLink = head;	
	Node* cp = head;
	while(cp->colLink->row != -1){
		cp = cp->colLink;
		//std::cout << cp->column << std::endl;
	}
	cp->colLink = node;
}

void CircularLinkedList::printList(void){
	std::cout << "=========" << std::endl;
	Node* cp = head;
	while(cp->colLink->row != -1){		
		//std::cout << cp->coefficient << std::endl;
		cp = cp->colLink;
		std::cout << cp->coefficient << std::endl;
	}
	std::cout << "=========" << std::endl;
}

void CircularLinkedList::setHeadPtr(Node* node) {
	head = node;
}

Node* CircularLinkedList::getHeadPtr() const { 
	return head; 
}

