#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include "formula.h"
#include <string>

using namespace std;

class parser{

public:
	parser();
	~parser();

	formula * parse(string formula_string);

	vector<string> give_lhs_rhs_string(string formula_string);
};

#endif