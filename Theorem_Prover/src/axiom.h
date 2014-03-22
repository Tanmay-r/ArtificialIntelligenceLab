#ifndef AXIOM_H
#define AXIOM_H
#include <iostream>
#include "parser.h"
#include <string>

class axiom {

	parser axiom_parser;
public:
	axiom();
	~axiom();
	formula* axiom_A1(formula * A , formula * B);
	formula* axiom_A2(formula * A , formula * B, formula * C);
	formula* axiom_A3(formula * A);
	formula *axiom_A11(string A, string B);
	formula *axiom_A21(string A, string B ,string C);
	formula *axiom_A31(string A);
};

#endif