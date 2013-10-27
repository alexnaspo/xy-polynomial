#include <string>
#include "SparseMatrix.h"

class XyPolynomial{
	public:
		XyPolynomial();
		
		void initialize(Node* nodes[], int nodeCount);

		void input();

		void output();

		void evaluate(int x, int y);

		void setM(int y);

		int getM();

		void setN(int x);

		int getN();


	private:
		Node** convertTripletsToNodes(std::string* triplets, int numTriplets);

		SparseMatrix* matrix;
		int m;
		int n;


};