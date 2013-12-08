#include <iostream>
#include <string>
#include "XyPolynomial.h"

using namespace std;

int main()
{
	XyPolynomial::runTestCases();
	std::cout << "Automatic tests complete; Start input:\n" << endl;
	XyPolynomial* p = new XyPolynomial();
	std::cout << "Start input for Polynomial P:\n" << endl;
	p->input();
	p->output();
	std::cout << "output for User input:  ";
	p->outputForTests();

	XyPolynomial* q = new XyPolynomial();
	std::cout << "Start input for Polynomial Q:\n" << endl;
	q->input();
	q->output();
	std::cout << "output for User input:  ";
	q->outputForTests();	
	
	XyPolynomial* r = new XyPolynomial();
	std::cout << "Start input for Polynomial R:\n" << endl;
	r->input();
	r->output();
	std::cout << "output for User input:  ";
	r->outputForTests();

	XyPolynomial* s = new XyPolynomial();
	std::cout << "Start input for Polynomial P:\n" << endl;
	s->input();
	s->output();
	std::cout << "output for User input:  ";
	s->outputForTests();


	return 0;
}