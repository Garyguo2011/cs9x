#ifndef PARK_H
#define PARK_H
#include <vector>
#include <string>
#include "positions.h"
#include <stdlib.h>

using namespace std;


class Animal {
friend class Scene;
public:
	Animal (string, Position);
	string Name () const;
	Position Pos () const;
	// Move the animal, and return true if it catches 
	// its target.
	virtual bool Chase () = 0;
protected:
	string myName;	// animal's name
	Position myPos;	// animal's position
	Animal *myTarget;	// ptr to animal being chased; 0 if none
};
class Scene {
public:
	Scene ();
	int Length ();
	Animal* &operator[] (int k);
private:
	vector<Animal*> allAnimals;
};
#endif
