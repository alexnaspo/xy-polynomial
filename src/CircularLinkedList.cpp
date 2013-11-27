#include "CircularLinkedList.h"
#include <string>
#include <iostream>

CircularLinkedList::CircularLinkedList(int headRow, int headColumn){
	Node* headNode = new Node(NULL, headRow, headColumn);

	if(headRow == -1){
		// build column
		headNode->setColLink(headNode);
		headNode->setRowLink(NULL);
	} else if(headColumn == -1) {
		// build row
		headNode->setColLink(NULL);
        headNode->setRowLink(headNode);
	}

	head = headNode;
}

void CircularLinkedList::insertInColumn(Node* node){
	int colValue = node->getColumn();
	int rowValue = node->getRow();
	node->setColLink(head);	
	
	Node* cp = head;
	Node* prev;
	int final = 1;

	while(cp->getColLink()->getRow() != -1){
		final = 0;
		prev = cp;
		cp = cp->getColLink();
		if (rowValue > cp->getRow()) {
			prev->setColLink(node);
			node->setColLink(cp);
			return;
		} else {
			final = 1;
		}
	}
	if(final){
		cp->setColLink(node);	
	}

}

void CircularLinkedList::insertInRow(Node* node){
	int rowValue = node->getRow();
	int colValue = node->getColumn();
	node->setRowLink(head);	
	Node* cp = head;
	Node* prev;
	int final = 1;
	while(cp->getRowLink()->getColumn() != -1){
		final = 0;
		prev = cp;
		cp = cp->getRowLink();
		if(colValue > cp->getColumn()){
			prev->setRowLink(node);
			node->setRowLink(cp);
			return;
		} else {
			final = 1;
		}
	}
	if(final){
		cp->setRowLink(node);	
	}
}

std::string CircularLinkedList::printList(void){
	std::string result;
    std::stringstream sstm;
    Node* cp = head;
	int rowValue = head->getRow();
	
	if(rowValue == -1){          
		while(cp->getColLink()->getRow() != -1){	
			cp = cp->getColLink();
            if(cp->getCoefficient() > 0){
                sstm << "+ ";    
            }
			sstm << cp->display() << " ";
		}
	} else {
		while(cp->getRowLink()->getColumn() != -1){							
			cp = cp->getRowLink();		 	
            if(cp->getCoefficient() > 0){
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
    while(cp->getRowLink()->getColumn() != -1){                           
        cp = cp->getRowLink();   
        total += cp->evaluate(x, y);
    }          
    return total;
}

void CircularLinkedList::removeNode(Node* node){
	Node* cp = head;
	Node* prev;
	while(cp->getRowLink()->getColumn() != -1){  
		prev = cp; 
		cp = cp->getRowLink();
		if(cp == node){
			prev->setRowLink(cp->getRowLink());
		} 
	}
	while(cp->getColLink()->getRow() != -1){  
		prev = cp; 
		cp = cp->getColLink();
		if(cp == node){
			prev->setColLink(cp->getColLink());
		} 
	}
}

Node* CircularLinkedList::findNodeWithLikeTerms(Node* node){
	Node* cp = head;
	while(cp->getRowLink()->getColumn() != -1){   
		cp = cp->getRowLink();
		if(cp->hasLikeTerms(node)){
			return cp;
		} 
	}
	return NULL;
}

bool CircularLinkedList::isRowListEmpty(){
	Node* cp = head;
	if(cp->getRowLink()->getColumn() == -1){
		return true;
	} else {
		return false;
	}
}

bool CircularLinkedList::isColListEmpty(){
	Node* cp = head;
	if(cp->getColLink()->getRow() == -1){
		return true;
	} else {
		return false;
	}
}

void CircularLinkedList::setHeadPtr(Node* node) {
	head = node;
}

Node* CircularLinkedList::getHeadPtr() const { 
	return head; 
}

