#include <iostream>
#include "luhn.h"
using namespace std;

int read_and_check(string number) {
    bool not_sixteen_digits = false;
    bool has_nondigit = false;
	bool has_space = false;

    for (int i = 0; i < number.length(); i++) {
        if (number.length() != 16) {
            not_sixteen_digits = true;
        }
        if ((number[i] < '0' || number[i] > '9') && number[i] != ' ') {
            has_nondigit = true;
        }
        if (number[i] == ' ') {
            has_space = true;
        }
    }

    cout << not_sixteen_digits << "\n";
    cout << has_nondigit << "\n";
    cout << has_space << "\n";

    return 0;
}
