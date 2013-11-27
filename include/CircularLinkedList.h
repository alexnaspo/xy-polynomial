#include <Node.h>
#include <math.h>
#include <string>
#include <iostream>
#include <sstream>

class CircularLinkedList{
	public:
		CircularLinkedList(int row, int column);
		void insertInColumn(Node* node);
		void insertInRow(Node* node);
  		void setHeadPtr(Node* node);
  		Node* getHeadPtr() const;
		std::string printList();
        double evaluateList(double x, double y);

        Node* findNodeWithLikeTerms(Node* node);
        void removeNode(Node* node);

        bool isColListEmpty();
        bool isRowListEmpty();

	private:
		Node* head;
	
};