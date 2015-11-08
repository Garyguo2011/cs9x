#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    int total = 0;
    int subtotal = 0;
    int input = 0;
    int continueZeros = 0;

    while(!cin.eof()){
        cin >> input;
        if (input == 0) {
            continueZeros++;
            if (continueZeros == 2) {
                cout << "Total " << total << endl;
                break;
            } else {
                cout << "Subtotal " << subtotal << endl;
                subtotal = 0;
            }
        } else {
            subtotal += input;
            total += input;
            continueZeros = 0;
        }
    }
}
