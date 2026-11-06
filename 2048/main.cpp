#include <iostream>
#include "2048_helper.h"
using namespace std;

int main()
{
	int num_rows = 5;
	int num_cols = 5;
	int board[5][5] = {
		{0, 4, 2, 4, 0},
		{0, 0, 0, 0, 0},
		{2, 0, 2, 0, 2},
		{0, 0, 2, 0, 0},
		{2, 2, 2, 2, 2},
	};
	//while getch == x loop for up down left right

	cout << "Initial Board : [5x5] :" << endl;
	print_board(board);

	char choice = 'u';	//initialized
	while (choice != 'e')
	{

		cout << "Please enter choice: (u,d,l,r,e) for UP, DOWN, LEFT, RIGHT, Exit: " << endl;
		cout << "Choice: ";
		cin >> choice;

		if (choice == 'u')
			move_up(board, num_rows, num_cols);
		else if (choice == 'd')
			move_down(board, num_rows, num_cols);
		else if (choice == 'l')
			move_left(board, num_rows, num_cols);
		else if (choice == 'r')
			move_right(board, num_rows, num_cols);

		//insert_random(board, size);
		print_board(board);

	}

	return 0;
}