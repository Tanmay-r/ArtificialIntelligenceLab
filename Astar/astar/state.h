#ifndef STATE_H
#define STATE_H
#include <list>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

class state;

class state
{
protected:	
	float gval;
	float hval;
	float fval;
	state* parent;
	
public:
		int predict;
		bool monotone;
	
		list<state*> children;
		state();
		~state();
		
		
		virtual float getGvalue();
		virtual void setGvalue(float gval);
		
		virtual float getFvalue();
		virtual void setFvalue(state* goal);
		
		virtual float getHvalue(); //This wil be predictor
		virtual void setHvalue(state* goal);
		
		virtual bool checkAncestor(state* succ, state* start);
		virtual list<state*> getSuccessor(); //sets children and returns it
		virtual void setParent(state* par);
		virtual state* getParent();
		
		
		virtual void print();
		virtual bool equal(state* st);
		virtual float getdistance(state* st);
		virtual void setPredictor(int pr);
		virtual bool checkPredictorMonotone(int pr);
		virtual bool equal_ancestor(state* st);
		virtual int redirectPointer(state* succ, state* curr, state* goal, int redirections); //checks if monotone then doesnot redirect children of succ
};

enum predictor{displacedTile, manhattan};
class eight_puzzle:public state
{
	
public:
	int matrix[3][3];
	
	eight_puzzle();
	~eight_puzzle();
	
	float getGvalue();
	void setGvalue(float gval);
	
	float getFvalue();
	void setFvalue(state* goal);
	
	float getHvalue(); //This wil be predictor
	void setHvalue(state* goal);
	
	bool checkAncestor(state* succ, state* goal);
	void setParent(state* par);
	state* getParent();
	list<state*> getSuccessor();
	void print();
	bool equal(state* st);
	float getdistance(state* st);
	
	void setMatrix(int mat[3][3]);
	void setPredictor(int pr);
	bool equal_ancestor(state* st);
	int redirectPointer(state* succ, state* curr, state* goal, int redirections); //checks if monotone then doesnot redirect children of succ
};


//////////////////////////////////////////////////////////////
enum boatpos{L,R};
class boat:public state
{	
public:
	int missionaries;
	int cannibals;
	boatpos currpos;
	
	boat();
	~boat();
	void new_state(state* st, state* ep, state* goal);
	
	float getGvalue();
	void setGvalue(float gval);
	
	float getFvalue();
	void setFvalue(state* goal);
	
	float getHvalue(); //This wil be predictor
	void setHvalue(state* goal);
	
	bool checkAncestor(state* succ, state* goal);
	void setParent(state* par);
	state* getParent();
	list<state*> getSuccessor();
	void print();
	bool equal(state* st);
	float getdistance(state* st);
	
	
	void setparameters(int m, int c, boatpos p );
	void setPredictor(int pr);
	bool equal_ancestor(state* st);
	int redirectPointer(state* succ, state* curr, state* goal, int redirections); //checks if monotone then doesnot redirect children of succ
};



#endif
