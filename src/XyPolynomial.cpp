#include "XyPolynomial.h"
#include <string>
#include <iostream>

XyPolynomial::XyPolynomial(){
	m = 0;
	n = 0;
}

void XyPolynomial::input(){
	Node* nodes[50];
	int isUserDoneWithInput = 0;
	int j = 0;
	while(!isUserDoneWithInput){
		std::string triplet;
		std::cout << "Please enter triplet in the form (c,i,j); Enter -1 to stop entering triplets:  ";
		std::cin >> triplet;
		if(triplet == "-1"){
			isUserDoneWithInput = 1;
		} else {			
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
	}
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

Node* convertTripletToNode(const std::string& input){
	// std::string delimiter = ",";

	// size_t pos = 0;
	// std::string token;
	// while ((pos = triplet.find(delimiter)) != std::string::npos) {
	//     token = triplet.substr(0, pos);
	//     std::cout << token << std::endl;
	//     triplet.erase(0, pos + delimiter.length());
	// }
	// std::cout << triplet << std::endl;	
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









