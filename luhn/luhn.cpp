#include <iostream>
#include "luhn.h"
using namespace std;

int read_and_check(int number) {
    cout << "Please enter a 16-digit number: ";
    cin >> number;

    return number;
}
