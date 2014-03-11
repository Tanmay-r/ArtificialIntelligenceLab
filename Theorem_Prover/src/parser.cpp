#include <iostream>
#include <vector>
#include "parser.h"

using namespace std;

parser::parser(){}

parser::~parser(){}

formula * parser::parse(string formula_string){

	vector <string> lhs_rhs = give_lhs_rhs_string (formula_string.substr(1,formula_string.size()-2));
	if(lhs_rhs[1].compare("") == 0){		
		return 	new unary_formula(lhs_rhs[0]) ; 
	}

	else
		return new binary_formula(parse(lhs_rhs[0]),parse(lhs_rhs[1])) ;
}

vector<string> parser::give_lhs_rhs_string(string formula_string){

	vector<string> to_return;
	int size = formula_string.size();
	int i = 0;
	int balanced_paran = 0;
	string lhs = "" ;
	string rhs = "";
	while(i < size){
		if(formula_string[i] == '(')
			balanced_paran++;
		if(formula_string[i] == ')')
			balanced_paran--;
		if(formula_string[i] == '>' && balanced_paran == 0){

			rhs+=formula_string.substr(i+1);
			break;
		}
		if(formula_string[i] == '|' && balanced_paran == 0){
			lhs+= ">" ;
			lhs+= "F" ;
			string new_lhs = "" ;
			new_lhs+= "(" ;
			new_lhs+= lhs;
			new_lhs+= ")";
			lhs = new_lhs;
			rhs += formula_string.substr(i+1);
			break;

		}
		if(formula_string[i] == '&' && balanced_paran == 0){
			string new_lhs="" ;
			new_lhs+= "(" ;
			new_lhs+= lhs;
			new_lhs+= ">(";
			new_lhs+= formula_string.substr(i+1);
			new_lhs+= ">";
			new_lhs+= "F))";
			rhs += "F";
			break;
		}
		lhs+=formula_string[i];
		i++;
	}

}
