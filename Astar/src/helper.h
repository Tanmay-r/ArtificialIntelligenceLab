#ifndef HELP_H
#define HELP_H
#include "state.h"

void printPath(state* goal,state* start)
{	
	int x =0 ;
	cout<<"Printing from goal to parent path"<<endl;
	while(goal != NULL)
	{
		goal->print();
		cout<<endl;
		goal = goal->getParent();
		x++;
	}
	cout<<"No of Nodes to Goal State: "<<x<<endl;
}

state* createStart()
{
	int mat[3][3];
	mat[0][0] = 1;
	mat[0][1] = 0;
	mat[0][2] = 2;
	mat[1][0] = 4;
	mat[1][1] = 5;
	mat[1][2] = 3;
	mat[2][0] = 6;
	mat[2][1] = 7;
	mat[2][2] = 8;
	
	
	
	eight_puzzle * start = new eight_puzzle(); //comes with parent NULL sucessor list empty
	start->setMatrix(mat);
	
	start->setGvalue(0);
	return start;
	/*boat * start = new boat();
	start->missionaries = 6;
	start->cannibals = 6;
	start->currpos = L;
	return start;*/
}

state* createGoal()
{
	int mat[3][3];
	
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[0][2] = 3;
	mat[1][0] = 4;
	mat[1][1] = 5;
	mat[1][2] = 6;
	mat[2][0] = 7;
	mat[2][1] = 8;
	mat[2][2] = 0;
	
	eight_puzzle * goal = new eight_puzzle();
	goal->setMatrix(mat);
	return goal;
	
	/*boat * goal = new boat();
	goal->missionaries = 0;
	goal->cannibals = 0;
	goal->currpos = R;
	return goal;*/
}
#endif
