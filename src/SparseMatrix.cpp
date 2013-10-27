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
	int rowIndex = node->row - 1;
	int columnIndex = node->column - 1;
	columnArray[columnIndex]->insertInColumn(node);	
	rowArray[rowIndex]->insertInRow(node);
}

void SparseMatrix::printMatrix(void){
	std::cout << "column" << std::endl;          
	for(int i = 0; i < columnCount; i++){		
		columnArray[i]->printList();	
	};
	
	std::cout << "row" << std::endl;  
	for(int j = 0; j < rowCount; j++){
		rowArray[j]->printList();
	};
}



