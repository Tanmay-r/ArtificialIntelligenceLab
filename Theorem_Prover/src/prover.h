#ifndef PROVER_H
#define PROVER_H
#include <iostream>
#include "axiom.h"

class prover {

	bool proved;
	axiom set_up_axiom;
	parser my_parser;
	formula * theorem;
	formula * current_guess_formula;
public:
	prover(string Formula);
	~prover();
	void next_step();
	void print_component_list();
	void use_MP(int Li , int Lj);
	void apply_axiom();
	void guess_start_hypothesis();
	int* axiom_to_use(formula * cur_hyp);
	bool is_applicable_for_mp();
	bool is_in_Deduction_list();
 };

#endif