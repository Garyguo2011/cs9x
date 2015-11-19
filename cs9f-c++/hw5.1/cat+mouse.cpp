#include <iostream>
using namespace std;
#include "park.h"
void RunChase (Scene allAnimals) {
	for (int time=1; time<=30; time++) {
		cout << time << endl;
		for (int k=0; k<allAnimals.Length (); k++) {
			if (allAnimals[k]->Chase ()) {
				return;
			}
		}
		cout << endl;
	}
	cout << "Chase took too long; all animals drifted away." 
		  << endl;
}
int main () {
	Scene allAnimals;
	RunChase (allAnimals);
	return 0;
}
