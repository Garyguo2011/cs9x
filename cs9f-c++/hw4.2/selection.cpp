#include <iostream>
#include "dll.h"

int main () {
    const int N = 8;
    const int K = 2;
    DLLnode *list = 0;
    for (int j=N; j>0; j--) {
	DLLnode *newGuy = new DLLnode (j);
	// you fill this in
    }
    list->Print ();
    while (!list->LengthIs1 ()) {
	for (int j=0; j<K; j++) {
	    list = list->Next ();
	}
	// you fill this in
    }
    cout << "Only one person remains: ";
    list->Print ();
    return 0;
}

