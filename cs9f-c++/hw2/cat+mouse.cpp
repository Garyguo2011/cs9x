#include <iostream>
#include <cmath>
#include "positions.h"

using namespace std;


const int MAX_RUNS = 30;

// You define the GetPositions function.
// It should read legal cat and mouse positions from the user
// and return the position values in its two arguments.
void GetPositions (Position& cat, Position& mouse) {
    float catRadius;
    float catAngle;
    float mouseAngle;
    cout << "Cat radius: ";
    cin >> catRadius;
    cout << "Cat angle: ";
    cin >> catAngle;
    cout << "mouse angle: ";
    cin >> mouseAngle;
    cout << endl;
    cat.SetAbsolutePosition(catRadius, catAngle * M_PI / 180);
    mouse.SetAbsolutePosition(1.0, mouseAngle * M_PI / 180);
}

// You define the RunChase function.
// Given initialized cat and mouse positions,
// it should simulate the cat chasing the mouse, printing the 
// result of each movement of cat and mouse.  Either the cat will 
// catch the mouse, or 30 time units will go by and the cat will 
// give up.
void RunChase (Position& cat, Position& mouse) {
    for (int i = 1; i <= MAX_RUNS; i++) {
    	Position originalCat = cat;
    	if(cat.Sees(mouse)){
    		cat.IncrementPosition(-1, 0);
    	} else {
    		cat.IncrementPosition(0, 1.25);
    	}
    	if(cat.IsAtStatue() && mouse.IsBetween(originalCat, cat)) {
    		cout << "Cat caughted Mouse in " << i << endl;
    		return;
    	}
    	mouse.IncrementPosition(0, 1);
    }
    cout << "Mouse escaped" << endl;
}

int main () {
    Position cat, mouse;
    GetPositions (cat, mouse);
    RunChase (cat, mouse);
    return 0;
}
