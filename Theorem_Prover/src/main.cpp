#include <iostream>
#include "prover.h"
using namespace std;

int main() {
	


	string Theorem;
	cout << "Enter the theorem " << endl;
	cin>> Theorem ;
	prover * my_prover = new prover(Theorem);
	my_prover->next_step();
		

}