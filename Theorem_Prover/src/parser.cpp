#include <iostream>
#include <vector>
#include "parser.h"

using namespace std;

parser::parser(){}

parser::~parser(){}

formula * parser::parse(string formula_string){

	cout << "in_ pasre" << endl;
	if(formula_string.size() == 1)
		return new unary_formula(formula_string);
	else{
		vector <string> lhs_rhs = give_lhs_rhs_string (formula_string.substr(1,formula_string.size()-2));
		cout << "binary ::"  << lhs_rhs[0] << "::" << lhs_rhs[1]<<endl;
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
	//formula_string.replace(formula_string.begin(), formula_string.end(), ' ', '');
	while(i < size){
		if(formula_string[i] == '(')
			balanced_paran++;
		if(formula_string[i] == ')')
			balanced_paran--;
		if(formula_string[0]== '!'){
			lhs+=formula_string.substr(1);
			rhs+="F";
			break;
		}
		if(formula_string[i] == '>' && balanced_paran == 0){

			rhs+=formula_string.substr(i+1);
			cout<< "rhs :: " <<rhs<<endl;
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
	to_return.push_back(lhs);
	to_return.push_back(rhs);
	cout << to_return[0] << "::" << lhs <<endl;
	return to_return;
}
