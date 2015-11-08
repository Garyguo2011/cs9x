#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


#include "inventory.h"
using namespace std;

Inventory* inventory;

void InterpretCommands (istream&);
void InterpretUpdate (istream&);
void InterpretList (istream&);
void InterpretBatch (istream&);
void InterpretQuit (istream&);

void InterpretCommands (istream& cmds) {
  string line, lineInWord;
  while (!getline(cmds, line).eof()) {
    istringstream lineIn (line);
    if (!(lineIn >> lineInWord)) {
      cerr << "Read Fails" << endl;
    } else if (lineInWord=="update") {
      InterpretUpdate (lineIn);
    } else if (lineInWord=="list") {
      InterpretList (lineIn);
    } else if (lineInWord=="batch") {
      InterpretBatch (lineIn);
    } else if (lineInWord=="quit") {
      InterpretQuit (lineIn);
    } else { 
      cerr << "Unrecognizable command word." << endl; 
    }
  }
}

void InterpretUpdate(istream& lineIn){
  string name;
  int number;
  if(!(lineIn >> name) || !(lineIn >> number) || !(lineIn.eof())){
    cerr << "Unrecognizable command args." << endl;
    return;
  }
  inventory->Update(name, number);
}

void InterpretList(istream& lineIn){
  string target;
  if(!(lineIn >> target)){
    cerr << "Unrecognizable command args." << endl;
    return;
  }
  if(target == "names") {
    inventory->ListByName();
  } else if (target == "quantities") {
    inventory->ListByQuantity();
  } else {
    cerr << "Unrecognizable command word." << endl;
    return;
  }
}

void InterpretBatch (istream& lineIn) {
  string filename;
  if (!(lineIn >> filename) || !lineIn.eof()) {
    cerr << "Unrecognizable command args." << endl;
    return;
  }
  fstream fin(filename, ios::in);
  if(!fin.is_open()){
    cerr << "File does not exist!" << endl;
    return;
  }
  InterpretCommands (fin);
  InterpretCommands (cin);
}

void InterpretQuit(istream& lineIn){
  if(!lineIn.eof()){
    cerr << "Unrecognizable command args." << endl;
    return;
  }
  exit(0);
}

int main ( ) {
  inventory = new Inventory();
  InterpretCommands (cin);
  return 0;
}