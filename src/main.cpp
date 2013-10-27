#include <iostream>
#include <string>
//#include "Node.h"
#include "SparseMatrix.h"

using namespace std;

int main()
{
	Node* node = new Node(10,1,1);
	node->colLink = NULL;
	node->rowLink = NULL;

	Node* node2 = new Node(15,2,2);
	node2->colLink = NULL;
	node2->rowLink = NULL;

	Node* node3 = new Node(20,3,3);
	node3->colLink = NULL;
	node3->rowLink = NULL;

	Node* node4 = new Node(25, 0, 4);
	node4->colLink = NULL;
	node4->rowLink = NULL;

	Node* node5 = new Node(-30, 1, 0);
	node5->colLink = NULL;
	node5->rowLink = NULL;

	SparseMatrix matrix(5,5);
	matrix.insertInMatrix(node);
	matrix.insertInMatrix(node2);
	matrix.insertInMatrix(node3);
	matrix.insertInMatrix(node4);
	matrix.insertInMatrix(node5);

	matrix.printFormatedMatrix();

	matrix.evaluateMatrix(4,5);
	
	return 0;
}