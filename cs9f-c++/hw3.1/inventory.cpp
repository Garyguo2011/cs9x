#include <iostream>
#include "inventory.h"

using namespace std;
bool QuantityComparer (Entry& a, Entry& b);

Inventory::Inventory() {}
void Inventory::Update(string item, int amount) {
	map<string,int>::iterator it;
	it = table.find(item);
	if (it == table.end()){
		table[item] = amount;
	} else {
		table[item] += amount;
	}
	cout << item << " :  " << table[item] << endl;
}

void Inventory::ListByName (){
	for(auto iter = table.begin(); iter != table.end(); iter++) {
		cout << iter->first << " :  " << iter->second << endl;
	}
}

void Inventory::ListByQuantity() {
	vector<Entry> v;
	for(auto iter = table.begin(); iter != table.end(); iter++) {
		v.push_back(*iter);
	}
	sort(v.begin(), v.end(), QuantityComparer);
	for(auto iter = v.begin(); iter != v.end(); iter++) {
		cout << iter->first << " :  " << iter->second << endl;	
	}
}

bool QuantityComparer (Entry& a, Entry& b){
	return a.second < b.second;
}
