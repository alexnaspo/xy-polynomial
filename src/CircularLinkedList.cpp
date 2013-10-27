#include "CircularLinkedList.h"
#include <string>
#include <iostream>

CircularLinkedList::CircularLinkedList(int headRow, int headColumn){
	Node* headNode = new Node(NULL, headRow, headColumn);

	if(headRow == -1){
		// build column
		headNode->colLink = headNode;
		headNode->rowLink = NULL;	
	} else if(headColumn == -1) {
		// build row
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
		final = 0;
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

std::string CircularLinkedList::printList(void){
	std::string result;
    std::stringstream sstm;

    Node* cp = head;
	int rowValue = head->row;
	
	if(rowValue == -1){          
		while(cp->colLink->row != -1){	
			cp = cp->colLink;
            if(cp->coefficient > 0){
                sstm << "+ ";    
            }
			sstm << cp->display() << " ";
		}
	} else {
		while(cp->rowLink->column != -1){							
			cp = cp->rowLink;		 	
            if(cp->coefficient > 0){
                sstm << "+ ";
            }
			sstm << cp->display() << " ";
		}
	}
    return sstm.str();	
}

int CircularLinkedList::evaluateList(int x, int y){
    int total = 0;
    Node* cp = head;
    while(cp->rowLink->column != -1){                           
        cp = cp->rowLink;           
        total += cp->evaluate(x, y);
    }          
    return total;
}

void CircularLinkedList::setHeadPtr(Node* node) {
	head = node;
}

Node* CircularLinkedList::getHeadPtr() const { 
	return head; 
}

