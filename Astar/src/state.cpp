#include<iostream>
#include "state.h"

using namespace std;

state::state()
{
}

state::~state(){
	cout<<"Should not reach here"<<endl;
}


float state::getGvalue()
{
	cout<<"Should not reach here"<<endl;
}
void state::setGvalue(float gval)
{
	cout<<"Should not reach here"<<endl;
}

float state::getFvalue()
{
	cout<<"Should not reach here"<<endl;
}

void state::setFvalue(state* goal)
{
	cout<<"Should not reach here"<<endl;
}

float state::getHvalue()
{
	cout<<"Should not reach here"<<endl;
} //This wil be predictor

void state::setHvalue(state* goal)
{
	cout<<"Should not reach here"<<endl;
}

bool state::checkAncestor(state* succ, state* goal)
{
	cout<<"Should not reach here"<<endl;
}
void state::setParent(state* par)
{
	cout<<"Should not reach here"<<endl;
}
state* state::getParent()
{
	cout<<"Should not reach here"<<endl;
}
list<state*> state::getSuccessor(){
	cout<<"Should not reach here"<<endl;
}
void state::print(){
	cout<<"Should not reach here"<<endl;
}
float state::getdistance(state* st)
{
	cout<<"Should not reach here"<<endl;
}
bool state::equal(state* st)
{
	cout<<"Should not reach here"<<endl;
}

void state::setPredictor(int pr)
{
	cout<<"Should not reach here"<<endl;
}
bool state::checkPredictorMonotone(int pr)
{
	cout<<"Should not reach here"<<endl;
}
void state::redirectPointer(state* succ, state* curr, state* goal)
{
	cout<<"Should not reach here"<<endl;
}

bool state::equal_ancestor(state* st)
{
	cout<<"Should not reach here"<<endl;
}

////////////////////////////////////////////////////////////////////////////
eight_puzzle::eight_puzzle()
{
	gval = 0;
	hval = 0;
	fval = 0;
	parent = NULL;
	predict = 2;
	monotone = false;
}

eight_puzzle::~eight_puzzle()
{
}

void eight_puzzle::setPredictor(int pr)
{
	predict = pr;
	switch(predict)
	{
		case ((int) manhattan): monotone = true;
								break;
								
		case ((int) displacedTile): monotone = false;
								break;
	}
}


	
float eight_puzzle::getGvalue()
{	
	return gval;
}

void eight_puzzle::setGvalue(float gvalue)
{
	gval = gvalue;
}

float eight_puzzle::getFvalue()
{
	return fval;
}

void eight_puzzle::setFvalue(state* goal)
{
	setHvalue(goal);
	fval = gval + hval;
}

float eight_puzzle::getHvalue()
{
	return hval;
}

void eight_puzzle::setHvalue(state* goal)
{
	eight_puzzle* ep = dynamic_cast<eight_puzzle*>(goal);
	for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				if((matrix[i][j] != ep->matrix[i][j]) && (matrix[i][j] != 0))
					hval++;
}

bool eight_puzzle::checkAncestor(state* succ, state* start)
{
	state* curr = parent;
	while(curr != NULL)
	{
		if(succ == curr)
			return true;
	}
	return false;
	
}

void eight_puzzle::setParent(state* par)
{
	parent = par;
	gval = parent->getGvalue() + getdistance(par);
}

state* eight_puzzle::getParent()
{
	return parent;
}

list<state*> eight_puzzle::getSuccessor()
{
	
	int x_zero, y_zero,temp;
	list<state*> lst;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(matrix[i][j] == 0)
			{
				x_zero = i;
				y_zero = j;
			}
		}
	}
	eight_puzzle* child1 = new eight_puzzle();
	eight_puzzle* child2 = new eight_puzzle();
	eight_puzzle* child3 = new eight_puzzle();
	eight_puzzle* child4 = new eight_puzzle();
	
	if(x_zero-1 >= 0)
	{
		
		
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				child1->matrix[i][j] = matrix[i][j];
		//child1->setMatrix(matrix);
				
		temp = matrix[x_zero][y_zero];
		child1->matrix[x_zero][y_zero] = child1->matrix[x_zero - 1][y_zero];
		child1->matrix[x_zero - 1][y_zero] = temp;
		
		lst.push_back(child1);
	}
	if(y_zero-1 >= 0)
	{
		//eight_puzzle* child2 = new eight_puzzle();
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				child2->matrix[i][j] = matrix[i][j];
				
		temp = matrix[x_zero][y_zero];
		child2->matrix[x_zero][y_zero] = child2->matrix[x_zero ][y_zero - 1];
		child2->matrix[x_zero][y_zero-1] = temp;
		lst.push_back(child2);
	}
	if(x_zero+1 <= 2)
	{
		//eight_puzzle* child3 = new eight_puzzle();
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				child3->matrix[i][j] = matrix[i][j];
				
		temp = matrix[x_zero][y_zero];
		child3->matrix[x_zero][y_zero] = child3->matrix[x_zero + 1][y_zero];
		child3->matrix[x_zero + 1][y_zero] = temp;
		lst.push_back(child3);
	}
	if(y_zero+1 <= 2)
	{
		//eight_puzzle* child4 = new eight_puzzle();
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				child4->matrix[i][j] = matrix[i][j];
				
		temp = matrix[x_zero][y_zero];
		child4->matrix[x_zero][y_zero] = child4->matrix[x_zero ][y_zero+1];
		child4->matrix[x_zero][y_zero+1] = temp;
		lst.push_back(child4);
	}
	return lst;
	
}
void eight_puzzle::print()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
bool eight_puzzle::equal(state* st)
{
	eight_puzzle* est =  dynamic_cast<eight_puzzle*>(st); 
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			if(matrix[i][j] != est->matrix[i][j])
				return false;
	}
	return true;
}

bool eight_puzzle::equal_ancestor(state* st)
{
	eight_puzzle* ancestor = dynamic_cast<eight_puzzle*>(parent);
	while(ancestor!=NULL)
	{
		if(ancestor->equal(st))
			return true;
		ancestor = dynamic_cast<eight_puzzle*>(ancestor->parent);
	}
	return false;
}

float eight_puzzle::getdistance(state* st)
{
	return 1;
}

void eight_puzzle::setMatrix(int mat[3][3])
{
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			matrix[i][j] = mat[i][j];
}


void eight_puzzle::redirectPointer(state* succ, state* curr, state* goal) //checks if monotone then doesnot redirect children of succ
{
	if(succ->getParent() == NULL)
		succ->setParent(curr);
	else
	{
		if(monotone == false)
		{
			for (list<state*>::iterator it = (succ->children).begin(); it != (succ->children).end(); it++)
			{
				//succ->setFvalue(goal);
				if(succ->getFvalue() > (curr->getGvalue() + succ->getdistance(curr) + succ->getHvalue()))
				{
					succ->setParent(curr);
					(succ)->setFvalue(goal);
					redirectPointer(*it ,succ, goal);
				}
			}
		}
		else
		{
			if(succ->getFvalue() > (curr->getGvalue() + succ->getdistance(curr) + succ->getHvalue()))
			{
				succ->setParent(curr);
				(succ)->setFvalue(goal);
			}
		}
	}
}


///////////////////////////////////////////////////////////////


boat::boat()
{
	gval = 0;
	hval = 0;
	fval = 0;
	parent = NULL;
	predict = 1;
	monotone = false;
}


boat::~boat()
{
}


void boat::setPredictor(int pr)
{
	/*predict = pr;
	switch(predict)
	{
		case ((int) manhattan): monotone = true;
								break;
								
		case ((int) displacedTile): monotone = false;
								break;
	}*/
}

float boat::getGvalue()
{	
	return gval;
}

void boat::setGvalue(float gvalue)
{
	gval = gvalue;
}

float boat::getFvalue()
{
	return fval;
}

void boat::setFvalue(state* goal)
{
	setHvalue(goal);
	fval = gval + hval;
}

float boat::getHvalue()
{
	return hval;
}

void boat::setHvalue(state* goal)/////////////////////////////////////////////////////////////////
{
		boat* ep = dynamic_cast<boat*>(goal);
		hval = (missionaries + cannibals) - ep->missionaries - ep->cannibals -1;
		//hval = hval/2;
		//hval=0;
}

bool boat::checkAncestor(state* succ, state* start)
{
	state* curr = parent;
	while(curr != NULL)
	{
		if(succ == curr)
			return true;
	}
	return false;
	
}

void boat::setParent(state* par)
{
	parent = par;
	gval = parent->getGvalue() + getdistance(par);
}

state* boat::getParent()
{
	return parent;
}


list<state*> boat::getSuccessor()/////////////////////////////////////////////////////////////////
{
	list<state*> lst;
	boat* child1 = new boat();
	boat* child2 = new boat();
	boat* child3 = new boat();
	boat* child4 = new boat();
	boat* child5 = new boat();
	if(currpos == L)
	{
		int m= missionaries;
		int c= cannibals;
		int m1=6-missionaries;
		int c1=6-cannibals;
		if((m-2>= c || m-2 ==0) && (m1+2 >= c1))
		{
			child1->missionaries = missionaries-2;
			child1->cannibals = cannibals;
			child1->currpos = R;
			child1->print();
			lst.push_back(child1);
		}
		if(( m-1 >= c-1 || m-1==0) && c-1 >=0 &&  m1+1 >= c1+1)
		{
			child2->missionaries = missionaries-1;
			child2->cannibals = cannibals;
			child2->currpos = R;
			child2->print();
			lst.push_back(child2);
		}
		if(c-2 >=0 && (m1 >= c1+2 || m1 ==0))
		{
			child3->missionaries = missionaries;
			child3->cannibals = cannibals - 2;
			child3->currpos = R;
			child3->print();
			lst.push_back(child3);
		}
		if(c-1 >=0 && (m1 >= c1+1 || m1==0))
		{
			child4->missionaries = missionaries;
			child4->cannibals = cannibals - 1;
			child4->currpos = R;
			child4->print();
			lst.push_back(child4);
		}
		if(m-1 >=0 && c-1>=0 && m1+1 >= c1+1)
		{
			child5->missionaries = missionaries-1;
			child5->cannibals = cannibals-1;
			child5->currpos = R;
			child5->print();
			lst.push_back(child5);
		}
	}
	else
	{
		int x = (3-missionaries);
		int y = (3-cannibals);
		int m = missionaries;
		int c = cannibals;
		if((x-2 >= y || x-2==0 ) && x-2 >=0 && m+2 >= c)
		{
			child1->missionaries = missionaries+2;
			child1->cannibals = cannibals;
			child1->currpos = L;
			child1->print();
			lst.push_back(child1);
		}
		if((x-1 >=y || x-1==0) && x-1 >=0 && m+1 >=c)
		{
			child2->missionaries = missionaries+1;
			child2->cannibals = cannibals;
			child2->currpos = L;
			child2->print();
			lst.push_back(child2);
		}
		if(y-2 >= 0 && (m >= c+2 || m==0))
		{
			child3->missionaries = missionaries;
			child3->cannibals = cannibals+2;
			child3->currpos = L;
			child3->print();
			lst.push_back(child3);
		}
		if(y-1 >=0 && (m >= c+1 || m==0))
		{
			child4->missionaries = missionaries;
			child4->cannibals = cannibals+1;
			child4->currpos = L;
			child4->print();
			lst.push_back(child4);
		}
		if(x-1 >=0 && y-1>=0 && m+1>=c+1)
		{
			child5->missionaries = missionaries+1;
			child5->cannibals = cannibals+1;
			child5->currpos = L;
			child5->print();
			lst.push_back(child5);
		}	
	}
	return lst;
}

void boat::print()
{
	cout << "<" << missionaries << "," << cannibals << ","<< currpos << ">"<<endl;
}

bool boat::equal(state* st)
{
	boat* est =  dynamic_cast<boat*>(st); 
	if(missionaries == est->missionaries && cannibals == est->cannibals && currpos==est->currpos)
		return true;
	return false;
}

bool boat::equal_ancestor(state* st)
{
	boat* ancestor = dynamic_cast<boat*>(parent);
	while(ancestor!=NULL)
	{
		if(ancestor->equal(st))
			return true;
		ancestor = dynamic_cast<boat*>(ancestor->parent);
	}
	return false;
}

float boat::getdistance(state* s)/////////////////////////////////////////////////////////////////
{
		return 1;
}

void boat::setparameters(int m, int c, boatpos p )
{
	missionaries = m;
	cannibals = c;
	currpos = p;
}


void boat::redirectPointer(state* succ, state* curr, state* goal)
{
	if(succ->getParent() == NULL)
	{
		succ->setParent(curr);
		//succ->setFvalue(goal);
	}
	else
	{
		for (list<state*>::iterator it = (succ->children).begin(); it != (succ->children).end(); it++)
		{
			//succ->setFvalue(goal);
			if(succ->getFvalue() > (curr->getGvalue() + succ->getdistance(curr) + succ->getHvalue()))
			{
				succ->setParent(curr);
				(succ)->setFvalue(goal);
				redirectPointer(*it ,succ, goal);
			}
		}
	}
}

void boat::new_state(state* st,state* ep, state* goal)
{
}

