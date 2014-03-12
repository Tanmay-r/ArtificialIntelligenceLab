#include <iostream>

#include "parser.h"
using namespace std;

int main() {
	
	parser * myparser = new parser();

	Formula_Object = myparser->parse("(p >(p|p))");
	Formula_Object->print_formula();
		

}