#include <node.h>
#include <math.h>
#include <string>
#include <iostream>
#include <sstream>

class CircularLinkedList{
	public:
		CircularLinkedList(int row, int column);
		// bool isLast();
		// bool isEmpty();
		// this will insert the node in the accurate spot
		// type will determine weather or not to use
		// the row value or the column value to determine position
		void insertInColumn(Node* node);
		void insertInRow(Node* node);
		// void delete(Node* node);
  		void setHeadPtr(Node* node);
  		Node* getHeadPtr() const;
		std::string printList();
        int evaluateList(int x, int y);

	private:
		Node* head;
	
};