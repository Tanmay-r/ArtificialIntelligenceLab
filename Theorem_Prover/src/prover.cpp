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
		cout << "Do you want to apply MP ? (Y/N) " << endl;
		cin >> flag ;
		if(flag == 'Y' || flag == 'y'){
			cout << "Choose first hypothesis by their index" << endl ;
			cin>>Li;
			cout << "Choose second hypothesis by their index" << endl ;
			cin>>Lj;
			use_MP(Li,Lj);
			continue;
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

	cout << "begin of MP" << endl;
	if(Deduction_list[Lj]->get_type() == 1){
		cout << "in mid of MP" << endl;
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