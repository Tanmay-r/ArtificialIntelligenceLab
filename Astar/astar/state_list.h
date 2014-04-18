#ifndef OLIST_H
#define OLIST_H
#include <iostream>
#include "state.h"
#include <set>
using namespace std;

struct state_fval
{
    bool operator()(state* lhs, state* rhs)
    {
		if(lhs->getFvalue() >= rhs->getFvalue())
			return false;
		else
			return true;
    }
};

class state_list
{
	multiset<state*, state_fval> lst;
	
public:
	state_list();
	~state_list();
	void insertState(state* curr);
	state* getState();
	bool isEmpty();
	int getSize();
};
#endif

