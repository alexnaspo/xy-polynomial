#include "XyPolynomial.h"
#include <stdlib.h>
#include <string>
#include <iostream>

XyPolynomial::XyPolynomial(){
	m = 0;
	n = 0;
}

XyPolynomial::XyPolynomial(int x, int y){
	n = x;
	m = y;
}

void XyPolynomial::input(){	
	std::string* tripletArray = new std::string[50]; 	
	int isUserDoneWithInput = 0;
	int j = 0;
	while(!isUserDoneWithInput){
		std::string triplet;
		std::cout << "Please enter triplet in the form (c,i,j); Enter -1 to stop entering triplets:  ";
		std::cin >> triplet;
		if(triplet == "-1"){
			isUserDoneWithInput = 1;
		} else {
			tripletArray[j++] = triplet;			
		}
	}
	Node** nodes = convertTripletsToNodes(tripletArray, j);
	initialize(nodes, j);
}

void XyPolynomial::initialize(Node* nodes[], int nodeCount){
	for(int i = 0; i < nodeCount; i++){
		setN(nodes[i]->getRow());
		setM(nodes[i]->getColumn());					
	}
	matrix = new SparseMatrix(n,m);
	for(int i = 0; i < nodeCount; i++){
		matrix->insertInMatrix(nodes[i]);					
	}
}

void XyPolynomial::output(){
	matrix->printFormatedMatrix();
	// matrix->printMatrix();
}

void XyPolynomial::evaluate(int x, int y){
	matrix->evaluateMatrix(x, y);
}

XyPolynomial* XyPolynomial::add(XyPolynomial* poly){
	int maxRows;
	int maxColumns;
	if(poly->m > this->m){
		maxColumns = poly->m;
	} else {
		maxColumns = this->m;
	}

	if(poly->n > this->n){
		maxRows = poly->n;
	} else {
		maxRows = this->n;
	}
	XyPolynomial* result = new XyPolynomial(maxRows,maxColumns);
	result->matrix = new SparseMatrix(maxRows,maxColumns);
	result->matrix->addMatrix(poly->matrix);
	result->matrix->addMatrix(this->matrix);
	return result;
}

XyPolynomial* XyPolynomial::subtract(XyPolynomial* poly){
	int maxRows;
	int maxColumns;
	if(poly->m > this->m){
		maxColumns = poly->m;
	} else {
		maxColumns = this->m;
	}
	
	if(poly->n > this->n){
		maxRows = poly->n;
	} else {
		maxRows = this->n;
	}
	XyPolynomial* result = new XyPolynomial(maxRows,maxColumns);
	result->matrix = new SparseMatrix(maxRows,maxColumns);
	//first add original matrix to new polynomial
	result->matrix->addMatrix(this->matrix);	
	//then subtract input polynomial
	result->matrix->subtractMatrix(poly->matrix);
	return result;
}

Node** XyPolynomial::convertTripletsToNodes(std::string triplets[], int numTriplets){
	Node** nodes = new Node*[numTriplets];
	for(int i = 0; i < numTriplets; i++){
		std::string triplet = triplets[i];
		std::string delimiter = ",";
		size_t pos = 0;
		std::string token;
		triplet.erase(0,1);	
		int k = 0;
		int values[5];
		while ((pos = triplet.find(delimiter)) != std::string::npos) {
		    token = triplet.substr(0, pos);
		    values[k++] = atoi(token.c_str());				
		    triplet.erase(0, pos + delimiter.length());			    
		}
		values[k++] = atoi(triplet.c_str());
		nodes[i] = new Node(values[0], values[1], values[2]);
	}	

	return nodes;
}

void XyPolynomial::setN(int x){
	if(x > n){
		n = x;
	}
}

void XyPolynomial::setM(int y){
	if(y > m){
		m = y;
	}
}

int XyPolynomial::getN(){
	return n;
}

int XyPolynomial::getM(){
	return m;
}

void XyPolynomial::runTestCases(){
	std::cout << "Start Automatic tests:\n" << std::endl;
	// test case P
	XyPolynomial* P = new XyPolynomial();
	std::string* tripletArray = new std::string[50]; 

	//hard code user input
	tripletArray[0] = "(5,4,3)";
	tripletArray[1] = "(-2,3,4)";
	tripletArray[2] = "(1,1,1)";
	tripletArray[3] = "(-6,0,0)";

	Node** nodes = P->convertTripletsToNodes(tripletArray, 4);
	P->initialize(nodes, 4);
	std::cout << "output for P:  ";
	P->outputForTests();

	// test case Q
	XyPolynomial* Q = new XyPolynomial();

	//hard code user input
	tripletArray[0] = "(-8,3,5)";
	tripletArray[1] = "(4,2,2)";
	tripletArray[2] = "(-1,1,0)";
	tripletArray[3] = "(1,0,1)";
	tripletArray[4] = "(1,0,0)";

	nodes = Q->convertTripletsToNodes(tripletArray, 5);
	Q->initialize(nodes, 5);
	std::cout << "output for Q:  ";
	Q->outputForTests();

	// test case R
	XyPolynomial* R = new XyPolynomial();

	//hard code user input
	tripletArray[0] = "(8,3,0)";
	tripletArray[1] = "(6,2,1)";
	tripletArray[2] = "(-4,1,0)";
	tripletArray[3] = "(2,0,0)";

	nodes = R->convertTripletsToNodes(tripletArray, 4);
	R->initialize(nodes, 4);
	std::cout << "output for R:  ";
	R->outputForTests();

	// test case S
	XyPolynomial* S = new XyPolynomial();

	//hard code user input
	tripletArray[0] = "(3,1,1)";
	tripletArray[1] = "(-5,0,5)";
	tripletArray[2] = "(3,0,3)";
	tripletArray[3] = "(-1,0,1)";

	nodes = S->convertTripletsToNodes(tripletArray, 4);
	S->initialize(nodes, 4);
	std::cout << "output for S:  ";
	S->outputForTests();

	XyPolynomial* A = P->add(Q);
	std::cout << "output for A:  ";
	A->outputForTests();

	XyPolynomial* B = P->subtract(Q);
	std::cout << "output for B:  ";
	B->outputForTests();
	
	XyPolynomial* C = R->add(S);
	std::cout << "output for C:  ";
	C->outputForTests();

	XyPolynomial* D = P->subtract(S);
	std::cout << "output for D:  ";
	D->outputForTests();

	XyPolynomial* E = S->subtract(P);
	std::cout << "output for E:  ";
	E->outputForTests();
	
	XyPolynomial* F = Q->add(R);	
	std::cout << "output for F:  ";
	F->outputForTests();
}

void XyPolynomial::outputForTests(){	
	this->output();
	std::cout << "    evaluate(3,8): ";
	this->evaluate(3,8);
	std::cout << "    evaluate(3,0): ";
	this->evaluate(3,0);
	std::cout << "    evaluate(0,2): ";
	this->evaluate(0,2);
	std::cout << "    evaluate(2,2): ";
	this->evaluate(2,2);
	std::cout << "    evaluate(10,6): ";
	this->evaluate(10,6);
	std::cout << "\n" << std::endl;
}









