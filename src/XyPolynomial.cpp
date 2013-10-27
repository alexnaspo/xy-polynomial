#include "XyPolynomial.h"
#include <string>
#include <iostream>

XyPolynomial::XyPolynomial(){
	m = 0;
	n = 0;
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
	matrix = new SparseMatrix(n,m);
	for(int i = 0; i < nodeCount; i++){
		matrix->insertInMatrix(nodes[i]);					
	}
}

void XyPolynomial::output(){
	matrix->printFormatedMatrix();
}

void XyPolynomial::evaluate(int x, int y){
	matrix->evaluateMatrix(x, y);
}

Node** XyPolynomial::convertTripletsToNodes(std::string triplets[], int numTriplets){
	Node** nodes = new Node*[numTriplets];
	int j = 0;
	for(int i = 0; i < numTriplets; i++){
		std::string triplet = triplets[i];
		std::string delimiter = ",";
		size_t pos = 0;
		std::string token;
		triplet.erase(0,1);	
		int i = 0;
		int values[5];
		while ((pos = triplet.find(delimiter)) != std::string::npos) {
		    token = triplet.substr(0, pos);
		    values[i++] = atoi(token.c_str());				
		    triplet.erase(0, pos + delimiter.length());			    
		}
		values[i++] = atoi(triplet.c_str());
		setN(values[1]);
		setM(values[2]);

		nodes[j++] = new Node(values[0], values[1], values[2]);
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









