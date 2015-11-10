
#include "animals.h"
#include "park.h"
#include "positions.h"
#include <iostream>
#include <string>
using namespace std;

Mouse::Mouse(string s, Position p)
  : Animal(s, p) {


}

bool Mouse::Chase() {
	float rad = myPos.getRadius();
	myPos.moveDistance(1.0);
	cout << "mouse moves to radius"<< myPos.getRadius() << "and angle" << myPos.getAngleInRadians() << endl;
	return false;
}


Person::Person(string s, Position p)
  : Animal(s, p) {

}
bool Person::Chase() {
	if (myPos.Sees(myTarget->Pos())) {
		cout << "person sees target" << endl;
		return false;
	} else {
		
		myPos.moveDistance(-2.0);
		cout << "person moves to radius" << myPos.getRadius() << "and angle" << myPos.getAngleInRadians() << endl;
		return false;
	}
}

Cat::Cat(string s, Position p)
  : Animal(s, p) {

}

bool Cat::Chase() {
	if (myPos.Sees(myTarget->Pos())) {
		cout << "cat sees target" << endl;
		if (myTarget->Pos().getRadius() == myPos.getRadius()) {
			Position temp = myPos;
			temp.moveDistance(1.25);
			if (myTarget->Pos().IsBetween(myPos, temp)) {
				cout << "cat has caught the mouse" << endl;
				return true;
			} else {
				myPos.moveDistance(1.25);
				cout << "cat has moved to radius" <<myPos.getRadius() << "and angle" << myPos.getAngleInRadians() << endl;
				return false;
			}
		}

		myPos.IncrementPosition(-1.0, 0.0);
		return false;
	} else {
		Position temp = myPos;

		temp.moveDistance(1.25);
		if (myTarget->Pos().IsBetween(myPos, temp) && myPos.getRadius() == myTarget->Pos().getRadius()) {
			cout << "cat caught mouse" << endl;
			return true;
		} else {
			myPos.moveDistance(1.25);
			cout << "cat has moved to radius" <<myPos.getRadius() << "and angle" << myPos.getAngleInRadians() << endl;
			return false;
		}
	}
}
	
	
