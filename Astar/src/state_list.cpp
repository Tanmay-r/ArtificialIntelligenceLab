#include "state_list.h"
state_list::state_list(){
}

state_list::~state_list(){
}

void state_list::insertState(state *curr){
	lst.insert(curr);
}

state* state_list::getState(){
	
	multiset<state*>::iterator it1, it2;
	if(lst.size()>0)
	{
		it2 = lst.begin();
		int minfval = (*it2)->getFvalue();
		it1 = lst.begin();
		for (multiset<state*>::iterator it = lst.begin(); it != lst.end(); it++)
		{
			if((*it)->getFvalue() < minfval)
			{
				it1 = it;
				minfval = (*it)->getFvalue();
			}
		}
		lst.erase(it1);
		return *it1;
	}
	else
		return NULL;
}

bool state_list::isEmpty(){
	return lst.empty();
}

int state_list::getSize()
{
	return lst.size();
}

