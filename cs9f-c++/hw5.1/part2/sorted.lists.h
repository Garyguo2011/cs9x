using namespace std;

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <cassert>

template <class NODETYPE> class SortedList;
template <class NODETYPE> class SortedListIterator;




/* ------ ListNode class definition ------*/


template <class NODETYPE>
class ListNode {
	friend class SortedList<NODETYPE>;
  friend class SortedListIterator<NODETYPE>;
public:
	ListNode (const NODETYPE &);
	NODETYPE Info ();
private:
	NODETYPE myInfo;
	ListNode* myNext;
};

/* ------ ListNode member functions ------*/


template <class NODETYPE>
ListNode<NODETYPE>::ListNode (const NODETYPE &value) {
	myInfo = value;
	myNext = 0;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::Info () {
	return myInfo;
}


/* ------ SortedList class definition ------*/

template <class NODETYPE>
class SortedList {
  friend class SortedListIterator<NODETYPE>;
public:
	SortedList ();
	~SortedList ();
	SortedList (const SortedList <NODETYPE> &);
  SortedList<NODETYPE> & operator = (const SortedList<NODETYPE> &);
	void Insert (const NODETYPE &);
	bool IsEmpty ();
private:
	ListNode <NODETYPE>* myFirst;
};

/* ------ SortedList member functions ------*/

template <class NODETYPE>
SortedList<NODETYPE>::SortedList() {	// constructor
	myFirst = 0;
}

template <class NODETYPE>
SortedList<NODETYPE>::~SortedList () {	// destructor
	if (!IsEmpty ()) {
		cerr << "*** in destructor, destroying: ";
		ListNode <NODETYPE>* current = myFirst;
		ListNode <NODETYPE>* temp;
		while (current != 0) {
			cerr << " " << current->myInfo;
			temp = current;
			current = current->myNext;
			delete temp;
		}
		cerr << endl;
	}
}

template <class NODETYPE>
SortedList<NODETYPE>::SortedList(const SortedList<NODETYPE> & list) {	// copy constructor
	cerr << "*** in copy constructor" << endl;
	ListNode <NODETYPE>* listCurrent = list.myFirst;
	ListNode <NODETYPE>* newCurrent = 0;
	while (listCurrent != 0) {
		ListNode <NODETYPE> *temp 
		  = new ListNode <NODETYPE> (listCurrent->Info ());
		if (newCurrent == 0) {
			myFirst = temp;
			newCurrent = myFirst;
		} else {
			newCurrent->myNext = temp;
			newCurrent = temp;
		}
		listCurrent = listCurrent->myNext;
	}
}

template <class NODETYPE>
void SortedList<NODETYPE>::Insert( const NODETYPE & value) {	// Insert
	ListNode <NODETYPE> *toInsert 
	  = new ListNode <NODETYPE> (value);
	if (IsEmpty ()) {
		myFirst = toInsert;
	} else if (value < myFirst->Info ()) {
		toInsert->myNext = myFirst;
		myFirst = toInsert;
	} else {
		ListNode <NODETYPE> *temp = myFirst;
		for (temp = myFirst; 
			  temp->myNext != 0 && temp->myNext->Info () < value; 
			  temp = temp->myNext) {
		}
		toInsert->myNext = temp->myNext;
		temp->myNext = toInsert;
	}
}

template <class NODETYPE>
bool SortedList<NODETYPE>::IsEmpty() {	// IsEmpty
	return myFirst == 0;
}

template <class NODETYPE>
SortedList<NODETYPE> & SortedList<NODETYPE>::operator = (const SortedList<NODETYPE> & value) {
  if (this == &value) {
    cerr << "*** Assigning a list to itself." << endl;
    return *this;
  }
  
  cerr << "*** in operator=, destroying:";
  ListNode<NODETYPE> *toDel = this->myFirst;
  
  // destroy all existing entries
  while (toDel != 0) {
    ListNode<NODETYPE> *next = toDel->myNext;
    cout << " " << toDel->Info();
    delete toDel;
    toDel = next;
  }
  cout << endl;
  
  ListNode <NODETYPE>* listCurrent = value.myFirst;
	ListNode <NODETYPE>* newCurrent = 0;
	while (listCurrent != 0) {
		ListNode <NODETYPE> *temp 
		  = new ListNode <NODETYPE> (listCurrent->Info ());
		if (newCurrent == 0) {
			myFirst = temp;
			newCurrent = myFirst;
		} else {
			newCurrent->myNext = temp;
			newCurrent = temp;
		}
		listCurrent = listCurrent->myNext;
	}
  return *this;
}


/* ------ SortedListIterator class definition (Part 3) ------ */

template <class NODETYPE>
class SortedListIterator {
public:
	SortedListIterator ();
  SortedListIterator(const SortedList<NODETYPE> &);
	bool MoreRemain ();
  NODETYPE Next();
private:
	SortedList <NODETYPE>* myList;
};

/* ------ SortedListIterator member functions (Part 3) ------ */

template <class NODETYPE>
SortedListIterator<NODETYPE>::SortedListIterator() {
  myList = new SortedList<NODETYPE>();
}

template <class NODETYPE>
SortedListIterator<NODETYPE>::SortedListIterator(const SortedList<NODETYPE> & val) {
  myList = new SortedList<NODETYPE>();

  ListNode <NODETYPE>* listCurrent = val.myFirst;
	ListNode <NODETYPE>* newCurrent = 0;
	while (listCurrent != 0) {
		ListNode <NODETYPE> *temp 
		  = new ListNode <NODETYPE> (listCurrent->Info ());
		if (newCurrent == 0) {
			myList->myFirst = temp;
			newCurrent = myList->myFirst;
		} else {
			newCurrent->myNext = temp;
			newCurrent = temp;
		}
		listCurrent = listCurrent->myNext;
	}
}

template <class NODETYPE>
bool SortedListIterator<NODETYPE>::MoreRemain() {
  return !(myList->IsEmpty());
}

template <class NODETYPE>
NODETYPE SortedListIterator<NODETYPE>::Next() {
  if (myList->IsEmpty()) {
    return 0;
  } else {
    ListNode<NODETYPE> *rtn = myList->myFirst;
    myList->myFirst = rtn->myNext;
    return rtn->Info();
  }
}

#endif
