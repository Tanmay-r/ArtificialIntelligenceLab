#include <iostream>
#include <queue>
#include "state.h"
#include "state_list.h"
#include "helper.h"
#include "bidirection.h"
#include <map>
using namespace std;

vector<state*> b_states;

vector<state*> g_states;
vector<state*> s_states;

bidirection::bidirection()
{
}

bidirection::~bidirection()
{
}

int bidirection::execute()
{
	state* start = createStart();
	state* goal = createGoal();
	
	//start->setPredictor((int) displacedTile);
	start->monotone = true;
	
	start->setFvalue(goal);
	
	state_list open_list;
	state_list closed_list;
	
	open_list.insertState(start);
	b_states.push_back(start);
	s_states.push_back(start);
	state* curr=NULL;
	
	
	/////////////////////////////////
	//goal->setPredictor((int) displacedTile);
	goal->monotone = true;
	
	goal->setFvalue(start);
	
	state_list g_open_list;
	state_list g_closed_list;
	
	g_open_list.insertState(goal);
	g_states.push_back(goal);
	b_states.push_back(goal);
	state* curr2=NULL;
	
	int redirections = 0;
	
	int steps=0;
	while(!(open_list.isEmpty() && g_open_list.isEmpty()))
	{
		steps++;
		//cout<<steps<<endl;
		curr = open_list.getState();
		closed_list.insertState(curr);
		//cout<<"!!!!!!!!!!!!!!!"<<endl;
		//curr->print();
		
		/********************/
		curr2 = g_open_list.getState();
		
		
		if(curr->equal(goal))
		{
			cout<<"Goal Found\n";
			printPath(curr, start);
			break;
		}
		else if(curr2->equal(start))
		{
			cout<<"Goal Found\n";
			printPath(curr, goal);
			break;
		}
		else
		{
			//cout << " Succesors of  "; curr->print();
			list<state*> child = curr->getSuccessor(); 
			for (list<state*>::iterator it = child.begin(); it != child.end(); it++)
			{
				for(int i=0; i<b_states.size(); i++)
				{
					if((*it)->equal(b_states[i]))
					{
						(curr->children).push_back(b_states[i]);
						goto p;
					}
				}
				(curr->children).push_back(*it);
				/*cout<<endl;
				(*it)->print();
				cout<<endl;*/
				p:;
			}
			//cout<<"Children"<<endl;
			for (list<state*>::iterator it = (curr->children).begin(); it != (curr->children).end(); ++it)
			{
				//(*it)->print();
				for(int i=0; i<g_states.size(); i++)
				{
					if(g_states[i]->equal(*it))
					{
						cout<<"Goal Found\n";
						cout<<"From node found to start"<<endl;
						printPath(curr, start);
						cout<<"From node found to goal"<<endl;
						printPath(*it, goal);
						cout<<"Steps: "<<steps<<endl;
						cout<<"Nodes Expanded: "<<b_states.size()<<endl;
						cout<<"No of Redirections: "<<redirections<<endl;
						return 0;
					}
				}
				
				if(!curr->equal_ancestor(*it))
				{
					if((*it)->getParent() != NULL)
					{
						redirections = (*it)->redirectPointer(*it, curr, goal, redirections);
					}
					else //new ones
					{
						(*it)->setPredictor(curr->predict);
						(*it)->monotone = curr->monotone;
						redirections = (*it)->redirectPointer(*it, curr, goal, redirections);
						(*it)->setFvalue(goal);
						open_list.insertState(*it);
						b_states.push_back(*it);
						s_states.push_back(*it);
					}
				}
				//cout<<"Gval: "<<(*it)->getGvalue()<<" Fval: "<<(*it)->getFvalue()<<" Hval: "<<(*it)->getHvalue()<<endl;
				//cout<<endl;
			}
			
			
			/****************************************************/
			//For goal to start
			
			//cout << " Succesors of  "; curr->print();
			list<state*> child2 = curr2->getSuccessor(); 
			for (list<state*>::iterator it = child2.begin(); it != child2.end(); it++)
			{
				for(int i=0; i<b_states.size(); i++)
				{
					if((*it)->equal(b_states[i]))
					{
						(curr2->children).push_back(b_states[i]);
						continue;
					}
				}
				(curr2->children).push_back(*it);
				/*cout<<endl;
				(*it)->print();
				cout<<endl;*/
			}
			//cout<<"Children"<<endl;
			for (list<state*>::iterator it = (curr2->children).begin(); it != (curr2->children).end(); ++it)
			{
				//(*it)->print();
				for(int i=0; i<s_states.size(); i++)
				{
					if(s_states[i]->equal(*it))
					{
						cout<<"Goal Found\n";
						cout<<"From node found to start"<<endl;
						printPath(curr2, goal);
						cout<<"From node found to goal"<<endl;
						printPath(*it, start);
						cout<<"Steps: "<<steps<<endl;
						cout<<"Nodes Expanded: "<<b_states.size()<<endl;
						cout<<"No of Redirections: "<<redirections<<endl;
						return 0;
					}
				}
				
				if(!curr2->equal_ancestor(*it))
				{
					if((*it)->getParent() != NULL)
						redirections = (*it)->redirectPointer(*it, curr2, start, redirections);
					else //new ones
					{
						(*it)->setPredictor(curr2->predict);
						(*it)->monotone = curr2->monotone;
						redirections = (*it)->redirectPointer(*it, curr2, start, redirections);
						(*it)->setFvalue(start);
						g_open_list.insertState(*it);
						b_states.push_back(*it);
						g_states.push_back(*it);
					}
				}
				//cout<<"Gval: "<<(*it)->getGvalue()<<" Fval: "<<(*it)->getFvalue()<<" Hval: "<<(*it)->getHvalue()<<endl;
				//cout<<endl;
			}
			
			
		}
	}
	
	cout<<"Steps: "<<steps<<endl;
	cout<<"Nodes Expanded: "<<b_states.size()<<endl;
	cout<<"No of Redirections: "<<redirections<<endl;
	if(!curr->equal(goal))
		cout<< "Goal Not Found!" << endl;
}

