#include "SparseMatrix.h"
#include <string>
#include <iostream>

SparseMatrix::SparseMatrix(int totalRows, int totalColumns){
	rowCount = totalRows;
	columnCount = totalColumns;

	for(int i = 0; i < rowCount; i++){
		CircularLinkedList* list = new CircularLinkedList(i, -1);
		this->rowArray[i] = list;
	};

	for(int j = 0; j < columnCount; j++){
		CircularLinkedList* list = new CircularLinkedList(-1, j);
		this->columnArray[j] = list;	
	};

}

void SparseMatrix::insertInMatrix(Node* node){

}

void SparseMatrix::printMatrix(void){

	for(int i = 0; i < columnCount; i++){		
		columnArray[i]->printList();	
	};

	for(int j = 0; j < rowCount; j++){
		rowArray[j]->printList();
	};
	

	
}



