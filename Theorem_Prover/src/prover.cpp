#include <iostream>
#include "prover.h"

using namespace std;

prover::prover(string Formula){


	theorem = my_parser.parse(Formula);
	theorem->make_list();
	for (list<formula * >::iterator it=theorem->get_list().begin(); it != theorem->get_list().end(); ++it){
		(*it)->set_status(true);
		Deduction_list.push_back((*it));
	}
	proved  = false ;
}

prover::~prover(){

}

void prover::print_component_list(){
	theorem->merge_list();
	for (set<string>::iterator it=Component_list.begin(); it!=Component_list.end(); ++it)
		cout << ' ' << *it << endl;
}

void prover::guess_start_hypothesis(){

	int max_guess_length = 0;
	for(int i = 0; i < Deduction_list.size(); i++){
		if(Deduction_list[i]->get_type() == 1){
			string elem = (Deduction_list[i]->get_rhs())->get_formula_name() ;
			if(elem.compare("(F)") == 0){
				if(elem.size() >  max_guess_length){
					max_guess_length = elem.size();
					current_guess_formula = Deduction_list[i]->get_lhs() ;
				}
			}
		}
	}

}

int * prover::axiom_to_use(formula * cur_hyp){

	int* arr = new int[3];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	formula * rhs =  cur_hyp->get_rhs() ;
	formula * lhs = cur_hyp->get_lhs() ;
	if(cur_hyp->get_type() == 1)
		arr[0] = 1;
	if(rhs->get_type() == 1 && lhs->get_type() == 1 ){
		if(rhs->get_lhs()->get_formula_name().compare(rhs->get_lhs()->get_formula_name()) == 0){
			arr[1] = 1;
		}
	}

	return arr ;
}

bool prover::is_in_Deduction_list(){
	bool is_present = false ;
	for(int i = 0; i < Deduction_list.size(); i++){
		//cout << Deduction_list[i]->get_formula_name() << "  " << current_guess_formula->get_formula_name() <<endl;
		if( Deduction_list[i]->get_formula_name().compare(current_guess_formula->get_formula_name()) == 0){
			is_present = true ;
			proved = true ;

		}
	}
	return is_present ;
}

bool prover::is_applicable_for_mp(){

	bool flag = false ;
	for(int i = 0; i < Deduction_list.size(); i++){
		if(Deduction_list[i]->get_type() == 1){
			formula * elem_rhs = Deduction_list[i]->get_rhs() ;
			formula * elem_lhs = Deduction_list[i]->get_lhs() ;
			if(elem_rhs->get_formula_name().compare(current_guess_formula->get_formula_name()) == 0){
				for(int j = 0; j < Deduction_list.size(); j++){
					if(elem_lhs->get_formula_name().compare(Deduction_list[j]->get_formula_name()) == 0){
						use_MP(j,i) ;
						flag = true ;
						return flag ;
					}
				}
			}
		}
	}
	return flag ;
}







void prover::next_step(){

	cout << "Proof ::" << endl;
	char flag ;
	int axiom_no;
	int Li , Lj ;
	while(!proved){
		cout << "Current Proof Status " << endl;
 		for(int i = 0 ; i < Deduction_list.size() ; i ++){
			cout<< i <<" :: " << Deduction_list[i]->get_formula_name() << endl ;
		}
		guess_start_hypothesis() ;
		cout << "Do you want to apply MP ? (Y/N) " << endl;
		cin >> flag ;
		
		if(flag == 'Y' || flag == 'y'){
			/*cout << "Choose first hypothesis by their index" << endl ;
			cin>>Li;
			cout << "Choose second hypothesis by their index" << endl ;
			cin>>Lj;
			use_MP(Li,Lj);*/
			if(is_in_Deduction_list()){
				cout << "is a hypothesis" << endl;

				cout << "proved" << endl;
				continue ;
			}
			else if(is_applicable_for_mp()){
				cout << "MP applicable" << endl;	
				continue;
			}
			else{
				cout << "MP not applicable" << endl;
			}
		}
		cout << "Do you want to apply axiom ? (Y/N) " << endl;
		cin >> flag ;
		if(flag == 'Y' || flag == 'y'){
			cout << "Choose an axiom number (1, 2, 3)" << endl;
			cin>>axiom_no;
			string A , B ,C;
			switch (axiom_no){
				case 1 :
					cout << "Enter the first formula" << endl;
					cin>>A;
					cout << "Enter the second formula" << endl;
					cin>>B;
					Deduction_list.push_back(set_up_axiom.axiom_A11(A,B));
					break;
				case 2 :
					cout << "Enter the first formula" << endl;
					cin>>A;
					cout << "Enter the second formula" << endl;
					cin>>B;
					cout << "Enter the third formula" << endl;
					cin>>C;	
					Deduction_list.push_back(set_up_axiom.axiom_A21(A, B, C));				
					break;
				case 3 :
					cout << "Enter the formula" << endl;
					cin>>A;
					//formula * f = set_up_axiom.axiom_A21(A);	
					Deduction_list.push_back(set_up_axiom.axiom_A31(A));
					break;	
				default:
					cout<< "PC has only three axioms" << endl ;	
					break;			
			}
		}

	}

} 
void prover::use_MP(int Li , int Lj){

	//cout << "begin of MP" << endl;
	if(Deduction_list[Lj]->get_type() == 1){
		//cout << "in mid of MP" << endl;
		string Lj_lhs_name = (Deduction_list[Lj]->get_lhs())->get_formula_name();
		cout << Lj_lhs_name << endl ;
		if(Deduction_list[Li]->get_formula_name().compare(Lj_lhs_name) == 0){
			(Deduction_list[Lj]->get_rhs())->set_status(true);
			cout << (Deduction_list[Lj]->get_rhs())->get_formula_name() << endl ;
			if((Deduction_list[Lj]->get_rhs())->get_formula_name().compare("(F)") == 0){
				cout << "proved " << endl;
				proved = true ;
			}
			else
				Deduction_list.push_back(Deduction_list[Lj]->get_rhs());
		}
		else{
			cout << "Choose correct pair of hypothesis" << endl;
		}

	}
	else{
		cout << "Choose correct pair of hypothesis" << endl;
	}
}