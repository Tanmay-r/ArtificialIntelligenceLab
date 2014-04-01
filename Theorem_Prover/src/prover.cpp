#include <iostream>
#include "prover.h"

using namespace std;

prover::prover(string Formula){


	bool hint_flag = false ;
	theorem = my_parser.parse(Formula);
	theorem->make_list();
	for (list<formula * >::iterator it=theorem->get_list().begin(); it != theorem->get_list().end(); ++it){
		(*it)->set_status(true);
		Deduction_list.push_back((*it));
		put_in_guess_list((*it));
	}
	proved  = false ;
}

prover::~prover(){

}
void prover::put_in_guess_list(formula * f){

	if(f->get_type() == 1){
	string elem = f->get_rhs()->get_formula_name() ;
	if( elem.compare("(F)") == 0 ){
		list_of_guesses.push_back(f);
	}
	else if(f->get_rhs()->get_type() == 1){
			formula * sec_guess = f->get_rhs() ;
			string elem = sec_guess->get_rhs()->get_formula_name() ;
			if(elem.compare("(F)") == 0){
				list_of_guesses.push_back(f);
			}
		}
	}

}
void prover::print_component_list(){
	theorem->merge_list();
	for (set<string>::iterator it=Component_list.begin(); it!=Component_list.end(); ++it)
		cout << ' ' << *it << endl;
}


void prover::guess_start_hypothesis(int level){
	int i , j;
	for(i = 0; i < list_of_guesses.size(); i++){
		if(list_of_guesses[i]->get_status() == true){
			current_guess_formula = list_of_guesses[i]->get_lhs() ;
			for(j = 0; j < Deduction_list.size(); j++){
				if(Deduction_list[j]->get_formula_name().compare(list_of_guesses[i]->get_formula_name()) == 0){
					cur_guess_index = j ;
					break ;
				}
			}
			break ;
		}
	}
	if(i == list_of_guesses.size()){
		cout << "setting hint.... " << endl;
		hint_flag = true ;
	}

}

int * prover::axiom_to_use(formula * cur_hyp){

	int* arr = new int[3];
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	if(cur_hyp->get_type() == 1){
		arr[0] = 1;
		formula * rhs =  cur_hyp->get_rhs() ;
		formula * lhs = cur_hyp->get_lhs() ;
		if(rhs->get_type() == 1 && lhs->get_type() == 1 ){
			if(rhs->get_lhs()->get_formula_name().compare(rhs->get_lhs()->get_formula_name()) == 0){
				arr[1] = 1;
			}
		}
	}
	if(list_of_guesses[cur_guess_index]->get_type() == 1){
		formula * rhs =  list_of_guesses[cur_guess_index]->get_rhs() ;
		formula * lhs = list_of_guesses[cur_guess_index]->get_lhs() ;
		if(rhs->get_formula_name().compare("F") == 0 && lhs->get_type() == 1){
			if(lhs->get_rhs()->get_formula_name().compare("(F)") == 0);
				arr[2] = 1 ;
		}
	}

	return arr ;
}

bool prover::apply_axiom(){

	int* arr  = axiom_to_use(current_guess_formula) ;
	bool present = false ;
	if(arr[0] == 1 && current_guess_formula->get_rhs()->get_formula_name().compare("(F)") != 0){
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
					Deduction_list[cur_guess_index]->set_status(false);
					return false ;
				}
				else{
					cout << "Applying axiom 2" << endl ;
					cout <<" "<<A->get_formula_name() << endl; 
					cout <<" "<<B->get_formula_name() << endl; 
					cout <<" "<<C->get_formula_name() << endl; 
					Deduction_list.push_back(ax2) ;
					return true ;
				}
			}
			else{
					Deduction_list[cur_guess_index]->set_status(false);
			}
		}
		else{
			cout << "Applying axiom 1" << endl ;
			cout <<" " << A << endl ;
			cout <<" " << B << endl ;
			Deduction_list.push_back(ax1) ;
			//current_guess_formula = ax1->get_lhs() ;
			//cur_guess_index = Deduction_list.size() -1 ;
			return true ;
		}
	}
	else{
		Deduction_list[cur_guess_index]->set_status(false);
	}
	return false ;
}



bool prover::is_in_Deduction_list(formula * f ){
	bool is_present = false ;
	for(int i = 0; i < Deduction_list.size(); i++){
		if( Deduction_list[i]->get_formula_name().compare(f->get_formula_name()) == 0){
			//cout << "is present" << endl ;
			is_present = true ;
		}
	}
	return is_present ;
}


void prover::hint(){

	for(int i = 0; i < Deduction_list.size(); i++){
		Deduction_list[i]->set_status(true);
	}
	char flag ;
	hint_flag = false ;
	int axiom_no;
	int Li , Lj ;
	cout << "Do you want to apply manually MP ? (Y/N) " << endl;
	cin >> flag ;
	
	if(flag == 'Y' || flag == 'y'){
			cout << "Choose first hypothesis by its index" << endl ;
			cin>>Li;
			cout << "Choose second hypothesis by its index" << endl ;
			cin>>Lj;

		}
	else {
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
						break;	
					default:
						cout<< "PC has only three axioms" << endl ;	
						break;			
				}
			}
		}

}
bool prover::apply_mp(){
	bool mp_app = false;
	int size = Deduction_list.size();
	for(int i = 0 ;i< size;i++){
		for(int j = 0 ;j < size ; j++){
			if(Deduction_list[j]->get_type() == 1 ){
				formula * elem_rhs = Deduction_list[j]->get_rhs() ;
				formula * elem_lhs = Deduction_list[j]->get_lhs() ;
				if(Deduction_list[i]->get_formula_name().compare(elem_lhs->get_formula_name()) == 0){
					if(!is_in_Deduction_list(elem_rhs)){
						cout << "Applying MP on ...." << endl;
						cout <<i <<"::"<<Deduction_list[i]->get_formula_name() << endl;
						cout <<j <<"::"<<Deduction_list[j]->get_formula_name() << endl;
						Deduction_list.push_back(Deduction_list[j]->get_rhs());
						put_in_guess_list(Deduction_list[j]->get_rhs()) ;
						mp_app = true;
					}
				}
			}

		}
	}

	return mp_app ;
}
void prover::next_step(){
	cout << "Proof Start..." << endl;
	int alpha = 0;
	while(!proved && alpha < 50){
		cout << "Current Proof Status " << endl;
 		for(int i = 0 ; i < Deduction_list.size() ; i ++){
			cout<< i <<" :: " << Deduction_list[i]->get_formula_name() << endl ;
		}	

		bool mp_flag = apply_mp() ;
		for(int i = 0 ; i< Deduction_list.size() ; i++){
			if(Deduction_list[i]->get_formula_name().compare("(F)") == 0){
				cout << "proved" << endl ;
				proved = true ;
				break ;
			}
		}
		if(!mp_flag){
			hint_flag = false ;
			guess_start_hypothesis(1) ;
			int t = 0;
			while(!proved){
				if(hint_flag){
					break ;
				}
				cout << "current_guess_formula :: " << current_guess_formula->get_formula_name() << endl; 
				bool is_applying_axiom = apply_axiom() ;

				if(is_applying_axiom){
					break ;
				}
				else{
					guess_start_hypothesis(1);
				}
				t++ ;
			}
			if(hint_flag){
				hint() ;
			}
		}
		alpha++ ;

	}
}
