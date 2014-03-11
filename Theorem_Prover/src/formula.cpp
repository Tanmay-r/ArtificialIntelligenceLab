#include <iostream>
#include "formula.h"

using namespace std;

formula * Formula_Object;
list <formula *> Deduction_list;

formula::formula(){
}

formula::~formula(){}

void formula::put_in_global_list(formula *temp_formula){
	cout<<"Should not reach here" << endl;
}

/********************************************************************************/
binary_formula::binary_formula(formula *temp_lhs , formula * temp_rhs){
	
	lhs = temp_lhs;
	rhs = temp_rhs;
}

binary_formula::~binary_formula()
{

}

void binary_formula::put_in_global_list(formula * temp_formula){
	
	Deduction_list.push_back(temp_formula);

}

/********************************************************************************/
unary_formula::unary_formula(string var_name){
	name = var_name;
}

unary_formula::~unary_formula(){}

void unary_formula::put_in_global_list(formula * temp_formula){

	Deduction_list.push_back(temp_formula);
}

string unary_formula::get_variable_name(){

	return name;
}
