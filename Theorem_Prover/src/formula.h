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
	list<formula *> hyp_list;
	int type;
public:
	formula();
	~formula();
	virtual void put_in_global_list(formula * temp_formula);
	virtual void set_status(bool status);
	virtual bool get_status();
	virtual list<formula *> & get_list();
	virtual void make_list();
	virtual int get_type();
	virtual void print_formula();

};

class binary_formula: public formula
{

	formula * lhs;
	formula * rhs;
	string formula_name;

public:
	binary_formula(formula *temp_lhs , formula *temp_rhs , string name);
	~binary_formula();
	void print_formula();
	void set_status(bool status);
	bool get_status();
	list<formula *> & get_list();
	formula * get_lhs();
	void make_list();
	int get_type();
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
	list<formula *> & get_list();
	void put_in_global_list(formula * temp_formula);
	void make_list();
	int get_type();
	string get_variable_name();
};

#endif