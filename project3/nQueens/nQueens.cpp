
#include <iostream>
#include <cmath>
#include "nQueenPuzzle.h"

using namespace std;

int main()
{
    for(int i = 1; i <= 10; i++){
    	nQueensPuzzle queens(i);

    	queens.queensConfiguration(0);
    	cout << "Number of Solutions: " << queens.solutionsCount() << endl;
    }

	return 0;
}
