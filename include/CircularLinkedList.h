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
        int evaluateList(int x, int y);
        Node** addList(CircularLinkedList* list);

        Node* findNodeWithLikeTerms(Node* node);
        void removeNode(Node* node);

        bool isColListEmpty();
        bool isRowListEmpty();

	private:
		Node* head;
	
};