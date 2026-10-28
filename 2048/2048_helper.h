#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

int counter = 0;

void move_left(int board[][5], int numrows = 5)
{
	for (int r = 0; r < numrows; r++) {
		for (int c = 0; c < 5; c++) {
            if (c != (0 && 4)) { 
                if (board[r][c] != 0) {
                    for (int i = 0; i < c; i++) {
                        if (board[r][i] == 0) {
                            board[r][i] = board[r][c];
                            board[r][c] = 0;
                        }                    
                    }
                }
            }
		}
	}
}

void move_right(int board[][5], int numrows = 5)
{
    for (int r = 0; r < numrows; r++) {
		for (int c = 0; c < 5; c++) {
            if (c != (0 && 4)) { 
                if (board[r][c] != 0) {
                    for (int i = c + 1; i <= 4; i++) {
                        if (board[r][i] == 0) {
                            board[r][i] = board[r][c];
                            board[r][c] = 0;
                        }                    
                    }
                }
            }
		}
	}
}

void move_up(int board[][5], int numrows = 5)
{
    for (int r = 0; r < numrows; r++) {
		for (int c = 0; c < 5; c++) {
            if (r != (0 && 4)) { 
                if (board[r][c] != 0) {
                    for (int i = 0; i < r; i++) {
                        if (board[i][c] == 0) {
                            board[i][c] = board[r][c];
                            board[r][c] = 0;
                            break;
                        }                    
                    }
                }
            }
		}
	}
}

void move_down(int board[][5], int numrows = 5)
{
    for (int r = 0; r < numrows; r++) {
		for (int c = 0; c < 5; c++) {
            if (r != (0 && 4)) { 
                if (board[r][c] != 0) {
                    for (int i = 4; i > r; i--) {
                        if (board[i][c] == 0) {
                            board[i][c] = board[r][c];
                            board[r][c] = 0;
                            break;
                        }                    
                    }
                }
            }
		}
	}
}

void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows = 5)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
}