#include <string>
#include <iostream>
#include "amoebas.h"

using namespace std;

Amoeba::Amoeba (string s) {	// an amoeba is born, named s
	myName = s;
	myParent = 0;
	myOlderSibling = 0;
	myOldestChild = 0;
	myYoungestChild = 0;
}

// Access functions
string Amoeba::Name () {
	return myName;
}

Amoeba* Amoeba::Parent () {
	return myParent;
}

void Amoeba::AddChild (Amoeba* newChild) {
	// make child point to parent
	newChild->myParent = this;

	// check for parent having other children
	Amoeba* otherSibling = myYoungestChild;
	if (!otherSibling) {	// the new amoeba is an only child
		myYoungestChild = newChild;	// make the parent's child
		myOldestChild = newChild;		// ptrs point to the new one
		newChild->myOlderSibling = 0;	// no older sibling
	} else {	// there are other kids; make this one the youngest
		myYoungestChild = newChild;	// no younger siblings,
		newChild->myOlderSibling = otherSibling;	// but new kid now
	}					// has older siblings.
}

void Amoeba::PrintChildren() {
	Amoeba *ptr = myYoungestChild;
	while(ptr != NULL){
		cout << ptr->Name() << endl;
		ptr = ptr->myOlderSibling;
	}
}

void Amoeba::PrintGrandchildren() {
    Amoeba *ptr = myYoungestChild;
    while (ptr != NULL) {
        ptr->PrintChildren();
        ptr = ptr->myOlderSibling;
    }
}

void Amoeba::PrintDescendants(int level){
	Amoeba *ptr = myYoungestChild;
	while(ptr != NULL){
		for (int i = 0; i < level; ++i) {
			cout << "	";
		}
		cout << ptr->Name() << endl;
		ptr->PrintDescendants(level + 1);
		ptr = ptr->myOlderSibling;
	}
}