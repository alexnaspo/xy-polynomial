#include <string>
#include "CircularLinkedList.h"

class SparseMatrix{
	public:
		SparseMatrix(int totalRows, int totalColumns);

		// insert node into rowList and column list
		// in the appropriate spot
		void insertInMatrix(Node* node);

		void printMatrix();
		void printFormatedMatrix();
		void evaluateMatrix(int x, int y);
		

	private:
		int rowCount;
		int columnCount;

		CircularLinkedList* rowArray[50];
		CircularLinkedList* columnArray[50]; 

	
};