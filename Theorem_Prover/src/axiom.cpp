#include <iostream>
#include "axiom.h"

axiom::axiom(){}

axiom::~axiom(){}

formula * axiom::axiom_A1(formula * A, formula * B){

	formula * to_return = new formula (A , new formula(B, A));
	to_return->set_status(true); 
	return to_return ;
}

formula * axiom::axiom_A2(formula * A, formula * B, formula * C){
	
	formula *lhs = new binary_formula (A , new binary_formula(B ,C));
	formula *rhs = new binary_formula (new binary_formula (A, B), binary_formula(A, C));
	formula * to_return = new binary_formula(lhs, rhs);
	to_return->set_status(true); 
	return to_return ;
}

formula * axiom::axiom_A3(formula * A){

	formula *lhs = new formula(new formula (A , new unary_formula("F")) , new unary_formula("F"));
	formula * to_return = new binary_formula(lhs, A);
	to_return->set_status(true); 
	return to_return ;

}
