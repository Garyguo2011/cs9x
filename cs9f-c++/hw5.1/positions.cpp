#include "positions.h"
#include <iostream>
#include <math.h>
using namespace std;

Position::Position() {
	myRadius = 1.0;
	myAngleInRadians = 0.0;
	
}

Position::Position(float r) {
	myRadius = r;
	myAngleInRadians = 0.0;
}

Position::Position(float r, float thetaInRadians) {
	myRadius = r;
	myAngleInRadians = thetaInRadians;
}


void Position::SetAbsolutePosition(float r, float thetaInRadians) {
	myRadius = r;
	myAngleInRadians = thetaInRadians;
}

bool Position::operator== (Position coords) {
	return (myRadius == coords.getRadius() && myAngleInRadians == coords.getAngleInRadians());
}

//could have been done with fried classes
float Position::getRadius() {
	return myRadius;
}

float Position::getAngleInRadians() {
	return myAngleInRadians;
}

void Position::IncrementPosition(float rChange, float thetaChange) {
	myRadius = myRadius + rChange;
	if (myRadius < 1.0) {
		myRadius = 1.0;
	}
	myAngleInRadians += thetaChange;
	while(myAngleInRadians > 6.28) {
		myAngleInRadians -= 6.28;
	}
	while (myAngleInRadians < 0) {
		myAngleInRadians += 6.28;
	}
}

void Position::moveDistance(float dist) {
	IncrementPosition(0.0, dist/myRadius);
}

bool Position::IsBetween(Position old, Position current) {
	//return ((old.getAngleInRadians() <= myAngleInRadians and myAngleInRadians <= current.getAngleInRadians())
	//	or (old.getAngleInRadians() >= myAngleInRadians and myAngleInRadians >= current.getAngleInRadians()));
	float maxGap = cos(current.getAngleInRadians() - old.getAngleInRadians());
	return (cos(myAngleInRadians - old.getAngleInRadians()) > maxGap) && (cos(current.getAngleInRadians() - myAngleInRadians) > maxGap);
}


bool Position::Sees(Position pos) {
	//fill this in
		float value = myRadius * cos(myAngleInRadians - pos.getAngleInRadians());
		return value >= 1.0;
	}
	
void Position::Print() {
    cout << "the myRadius is " << myRadius << endl;
		cout << "the angle is " << myAngleInRadians << endl;
	} 