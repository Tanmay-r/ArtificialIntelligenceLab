#include <iostream>
#include "axiom.h"

axiom::axiom(){}

axiom::~axiom(){}

formula * axiom::axiom_A1(formula * A, formula * B){


	string name_lhs = A->get_formula_name();
	string name_rhs ="(";
	name_rhs+=B->get_formula_name();
	name_rhs+=">";
	name_rhs+= A->get_formula_name(); 
	name_rhs += ")";
	string name = "(";
	name += name_lhs ;
	name +=">";
	name += name_rhs ;
	name +=")";
	binary_formula * to_return = new binary_formula (A , new binary_formula(B, A,name_rhs) ,name);
	to_return->set_status(true); 
	return to_return ;
}

formula * axiom::axiom_A2(formula * A, formula * B, formula * C){
	

	string name_lhs_b , name_lhs, name_rhs_a , name_rhs_b , name_rhs ,name;

	name_lhs_b += "(" ;
	name_lhs_b += B->get_formula_name() ;
	name_lhs_b += ">" ;
	name_lhs_b += C->get_formula_name();
	name_lhs_b += ")" ;

	name_lhs = "(" ;
	name_lhs += A->get_formula_name();
	name_lhs += ">";
	name_lhs += name_lhs_b ;
	name_lhs += ")" ;

	name_rhs_a ="(";
	name_rhs_a += A->get_formula_name();
	name_rhs_a +=">";
	name_rhs_a += B->get_formula_name(); 
	name_rhs_a += ")";
	
	name_rhs_a ="(";
	name_rhs_a += A->get_formula_name();
	name_rhs_a +=">";
	name_rhs_a += B->get_formula_name(); 
	name_rhs_a += ")";

	name_rhs_b ="(";
	name_rhs_b += A->get_formula_name();
	name_rhs_b +=">";
	name_rhs_b += C->get_formula_name(); 
	name_rhs_b += ")";
	name_rhs = "(" ;
	name_rhs += name_rhs_a;
	name_rhs +=">";
	name_rhs += name_rhs_b;
	name_rhs +=")";

	name = "(" ;
	name += name_lhs ;
	name += ">";
	name += name_rhs ;
	name += ")";

  	binary_formula *lhs = new binary_formula (A , new binary_formula(B ,C,name_lhs_b) ,name_lhs);
	binary_formula *rhs = new binary_formula (new binary_formula (A, B, name_rhs_a), new binary_formula(A, C ,name_rhs_b),name_rhs);
	binary_formula * to_return = new binary_formula(lhs, rhs ,name);
	to_return->set_status(true); 
	return to_return ;
}

formula * axiom::axiom_A3(formula * A){

	string name_lhs_a , name_lhs, name;
	name_lhs_a = "(" ;
	name_lhs_a += A->get_formula_name();
	name_lhs_a+= ">" ;
	name_lhs_a += "(F)";
	name_lhs_a += ")";

	name_lhs = "(" ;
	name_lhs += name_lhs_a ;
	name_lhs += ">" ;
	name_lhs +="(F))";


	name  = "(" ;
	name += name_lhs ;
	name += ">";
	name += A->get_formula_name();
	name += ")" ;

	binary_formula *lhs = new binary_formula(new binary_formula (A , new unary_formula("F") ,name_lhs_a) , new unary_formula("F") , name_lhs);
	binary_formula * to_return = new binary_formula(lhs, A , name);
	to_return->set_status(true); 
	return to_return ;

}


formula * axiom::axiom_A11(string A , string B){

	string name_lhs = A;
	string name_rhs ="(";
	name_rhs+=B;
	name_rhs+=">";
	name_rhs+= A; 
	name_rhs += ")";
	string name = "(";
	name += name_lhs ;
	name +=">";
	name += name_rhs ;
	name +=")";
	formula * to_return = axiom_parser.parse(name);
	to_return->set_status(true); 
	return to_return ;

}

formula * axiom::axiom_A21(string A, string B, string C){

	string name_lhs_b , name_lhs, name_rhs_a , name_rhs_b , name_rhs ,name;

	name_lhs_b += "(" ;
	name_lhs_b += B;
	name_lhs_b += ">" ;
	name_lhs_b += C;
	name_lhs_b += ")" ;

	name_lhs = "(" ;
	name_lhs += A;
	name_lhs += ">";
	name_lhs += name_lhs_b ;
	name_lhs += ")" ;

	name_rhs_a ="(";
	name_rhs_a += A;
	name_rhs_a +=">";
	name_rhs_a += B; 
	name_rhs_a += ")";
	
	name_rhs_a ="(";
	name_rhs_a += A;
	name_rhs_a +=">";
	name_rhs_a += B; 
	name_rhs_a += ")";

	name_rhs_b ="(";
	name_rhs_b += A;
	name_rhs_b +=">";
	name_rhs_b += C; 
	name_rhs_b += ")";
	name_rhs = "(" ;
	name_rhs += name_rhs_a;
	name_rhs +=">";
	name_rhs += name_rhs_b;
	name_rhs +=")";

	name = "(" ;
	name += name_lhs ;
	name += ">";
	name += name_rhs ;
	name += ")";
	
	formula * to_return = axiom_parser.parse(name);
	to_return->set_status(true); 
	return to_return ;
	
}

formula * axiom::axiom_A31(string A){

	string name_lhs_a , name_lhs, name;
	name_lhs_a = "(" ;
	name_lhs_a += A;
	name_lhs_a+= ">" ;
	name_lhs_a += "(F)";
	name_lhs_a += ")";

	name_lhs = "(" ;
	name_lhs += name_lhs_a ;
	name_lhs += ">" ;
	name_lhs +="(F))";


	name  = "(" ;
	name += name_lhs ;
	name += ">";
	name += A;
	name += ")" ;
	formula * to_return = axiom_parser.parse(name);
	to_return->set_status(true); 
	return to_return ;

}


