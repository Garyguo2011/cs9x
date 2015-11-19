#include "animals.h"
#include "park.h"
#include "positions.h"
#include <iostream>
#include <string>
using namespace std;

Mouse::Mouse(string s, Position p) : Animal(s, p) {
}

bool Mouse::Chase() {
  myPos.IncrementPosition(0, 1.0);
  cout << "Mouse move [radius: " <<  myPos.GetMyRadius() << " , angle:  " << myPos.GetMyAngleInRadians()  << " ]" << endl;
  return false;
}

Cat::Cat(string s, Position p) : Animal(s, p){
}

bool Cat::Chase() {
  Position original = myPos;
  if(myPos.Sees(myTarget->Pos())){
    myPos.IncrementPosition(-1, 0);
  } else {
    myPos.IncrementPosition(0, 1.25);
  }
  if(myPos.IsAtStatue() && myTarget->Pos().IsBetween(original, myPos)) {
    cout << "Cat caughted Mouse "<< endl;
    return true;
  } else {
    cout << "Cat move [radius: " <<  myPos.GetMyRadius() << " , angle:  " << myPos.GetMyAngleInRadians()  << " ]" << endl;
    return false;
  }
}

Person::Person(string s, Position p) : Animal(s, p) {
}

bool Person::Chase() {
  if (myPos.Sees(myTarget->Pos())) {
    cout << "person sees target" << endl;
    return false;
  } else {
    myPos.IncrementPosition(0, -2.0);
    cout << "Person move [radius: " <<  myPos.GetMyRadius() << " , angle:  " << myPos.GetMyAngleInRadians()  << " ]" << endl;
    return false;
  }
}





