#include <iostream>
#include "luhn.h"
using namespace std;

int main() {
	string number;
	char choice = '-';

	while (choice != 'e') {
		cout << "\n";
		cout << "Please enter option for Luhn Checksum Validation or exit (c, e): ";
		cin >> choice;
		
		if (choice == 'c') {
			cout << "Please enter a 16-digit number: ";
			cin.ignore();
			getline(cin, number);
			read_and_check(number);
		} else if (choice == 'e') {
			break;
		} 
	}
	return 0;
}