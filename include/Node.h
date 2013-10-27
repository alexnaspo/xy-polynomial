#include <string>

class Node {
	public:
        Node();
        Node(int coef, int r, int col);
		void setCoefficient(int c);
		void setRow(int r);
		void setColumn(int c);
        void setColLink(Node* node);
        void setRowLink(Node* node);        

		int getCoefficient() const;
        int getRow() const;
		int getColumn() const;
        Node* getColLink() const;
        Node* getRowLink() const;

        std::string display();
        int evaluate(int x, int y);

        void toString();

        Node* colLink;
        Node* rowLink;
        int coefficient, row, column;   
        

    private:

        
        
              
};
