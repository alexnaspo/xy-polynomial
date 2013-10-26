#include <math.h>
#include <string>


struct Node {
    Node* colLink;
    Node* rowLink;
    int coefficient, row, column;
    int evaluate(int x, int y){
		int xVal = pow(x,row);
		int yVal = pow(y, column);

		return (coefficient * xVal * yVal);
	}
};

class CircularLinkedList{
	public:
		CircularLinkedList(int row, int column);
		// bool isLast();
		// bool isEmpty();
		// this will insert the node in the accurate spot
		// type will determine weather or not to use
		// the row value or the column value to determine position
		void insertInColumn(Node* node);
		// void insertInColumn(Node* node);
		// void delete(Node* node);

  		void setHeadPtr(Node* node);

  		Node* getHeadPtr() const;

		void printList();

	private:
		Node* head;
	
};