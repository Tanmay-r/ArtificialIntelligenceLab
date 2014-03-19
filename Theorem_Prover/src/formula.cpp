#include <iostream>
#include "formula.h"

using namespace std;

formula * Formula_Object;
list <formula *> Deduction_list;


formula::formula(){
}

formula::~formula(){}

void formula::print_formula(){
	cout<<"Should not reach here" << endl;
}
void formula::put_in_global_list(formula *temp_formula){
	cout<<"Should not reach here" << endl;
}

/********************************************************************************/
binary_formula::binary_formula(formula *temp_lhs , formula * temp_rhs){
	
	lhs = temp_lhs;
	rhs = temp_rhs;
	formula_status = false ;
}

binary_formula::~binary_formula()
{

}

void binary_formula::set_status(bool status){

	formula_status = status ;
}

bool binary_formula::get_status(){

	return formula_status ;
}
void binary_formula::print_formula(){
	cout <<"( " ;
	lhs->print_formula() ;
	cout << " )" ;
	cout << " -> " ;
	cout << "( " ;
	rhs->print_formula() ;
	cout << " )";
	cout << "\n";
}
void binary_formula::put_in_global_list(formula * temp_formula){
	
	Deduction_list.push_back(temp_formula);

}

/********************************************************************************/
unary_formula::unary_formula(string var_name){
	name = var_name;
	formula_status = false ;
}

unary_formula::~unary_formula(){}

void unary_formula::set_status(bool status){

	formula_status = status ;
}

bool unary_formula::get_status(){

	return formula_status ;
}

void unary_formula::put_in_global_list(formula * temp_formula){

	Deduction_list.push_back(temp_formula);
}

void unary_formula::print_formula(){
	cout << " " << name << " ";
}

string unary_formula::get_variable_name(){

	return name;
}
