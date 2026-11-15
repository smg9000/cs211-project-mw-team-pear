#pragma once

// Declared functions for moving left, right, up, and down.
void move_left(int board[][5], int numrows, int numcols);
void move_right(int board[][5], int numrows, int numcols);
void move_up(int board[][5],int numrows, int numcols);
void move_down(int board[][5], int numrows, int numcols);

// Declared functions for adding left, right, up, and down.
void add_left(int board[][5], int numrows, int numcols, int& score, int& previous_score);
void add_right(int board[][5], int numrows, int numcols, int& score, int& previous_score);
void add_up(int board[][5], int numrows, int numcols, int& score, int& previous_score);
void add_down(int board[][5], int numrows, int numcols, int& score, int& previous_score);

// Declared functions for printing board and inserting random.
void print_board(int board[][5], int numrows = 5);
void insert_random(int board[][5], int numrows = 5);