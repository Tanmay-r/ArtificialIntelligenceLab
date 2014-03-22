#ifndef FORMULA_H
#define FORMULA_H
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <cmath>


using namespace std;


class formula;

extern formula * Formula_Object ;
extern vector <formula *> Deduction_list ;
extern set <string> Component_list;

class formula{

protected:
	bool formula_status;
	int type;
public:
	formula();
	~formula();
	virtual void set_status(bool status) = 0;
	virtual bool get_status() = 0;
	virtual list<formula *>  & get_list() = 0;
	virtual void make_list() = 0;
	virtual int get_type() = 0;
	virtual void print_formula() = 0;
	virtual string get_formula_name() = 0;
	virtual void print_rhs_lhs();
	virtual void merge_list();
	virtual formula * get_lhs();
	virtual formula * get_rhs();

};

class binary_formula: public formula
{
	string formula_name;
	list<formula *> hyp_list;
	formula * lhs;
	formula * rhs;
public:

	binary_formula(formula *temp_lhs , formula *temp_rhs, string name);
	~binary_formula();
	void print_formula();
	void set_status(bool status);
	bool get_status();
	list<formula *> &  get_list();
	formula * get_lhs();
	formula * get_rhs();
	void make_list();
	int get_type();
	string get_formula_name();
	void print_rhs_lhs();
	void merge_list();

};

class unary_formula: public formula
{
	string name;
	list<formula *> hyp_list;
public:
	unary_formula(string var_name);
	~unary_formula();
	void print_formula();
	void set_status(bool status);
	bool get_status();
	list<formula *> & get_list();
	void make_list();
	int get_type();
	string get_formula_name();
	void merge_list() ;
};

#endif