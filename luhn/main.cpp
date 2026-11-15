#include <iostream>
#include "luhn.h"
using namespace std;

int main() {
	string number;
	char choice;

	while (choice != 'e') {
		cout << "\n";
		cout << "-------------------------------------------------------------------" << "\n";
		cout << "Please enter option for Luhn Checksum Validation or exit (c, e): ";
		cin >> choice;
		
		if (choice == 'c') {
			cout << "Please enter a 16-digit number: ";
			cin.ignore(); // Ignores previous "enter key" that skips the ability for user to input number
			getline(cin, number); // Regular cin drops digits after the space. This function includes those digits so that no digits are lost.
			read_and_check(number); // Initial function to check if format of number is correct.
		} else if (choice == 'e') {
			break;
		} 
	}
	return 0;
}