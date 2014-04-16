#include "astar.h"
#include "bidirection.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
int main()
{
	srand (time(NULL));
	//astar puzzle;
	bidirection puzzle;
	puzzle.execute();
	return 0;
}
