#include <iostream>
#include <queue>
#include "state.h"
#include "state_list.h"
#include "helper.h"
#include "astar.h"
#include <map>
using namespace std;

vector<state*> states;

astar::astar()
{
}

astar::~astar()
{
}

void astar::execute()
{
	state* start = createStart();
	state* goal = createGoal();
	
	start->setPredictor((int) displacedTile);
	start->monotone = true;
	
	start->setFvalue(goal);
	
	state_list open_list;
	state_list closed_list;
	
	open_list.insertState(start);
	states.push_back(start);
	state* curr=NULL;
	
	int steps=0;
	while(!open_list.isEmpty())
	{
		steps++;
		//cout<<steps<<endl;
		curr = open_list.getState();
		closed_list.insertState(curr);
		//cout<<"!!!!!!!!!!!!!!!"<<endl;
		//curr->print();
		
		if(curr->equal(goal))
		{
			cout<<"Goal Found\n";
			printPath(curr, start);
			break;
		}
		else
		{
			//cout << " Succesors of  "; curr->print();
			list<state*> child = curr->getSuccessor(); 
			for (list<state*>::iterator it = child.begin(); it != child.end(); it++)
			{
				for(int i=0; i<states.size(); i++)
				{
					if((*it)->equal(states[i]))
					{
						(curr->children).push_back(states[i]);
						continue;
					}
				}
				(curr->children).push_back(*it);
				/*cout<<endl;
				(*it)->print();
				cout<<endl;*/
			}
			//cout<<"Children"<<endl;
			for (list<state*>::iterator it = (curr->children).begin(); it != (curr->children).end(); ++it)
			{
				//(*it)->print();
				if(!curr->equal_ancestor(*it))
				{
					if((*it)->getParent() != NULL)
						(*it)->redirectPointer(*it, curr, goal);
					else //new ones
					{
						(*it)->setPredictor(curr->predict);
						(*it)->monotone = curr->monotone;
						(*it)->redirectPointer(*it, curr, goal);
						(*it)->setFvalue(goal);
						open_list.insertState(*it);
						states.push_back(*it);
					}
				}
				//cout<<"Gval: "<<(*it)->getGvalue()<<" Fval: "<<(*it)->getFvalue()<<" Hval: "<<(*it)->getHvalue()<<endl;
				//cout<<endl;
			}
		}
	}
	cout<<"Nodes Expanded: "<<steps<<endl;
	cout<<"Nodes Visited: "<<states.size()<<endl;
	if(!curr->equal(goal))
		cout<< "Goal Not Found!" << endl;
	
}


