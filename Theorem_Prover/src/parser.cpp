#include <iostream>
#include <vector>
#include <stdlib.h> 
#include "parser.h"

using namespace std;

parser::parser(){}

parser::~parser(){}

formula * parser::parse(string formula_string){

	string new_str="";
	int i = 0;
	if(formula_string.size() == 1)
		return new unary_formula(formula_string);
	else{
		while(i<formula_string.size())
		{
			if(formula_string[i] == ' ')
				i++;
			else{
				new_str+=formula_string[i];
				i++;
			}
			
		}

		vector <string> lhs_rhs = give_lhs_rhs_string (new_str.substr(1,new_str.size()-2));
		return new binary_formula(parse(lhs_rhs[0]),parse(lhs_rhs[1])) ;
	}
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
		if(formula_string[0] == '!'){
			lhs+=formula_string.substr(1);
			rhs+="F";
			break;
		}

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
			lhs = new_lhs;

			break;
		}
		lhs+=formula_string[i];
		i++;
	}

	if(balanced_paran != 0){
		cout << "formula is not correct" << endl;
		exit(0);
	}


	to_return.push_back(lhs);
	to_return.push_back(rhs);

	return to_return;
}
