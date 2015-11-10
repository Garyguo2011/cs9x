#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <vector>
#include "positions.h"
#include "park.h"



class Cat: public Animal {
friend class Scene;

public:
	Cat(string s, Position p);
	virtual bool Chase(); //const?


protected:


};

class Mouse: public Animal {
friend class Scene;

public:
	Mouse(string s, Position P);
	virtual bool Chase();

protected:

};


class Person: public Animal {
friend class Scene;

public:
	Person(string s, Position p);
	virtual bool Chase();

protected:


};




#endif