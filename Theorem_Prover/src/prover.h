#ifndef PROVER_H
#define PROVER_H
#include <iostream>
#include "axiom.h"

class prover {

	bool proved;
	axiom set_up_axiom;
	parser my_parser;
	formula * theorem;
public:
	prover(string Formula);
	~prover();
	void next_step();
	void use_MP(int Li , int Lj);
	void apply_axiom();
};

#endif