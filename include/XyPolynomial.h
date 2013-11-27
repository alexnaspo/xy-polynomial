#include <string>
#include "SparseMatrix.h"

class XyPolynomial{
	public:
		XyPolynomial();
		XyPolynomial(int x, int y);
		
		void initialize(Node* nodes[], int nodeCount);

		void input();

		void output();

		void evaluate(int x, int y);

		void setM(int y);

		int getM();

		void setN(int x);

		int getN();
		Node** convertTripletsToNodes(std::string* triplets, int numTriplets);
		void outputForTests();
		static void runTestCases();
		XyPolynomial* add(XyPolynomial* poly);
		XyPolynomial* subtract(XyPolynomial* poly);


		SparseMatrix* matrix;

	private:
		//Node** convertTripletsToNodes(std::string* triplets, int numTriplets);

		
		int m;
		int n;


};