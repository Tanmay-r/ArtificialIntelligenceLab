#ifndef FORMULA_H
#define FORMULA_H
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <cmath>

using namespace std;


class formula;

extern formula * Formula_Object;

class formula{

	bool formula_status;
public:
	formula();
	~formula();
	virtual void put_in_global_list(formula * temp_formula);
	virtual void set_status(bool status);
	virtual bool get_status();
	virtual void print_formula();

};

class binary_formula: public formula
{

	formula * lhs;
	formula * rhs;
	string name;

public:
	binary_formula(formula *temp_lhs , formula *temp_rhs);
	~binary_formula();
	void print_formula();
	void set_status(bool status);
	bool get_status();
	formula * get_lhs();
	void put_in_global_list(formula * temp_formula);

};

class unary_formula: public formula
{
	string name;
public:
	unary_formula(string var_name);
	~unary_formula();
	void print_formula();
	void set_status(bool status);
	bool get_status();
	void put_in_global_list(formula * temp_formula);
	string get_variable_name();
};

#endif