#include "Node.h"
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

Node::Node(){}

Node::Node(double coef, int r, int col){
	setColLink(NULL);
	setRowLink(NULL);
	setCoefficient(coef);
	setRow(r);
	setColumn(col);
}

void Node::setCoefficient(double c){
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

double Node::getCoefficient() const {
	return coefficient;
}

Node* Node::getColLink() const {
	return colLink;
}

Node* Node::getRowLink() const {
	return rowLink;
}

double Node::evaluate(double x, double y){
	double xVal = pow(x,row);
	double yVal = pow(y, column);

	double final = (coefficient * xVal * yVal);
	return final;
}

std::string Node::display(){
	std::string result;
	std::stringstream sstm;

	std::string x = "x";
	std::string y = "y";
	     
    sstm << coefficient;
    if(row == 1){
    	sstm << x;            
    } else if (row >= 1){
    	sstm << x << row;  
    }

    if(column == 1){
    	sstm << y;            
    } else if (column >= 1){
    	sstm << y << column;
    }
    
    result = sstm.str();

	return result;	
}

Node* Node::createNodeAndAdd(Node* node){	
	return new Node(node->getCoefficient() + getCoefficient(), getRow(), getColumn());
}

void Node::condenseNodes(Node* node){	
	this->setCoefficient(node->getCoefficient() + getCoefficient());
}

Node* Node::addNode(Node* node){	
	int coef = node->getCoefficient() + getCoefficient();
	return new Node(coef, node->getRow(), node->getColumn());
}

Node* Node::subtractNode(Node* node){	
	int coef = getCoefficient() - node->getCoefficient();
	return new Node(coef, node->getRow(), node->getColumn());
}

Node* Node::multiplyNode(Node* node){
	int coef = getCoefficient() * node->getCoefficient();
	int rowValue = getRow() + node->getRow();
	int columnValue = getColumn() + node->getColumn();
	return new Node(coef, rowValue, columnValue);
}

bool Node::hasLikeTerms(Node* node){
	if(node->getRow() == this->getRow() && node->getColumn() == this->getColumn()){
		return true;
	} else {
		return false;
	}
}

void Node::toString(){
	std::cout << getColumn() << std::endl;
	std::cout << getRow() << std::endl;	
	std::cout << getCoefficient() << std::endl;	
	std::cout << getRowLink() << std::endl;	
	std::cout << getColLink() << std::endl;
}

