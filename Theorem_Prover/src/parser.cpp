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
	if(formula_string.size() == 1){
		string name ="(";
		name += formula_string ;
		name += ")";
		return new unary_formula(name);
	}
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
		string name = "(";
		//cout << lhs_rhs[1] << endl;
		formula * lhs = parse(lhs_rhs[0]) ;
		formula * rhs = parse(lhs_rhs[1]) ;
		if(lhs->get_type() == 0)
			name+= lhs->get_formula_name().substr(1,1);
		else
			name+= lhs->get_formula_name() ;
		name+=">";
		if(rhs->get_type() == 0)
			name+= rhs->get_formula_name().substr(1,1);
		else
			name+= rhs->get_formula_name() ;	
		name+=")" ;	
		return new binary_formula(lhs,rhs,name) ;
		//return parse(lhs_rhs[1]);
	}
}



vector<string> parser::give_lhs_rhs_string(string formula_string){

	vector<string> to_return;
	int size = formula_string.size();
	int i = 0;
	int balanced_paran = 0;
	string lhs = "" ;
	string rhs = "";
	//cout << "size :" << size <<endl;
	//cout << "in break : " <<formula_string <<endl;
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

			//cout << "in break rhs : " <<rhs <<endl;
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
