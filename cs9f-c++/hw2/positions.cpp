#include <iostream>
#include <cmath>
#include <algorithm>
#include "positions.h"

using namespace std;

// Covert myRadius and myAngleInRadians as standard form
void Position::Standardize (){
	myRadius = max<float>(myRadius, 1.0);
	myAngleInRadians = fmod(myAngleInRadians, 2 * M_PI);
	if (myAngleInRadians < 0){
		myAngleInRadians += 2 * M_PI;
	}
}

Position::Position() {
	myRadius = 1;
	myAngleInRadians = 0;
	Standardize();
}

Position::Position(float r) {
	myRadius = r;
	myAngleInRadians = 0;
	Standardize();
}

Position::Position(float r, float thetaInRadians) {
	cout << "--------------- " << r;
	cout << "--------------- " << thetaInRadians;
	myRadius = r;
	myAngleInRadians = thetaInRadians;
	Standardize();
}

void Position::SetAbsolutePosition(float r, float thetaInRadians) {
	myRadius = r;
	myAngleInRadians = thetaInRadians;
	Standardize();
}

void Position::IncrementPosition (float rChange, float angularDistChange) {
	myAngleInRadians += angularDistChange / myRadius;
	myRadius += rChange;
	Standardize();
}

void Position::Print(){
	cout << "Radius: " << myRadius << " AngleInRadians:" << myAngleInRadians << endl;
}

bool Position::Sees (Position pos) {
	return myRadius * cos(myAngleInRadians - pos.myAngleInRadians) >= 1.0;
}

bool Position::IsAtStatue () {
	return myRadius == 1.0;
}

bool Position::IsBetween (Position pos1, Position pos2) {
	float A = pos2.myAngleInRadians;
	float B = myAngleInRadians;
	float C = pos1.myAngleInRadians;
	return cos(B - A) > cos(C - A) && cos(C - B) > cos(C - A);
}

float Position::GetMyRadius () {
	return myRadius;
}

float Position::GetMyAngleInRadians () {
	return myAngleInRadians;
}

