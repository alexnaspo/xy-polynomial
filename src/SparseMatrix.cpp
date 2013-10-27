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
	int rowIndex = node->getRow();
	int columnIndex = node->getColumn();
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

void SparseMatrix::printFormatedMatrix(void){
	std::string result;
    std::stringstream sstm;

	for(int i = rowCount -1; i >= 0; i--){	
		sstm << rowArray[i]->printList();	
	}

	std::cout << sstm.str() << std::endl;
}

void SparseMatrix::evaluateMatrix(int x, int y){
	int total = 0;
	for(int i = rowCount -1; i >= 0; i--){	
		total += rowArray[i]->evaluateList(x, y);	
	}
	std::cout << total << std::endl;
}

