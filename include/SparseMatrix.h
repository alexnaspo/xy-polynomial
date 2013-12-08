#include <string>
#include "CircularLinkedList.h"

class SparseMatrix{
	public:
		SparseMatrix(){};
		SparseMatrix(int totalRows, int totalColumns);

		void insertInMatrix(Node* node);
		void printMatrix();
		void printFormatedMatrix();
		void evaluateMatrix(double x, double y);
		int getRowCount();		
		CircularLinkedList* getRowArray();

		Node* findNodeWithLikeTerms(Node* node);	
		void addToMatrix(Node* node);
		void addMatrix(SparseMatrix* matrix);
		void subtractMatrix(SparseMatrix* matrix);
		void subtractFromMatrix(Node* node);
		SparseMatrix* multiplyMatrix(SparseMatrix* matrix);
		SparseMatrix* multiplyNode(Node* node);

		CircularLinkedList** rowArray;
		CircularLinkedList** columnArray; 	


	private:
		int rowCount;
		int columnCount;
		
};