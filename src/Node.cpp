#include "Node.h"
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

Node::Node(){}

Node::Node(int coef, int r, int col){
	setColLink(NULL);
	setRowLink(NULL);
	setCoefficient(coef);
	setRow(r);
	setColumn(col);
}

void Node::setCoefficient(int c){
	coefficient = c;
}

void Node::setRow(int r){
	row = r;
}

void Node::setColumn(int c){
	column = c;
}

void Node::setColLink(Node* colPtr){
	colLink = colPtr;
}

void Node::setRowLink(Node* rowPtr){
	rowLink = rowPtr;
}

int Node::getRow() const {
	return row;
}

int Node::getColumn() const {
	return column;
}

int Node::getCoefficient() const {
	return coefficient;
}

Node* Node::getColLink() const {
	return colLink;
}

Node* Node::getRowLink() const {
	return rowLink;
}

int Node::evaluate(int x, int y){
	int xVal = pow(x,row);
	int yVal = pow(y, column);

	int final = (coefficient * xVal * yVal);
	return final;
}

std::string Node::display(){
	std::string result;
	std::stringstream sstm;

	std::string x = "x";
	std::string y = "y";
	     
    sstm << coefficient;
    if(row > 0){
        sstm << x << row;    
    }

    if(column > 0){
        sstm << y << column;    
    }
    
    result = sstm.str();

	return result;	
}

void Node::toString(){
	std::cout << getColumn() << std::endl;
	std::cout << getRow() << std::endl;	
	std::cout << getCoefficient() << std::endl;	
	std::cout << getRowLink() << std::endl;	
	std::cout << getColLink() << std::endl;
}
