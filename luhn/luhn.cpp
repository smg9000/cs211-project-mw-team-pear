#include <iostream>
#include "luhn.h"
using namespace std;

int read_and_check(string number) {
    bool not_sixteen_digits = false; // Track if there number is not exactly equal to 16 digits.
    bool has_nondigit = false; // Track if there is atleast one non digit (letters, symbols, punctuation, etc) in the given number.
	bool has_space = false; // Track if there is atleast one space in the given number.

    // For loop with nested if statements check for these conditions.
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

   // If number has none of these format issues, then proceed with checking if it is a valid Luhn checksum.
   // Else, print out reason on format issues of number.
   if (not_sixteen_digits == false && has_nondigit == false && has_space == false) {
    luhn_checksum_validation(number);
   } else {
        if (not_sixteen_digits == true) {
            cout << "Number is not 16 digits long" << "\n";
        }
        if (has_nondigit == true) {
            cout << "Number includes a character that is not a digit" << "\n";
        }
        if (has_space == true) {
            cout << "Number includes a space" << "\n";
        }
   }
    return 0;
}

int luhn_checksum_validation(string number) {
    int temp = 0;
    int check_sum = 0;

    // For loop that consists of primary mathematical Luhn checksum validation.
    for (int i = number.length() - 1; i >= 0; i--) {
        temp = number[i] - '0';
        if ((i + 1) % 2 != 0) {
            temp *= 2;
            if (temp >= 10) {
                temp -= 9;
            }
        }
        check_sum += temp; // Add value of digit whether changed or unchanged to check sum variable.
    }

    // If check is evenly divisble by 10, it is a valid Luhn check sum, and if not, it is not a valid Luhn check sum.
    if (check_sum % 10 == 0) {
        cout << "Number is a valid Luhn check sum" << "\n";
    } else {
        cout << "Number is not a valid Luhn check sum" << "\n";
    }
    return 0;
}