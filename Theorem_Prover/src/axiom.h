#ifndef AXIOM_H
#define AXIOM_H
#include <iostream>
#include "formula.h"
#include <string>

class axiom {

public:
	axiom();
	~axiom();
	formula* axiom_A1(formula * A , formula * B);
	formula* axiom_A2(formula * A , formula * B, formula * C);
	formula* axiom_A3(formula * A);
};

#endif;