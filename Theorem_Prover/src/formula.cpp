#include <iostream>
#include "formula.h"
#include <list>
#include <stdlib.h> 
using namespace std;

formula * Formula_Object ;
vector <formula *> Deduction_list ;
set <string> Component_list ;

formula::formula(){
}

formula::~formula(){}

void formula::print_formula(){
	cout<<"Should not reach here" << endl;
}
void formula::print_rhs_lhs(){
	cout<<"Should not reach this print" << endl;
}
void formula::merge_list(){
	cout<<"Should not reach this merge" << endl;
}

formula* formula::get_lhs(){
	cout<<"Should not rech this merge" << endl;
	exit(0);
	return NULL;
}
formula* formula::get_rhs(){
	cout<<"Should not rech this merge" << endl;
	exit(0);
	return NULL;
}
/********************************************************************************/
binary_formula::binary_formula(formula *temp_lhs , formula * temp_rhs , string name){
	
	lhs = temp_lhs;
	rhs = temp_rhs;
	formula_status = false ;
	type = 1;
	formula_name = name;
}

binary_formula::~binary_formula()
{

}

void binary_formula::set_status(bool status){

	formula_status = status ;
}

void binary_formula::merge_list(){

	Component_list.insert(formula_name);
	lhs->merge_list();
	rhs->merge_list();

}

void binary_formula::print_rhs_lhs(){
	 cout << rhs->get_formula_name() << endl;
}

bool binary_formula::get_status(){

	return formula_status ;
}
void binary_formula::print_formula(){
	cout << formula_name << endl ;
}
formula * binary_formula::get_lhs(){

	return lhs;

}

formula * binary_formula::get_rhs(){

	return rhs;

}

void binary_formula::make_list(){

	if(hyp_list.size() == 0){
		hyp_list.push_back(lhs);
		rhs->make_list();
		hyp_list.splice(hyp_list.end(), rhs->get_list());
	}
}
list<formula * > & binary_formula::get_list(){

	return hyp_list;
}

int binary_formula::get_type(){

	return type;
}

string binary_formula::get_formula_name(){

	return formula_name ;
}

/********************************************************************************/
unary_formula::unary_formula(string var_name){
	name = var_name;
	formula_status = false ;
	type = 0;


}

unary_formula::~unary_formula(){}

void unary_formula::set_status(bool status){

	formula_status = status ;
}

bool unary_formula::get_status(){

	return formula_status ;
}
void unary_formula::make_list(){

	if(name.compare("(F)") != 0){
		string name_var = "(";
		name_var += name.substr(1,1);
		name_var += ">";
		name_var +="F)";
		hyp_list.push_back(new binary_formula(new unary_formula(name),new unary_formula("(F)") , name_var));
	}

}
list<formula * > & unary_formula::get_list(){

	return hyp_list ;
}

void unary_formula::merge_list(){

	Component_list.insert(name);
}

int unary_formula::get_type(){
	return type;
}

void unary_formula::print_formula(){
	cout << " " << name << " ";
}

string unary_formula::get_formula_name(){

	return name;
}
