#ifndef PROVER_H
#define PROVER_H
#include <iostream>
#include "axiom.h"

class prover {

	bool proved;
	axiom set_up_axiom;
	parser my_parser;
	formula * theorem;
	formula * current_guess_formula ;
	int cur_guess_index;
	bool hint_flag ;
	vector <formula *> list_of_guesses ;
public:
	prover(string Formula);
	~prover();
	void next_step();
	void print_component_list();
	void put_in_guess_list(formula * f);
	bool apply_axiom();
	void guess_start_hypothesis(int level);
	int* axiom_to_use(formula * cur_hyp);
	bool is_in_Deduction_list(formula * f);
	void hint();
	void start_proof() ;
	bool apply_mp() ;
	bool apply_axiom_guess() ;

 };

#endif