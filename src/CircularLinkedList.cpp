#include "CircularLinkedList.h"
#include <string>
#include <iostream>

CircularLinkedList::CircularLinkedList(int headRow, int headColumn){
	Node* headNode = new Node;
	headNode->column = headColumn;
	headNode->row = headRow;
	headNode->coefficient = NULL;

	if(headRow == -1){
		headNode->colLink = headNode;
		headNode->rowLink = NULL;	
	} else {
		headNode->colLink = NULL;
		headNode->rowLink = headNode;	
	}
	head = headNode;
}

void CircularLinkedList::insertInColumn(Node* node){
	int colValue = node->column;
	node->colLink = head;	
	Node* cp = head;
	Node* prev;
	int final = 1;
	while(cp->colLink->row != -1){
		final =0;
		prev = cp;
		cp = cp->colLink;
		if(colValue > cp->column){
			prev->colLink = node;
			node->colLink = cp;
			return;
		} else {
			final = 1;
		}
	}
	if(final){
		cp->colLink = node;	
	}
}

void CircularLinkedList::insertInRow(Node* node){
	int rowValue = node->row;
	node->rowLink = head;	
	Node* cp = head;
	Node* prev;
	int final = 1;
	while(cp->rowLink->column != -1){
		final =0;
		prev = cp;
		cp = cp->rowLink;
		if(rowValue > cp->row){
			prev->rowLink = node;
			node->rowLink = cp;
			return;
		} else {
			final = 1;
		}
	}
	if(final){
		cp->rowLink = node;	
	}
}

void CircularLinkedList::printList(void){
	std::cout << "====column=====" << std::endl;
	Node* cp = head;
	while(cp->colLink->row != -1){				
		cp = cp->colLink;
		std::cout << cp->column << std::endl;
	}
	std::cout << "====column=====" << std::endl;
}

void CircularLinkedList::printRowList(void){
	std::cout << "====row=====" << std::endl;
	Node* cp = head;
	while(cp->rowLink->column != -1){				
		cp = cp->rowLink;
		std::cout << cp->row << std::endl;
	}
	std::cout << "=====row====" << std::endl;
}

void CircularLinkedList::setHeadPtr(Node* node) {
	head = node;
}

Node* CircularLinkedList::getHeadPtr() const { 
	return head; 
}

