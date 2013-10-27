#include <node.h>
#include <math.h>
#include <string>
#include <iostream>
#include <sstream>


// struct Node {
//     Node* rowLink;
// 	Node* colLink;
    
//     int coefficient;
//     int row;
//     int column;
//     Node(int coef, int r, int col){
//     	row = r;
//     	column = col;
//     	coefficient = coef;    	
//     }

//     std::string display(){
//         std::string result;
//         std::stringstream sstm;

//         std::string x = "x";
//         std::string y = "y";
        
//         sstm << coefficient;
//         if(row > 0){
//             sstm << x << row;    
//         }

//         if(column > 0){
//             sstm << y << column;    
//         }
        
//         result = sstm.str();

//         return result;  
//     }

//     int evaluate(int x, int y){
// 		int xVal = pow(x,row);
// 		int yVal = pow(y, column);

// 		return (coefficient * xVal * yVal);
// 	}
// };

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