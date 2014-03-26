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
					cur_guess_index = i ;
				}
			}
		}
	}

}

int * prover::axiom_to_use(formula * cur_hyp){

	int* arr = new int[3];
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	if(cur_hyp->get_type() == 1){
		formula * rhs =  cur_hyp->get_rhs() ;
		formula * lhs = cur_hyp->get_lhs() ;
		if(cur_hyp->get_type() == 1)
			arr[0] = 1;
		if(rhs->get_type() == 1 && lhs->get_type() == 1 ){
			if(rhs->get_lhs()->get_formula_name().compare(rhs->get_lhs()->get_formula_name()) == 0){
				arr[1] = 1;
			}
		}
	}
	return arr ;
}

bool prover::apply_axiom(){

	int* arr  = axiom_to_use(current_guess_formula) ;
	bool present = false ;
	if(arr[0] == 1){
		cout << current_guess_formula->get_lhs()->get_formula_name() << endl ;
		string B =current_guess_formula->get_lhs()->get_formula_name() ;
		string A = current_guess_formula->get_rhs()->get_formula_name() ;
		if(current_guess_formula->get_lhs()->get_type() == 0 )
			B = current_guess_formula->get_lhs()->get_formula_name().substr(1,1);
		if(current_guess_formula->get_rhs()->get_type() == 0 )
			A = current_guess_formula->get_rhs()->get_formula_name().substr(1,1);
		formula * ax1 = set_up_axiom.axiom_A11(A,B);
		for(int i = 0; i < Deduction_list.size(); i++){
			if( Deduction_list[i]->get_formula_name().compare(ax1->get_formula_name()) == 0){
				present = true ;
			}
		}
		if(present){
			present = false ;
			delete(ax1);
			if(arr[1] == 1){
				formula * A = current_guess_formula->get_lhs()->get_lhs() ;
				formula * B = current_guess_formula->get_lhs()->get_rhs() ;
				formula * C = current_guess_formula->get_rhs()->get_rhs() ;
 				formula * ax2 = set_up_axiom.axiom_A21(A->get_formula_name() , B-> get_formula_name () , C-> get_formula_name() );
				for(int i = 0; i < Deduction_list.size(); i++){
					if( Deduction_list[i]->get_formula_name().compare(ax2->get_formula_name()) == 0){
						present = true ;
					}
				}
				if(present){
					return false ;
				}
				else{
					cout << "Applying axiom 2" << endl ;
					cout <<" "<<A->get_formula_name() << endl; 
					cout <<" "<<B->get_formula_name() << endl; 
					cout <<" "<<C->get_formula_name() << endl; 
					Deduction_list.push_back(ax2) ;
					current_guess_formula = ax2->get_lhs() ;
					cur_guess_index = Deduction_list.size() -1 ;
					return true ;
				}
			}
		}
		else{
			cout << "Applying axiom 1" << endl ;
			cout <<" " << A << endl ;
			cout <<" " << B << endl ;
			Deduction_list.push_back(ax1) ;
			current_guess_formula = ax1->get_lhs() ;
			cur_guess_index = Deduction_list.size() -1 ;
			return true ;
		}
	}
	return false ;
}



bool prover::is_in_Deduction_list(){
	bool is_present = false ;
	for(int i = 0; i < Deduction_list.size(); i++){
		//cout << Deduction_list[i]->get_formula_name() << "  " << current_guess_formula->get_formula_name() <<endl;
		if( Deduction_list[i]->get_formula_name().compare(current_guess_formula->get_formula_name()) == 0){
			if(cur_guess_index != i){
				cout << "MP applicable" << endl;
				is_present = true ;
				use_MP(i , cur_guess_index) ;
			}
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
					if(elem_lhs->get_formula_name().compare(Deduction_list[j]->get_formula_name()) == 0){\
						cout << "MP applicable" << endl;
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
	guess_start_hypothesis() ;
	while(!proved){
		cout << "Current Proof Status " << endl;
 		for(int i = 0 ; i < Deduction_list.size() ; i ++){
			cout<< i <<" :: " << Deduction_list[i]->get_formula_name() << endl ;
		}
		//cout << "Do you want to apply MP ? (Y/N) " << endl;
		//cin >> flag ;cout <<Li <<"::"<<Deduction_list[Li]->get_formula_name() << endl;
		
		//if(flag == 'Y' || flag == 'y'){
			/*cout << "Choose first hypothesis by their index" << endl ;
			cin>>Li;
			cout << "Choose second hypothesis by their index" << endl ;
			cin>>Lj;
			use_MP(Li,Lj);*/
		if(is_in_Deduction_list()){
			continue ;
		}
		else if(is_applicable_for_mp()){	
			continue;
		}
		else{
			cout << "MP not applicable" << endl;
		}
		//}
		bool is_applying_axiom = apply_axiom() ;


		if(!is_applying_axiom){
			cout << "Do you want to apply axiom ? (Y/N) " << endl;
			cin >> flag ;
			if(flag == 'Y' || flag == 'y'){
				cout << "Choose an axiom number (1, 2, 3)" << endl;
				cin>>axiom_no;
				string A , B ,C;
				formula * f;
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
						f = set_up_axiom.axiom_A31(A);	
						Deduction_list.push_back(f);
						current_guess_formula = f ;
						cur_guess_index = Deduction_list.size() - 1 ;
						break;	
					default:
						cout<< "PC has only three axioms" << endl ;	
						break;			
				}
			}
		}

	}

} 
void prover::use_MP(int Li , int Lj){

	cout << "\nApplying MP on .." <<endl ;
	cout <<Li <<"::"<<Deduction_list[Li]->get_formula_name() << endl;
	cout <<Lj <<"::"<<Deduction_list[Lj]->get_formula_name() << endl;
	if(Deduction_list[Lj]->get_type() == 1){
		//cout << "in mid of MP" << endl;
		string Lj_lhs_name = (Deduction_list[Lj]->get_lhs())->get_formula_name();
		if(Deduction_list[Li]->get_formula_name().compare(Lj_lhs_name) == 0){
			(Deduction_list[Lj]->get_rhs())->set_status(true);
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