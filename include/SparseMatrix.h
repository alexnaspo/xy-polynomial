#include <string>
#include "CircularLinkedList.h"

class SparseMatrix{
	public:
		SparseMatrix(int totalRows, int totalColumns);

		// insert node into rowList and column list
		// in the appropriate spot
		void insertInMatrix(Node* node);

		void printMatrix();
		

	private:
		int rowCount;
		int columnCount;

		CircularLinkedList* rowArray[4];
		CircularLinkedList* columnArray[4]; 

	
};