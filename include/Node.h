#include <string>

class Node {
	public:
        Node();
        Node(double coef, int r, int col);
        void setCoefficient(double c);
        void setRow(int r);
        void setColumn(int c);
        void setColLink(Node* node);
        void setRowLink(Node* node);        

		double getCoefficient() const;
        int getRow() const;
		int getColumn() const;
        Node* getColLink() const;
        Node* getRowLink() const;

        std::string display();
        double evaluate(double x, double y);

        void condenseNodes(Node* node);
        Node* addNode(Node* node);
        Node* subtractNode(Node* node);
        Node* createNodeAndAdd(Node* node);

        Node* multiplyNode(Node* node);

        bool hasLikeTerms(Node* node);

        void toString();                        

    private:
        Node* colLink;
        Node* rowLink;
        double coefficient;
        int row, column;
     
};
