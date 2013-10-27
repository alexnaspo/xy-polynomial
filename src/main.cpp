#include <iostream>
#include <string>
#include "XyPolynomial.h"

using namespace std;

int main()
{
	XyPolynomial* polynomial = new XyPolynomial();
	polynomial->input();
	polynomial->output();
	polynomial->evaluate(0,1);
	
	return 0;
}

void runTestCases(){
	std::cout << "face";
}