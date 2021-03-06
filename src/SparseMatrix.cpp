#include "SparseMatrix.h"
#include <string>
#include <iostream>

SparseMatrix::SparseMatrix(int totalRows, int totalColumns){
	rowCount = totalRows;
	columnCount = totalColumns;
	this->rowArray = new CircularLinkedList*[rowCount + 1];
	this->columnArray = new CircularLinkedList*[columnCount + 1];

	for(int i = 0; i <= rowCount; i++){
		CircularLinkedList* list = new CircularLinkedList(i, -1);
		this->rowArray[i] = list;
	};

	for(int j = 0; j <= columnCount; j++){
		CircularLinkedList* list = new CircularLinkedList(-1, j);
		this->columnArray[j] = list;	
	};

}

void SparseMatrix::insertInMatrix(Node* node){	
	if(node->getCoefficient() != 0){
		Node* newNode = new Node(node->getCoefficient(), node->getRow(), node->getColumn());
		int rowIndex = newNode->getRow();
		int columnIndex = newNode->getColumn();
		this->rowArray[rowIndex]->insertInRow(newNode);	
		this->columnArray[columnIndex]->insertInColumn(newNode);
	}
}

void SparseMatrix::addMatrix(SparseMatrix* matrix){
	for(int i = matrix->rowCount; i >= 0; i--){	
		CircularLinkedList* list = matrix->rowArray[i];
		Node* cp = list->getHeadPtr();
		while(cp->getRowLink()->getColumn() != -1){
			cp = cp->getRowLink();			
			this->addToMatrix(cp);		
		}
	}
}

void SparseMatrix::subtractMatrix(SparseMatrix* matrix){
	for(int i = matrix->rowCount; i >= 0; i--){	
		CircularLinkedList* list = matrix->rowArray[i];
		Node* cp = list->getHeadPtr();
		while(cp->getRowLink()->getColumn() != -1){
			cp = cp->getRowLink();			
			this->subtractFromMatrix(cp);		
		}
	}
}

SparseMatrix* SparseMatrix::multiplyMatrix(SparseMatrix* matrix){
	SparseMatrix* resultMatrix = new SparseMatrix(rowCount, columnCount);
	for(int i = matrix->rowCount; i >= 0; i--){	
		Node* cp = matrix->rowArray[i]->getHeadPtr();
		while(cp->getRowLink()->getColumn() != -1){
			cp = cp->getRowLink();
			SparseMatrix* multMatrix = this->multiplyNode(cp);
			resultMatrix->addMatrix(multMatrix);
		}
	}
	return resultMatrix;
}

SparseMatrix* SparseMatrix::multiplyNode(Node* node){
	SparseMatrix* resultMatrix = new SparseMatrix(rowCount, columnCount);
	for(int i = this->rowCount; i >= 0; i--){	
		Node* cp = this->rowArray[i]->getHeadPtr();
		while(cp->getRowLink()->getColumn() != -1){
			cp = cp->getRowLink();
			Node* newNode = cp->multiplyNode(node);
			if(newNode != NULL){
				resultMatrix->addToMatrix(newNode);		
			}
			
		}
	}
	return resultMatrix;
}

void SparseMatrix::addToMatrix(Node* node){	
	Node* nodeFound = this->findNodeWithLikeTerms(node);
	if(nodeFound){
		//need to replace node
		this->rowArray[nodeFound->getRow()]->removeNode(nodeFound);
		insertInMatrix(nodeFound->addNode(node));
	} else {
		insertInMatrix(node);
	}
}

void SparseMatrix::subtractFromMatrix(Node* node){
	Node* nodeFound = this->findNodeWithLikeTerms(node);
	if(nodeFound){
		//need to replace node
		this->rowArray[nodeFound->getRow()]->removeNode(nodeFound);
		insertInMatrix(nodeFound->subtractNode(node));
	} else {
		double coef = (node->getCoefficient() * -1);
		Node* newNode = new Node(coef, node->getRow(), node->getColumn());
	 	insertInMatrix(newNode);
	}
}

Node* SparseMatrix::findNodeWithLikeTerms(Node* node){
	int row = node->getRow();
	//only search the linked this with the matching row
	Node* nodeFound = rowArray[row]->findNodeWithLikeTerms(node);
	return nodeFound;
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
	for(int i = rowCount; i >= 0; i--){	
		sstm << rowArray[i]->printList();	
	}
	std::cout << sstm.str() << std::endl;
	std::cout << "" << std::endl;
}

void SparseMatrix::evaluateMatrix(double x, double y){
	double total = 0;
	for(int i = rowCount; i >= 0; i--){	
		total += rowArray[i]->evaluateList(x, y);	
	}
	std::cout << total << std::endl;
}

int SparseMatrix::getRowCount(){
	return rowCount;
}
