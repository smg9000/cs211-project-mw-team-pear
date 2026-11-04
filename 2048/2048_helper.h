#include <iostream> 

#include <random> 

#include <iomanip> 

#include <cstdlib> 

 

using namespace std; 

 

int score = 0; 

 

// Move numbers together and merge matching numbers 

void merge_line(int line[5]) 

{ 

    int temp[5] = {0, 0, 0, 0, 0}; 

    int count = 0; 

 

    // Move nonzero numbers together 

    for (int i = 0; i < 5; i++) 

    { 

        if (line[i] != 0) 

        { 

            temp[count] = line[i]; 

            count++; 

        } 

    } 

 

    int position = 0; 

 

    // Merge matching numbers 

    for (int i = 0; i < count; i++) 

    { 

        if (i + 1 < count && temp[i] == temp[i + 1]) 

        { 

            line[position] = temp[i] * 2; 

 

            // Add merged number to score 

            score = score + line[position]; 

 

            i++; 

        } 

        else 

        { 

            line[position] = temp[i]; 

        } 

 

        position++; 

    } 

 

    // Fill remaining spaces with zeros 

    while (position < 5) 

    { 

        line[position] = 0; 

        position++; 

    } 

} 

 

 

// Move all numbers left 

void move_left(int board[][5], int numrows = 5) 

{ 

    for (int r = 0; r < numrows; r++) 

    { 

        int line[5]; 

 

        // Copy row into temporary array 

        for (int c = 0; c < 5; c++) 

        { 

            line[c] = board[r][c]; 

        } 

 

        // Move and merge numbers 

        merge_line(line); 

 

        // Copy numbers back into board 

        for (int c = 0; c < 5; c++) 

        { 

            board[r][c] = line[c]; 

        } 

    } 

} 

 

 

// Move all numbers right 

void move_right(int board[][5], int numrows = 5) 

{ 

    for (int r = 0; r < numrows; r++) 

    { 

        int line[5]; 

 

        // Copy row in reverse order 

        for (int c = 0; c < 5; c++) 

        { 

            line[c] = board[r][4 - c]; 

        } 

 

        // Move and merge numbers 

        merge_line(line); 

 

        // Copy numbers back in reverse order 

        for (int c = 0; c < 5; c++) 

        { 

            board[r][4 - c] = line[c]; 

        } 

    } 

} 

 

 

// Move all numbers up 

void move_up(int board[][5], int numrows = 5) 

{ 

    for (int c = 0; c < 5; c++) 

    { 

        int line[5]; 

 

        // Copy column into temporary array 

        for (int r = 0; r < numrows; r++) 

        { 

            line[r] = board[r][c]; 

        } 

 

        // Move and merge numbers 

        merge_line(line); 

 

        // Copy numbers back into board 

        for (int r = 0; r < numrows; r++) 

        { 

            board[r][c] = line[r]; 

        } 

    } 

} 

 

 

// Move all numbers down 

void move_down(int board[][5], int numrows = 5) 

{ 

    for (int c = 0; c < 5; c++) 

    { 

        int line[5]; 

 

        // Copy column in reverse order 

        for (int r = 0; r < numrows; r++) 

        { 

            line[r] = board[numrows - 1 - r][c]; 

        } 

 

        // Move and merge numbers 

        merge_line(line); 

 

        // Copy numbers back in reverse order 

        for (int r = 0; r < numrows; r++) 

        { 

            board[numrows - 1 - r][c] = line[r]; 

        } 

    } 

} 

 

 

// Print the board in the console 

void print_board(int board[][5], int numrows = 5) 

{ 

    cout << endl; 

 

    for (int r = 0; r < numrows; r++) 

    { 

        for (int c = 0; c < 5; c++) 

        { 

            cout << setw(6) << board[r][c]; 

        } 

 

        cout << endl; 

    } 

 

    cout << endl; 

} 

 

 

// Insert a random 2 or 4 into an empty position 

void insert_random(int board[][5], int numrows = 5) 

{ 

    int empty_count = 0; 

 

    // Count empty spaces 

    for (int r = 0; r < numrows; r++) 

    { 

        for (int c = 0; c < 5; c++) 

        { 

            if (board[r][c] == 0) 

            { 

                empty_count++; 

            } 

        } 

    } 

 

    // Only insert if empty spaces exist 

    if (empty_count > 0) 

    { 

        int selected = rand() % empty_count; 

        int current = 0; 

 

        bool inserted = false; 

 

        for (int r = 0; r < numrows; r++) 

        { 

            for (int c = 0; c < 5; c++) 

            { 

                if (board[r][c] == 0 && inserted == false) 

                { 

                    if (current == selected) 

                    { 

                        // Randomly insert 2 or 4 

                        if (rand() % 10 == 0) 

                        { 

                            board[r][c] = 4; 

                        } 

                        else 

                        { 

                            board[r][c] = 2; 

                        } 

 

                        inserted = true; 

                    } 

 

                    current++; 

                } 

            } 

        } 

    } 

} 

 

 

// Check if the board changed after movement 

bool board_changed(int board[][5], int old_board[][5], 

                   int numrows = 5) 

{ 

    for (int r = 0; r < numrows; r++) 

    { 

        for (int c = 0; c < 5; c++) 

        { 

            if (board[r][c] != old_board[r][c]) 

            { 

                return true; 

            } 

        } 

    } 

 

    return false; 

} 

 

 

// Check if the player reached 2048 

bool check_win(int board[][5], int numrows = 5) 

{ 

    for (int r = 0; r < numrows; r++) 

    { 

        for (int c = 0; c < 5; c++) 

        { 

            if (board[r][c] >= 2048) 

            { 

                return true; 

            } 

        } 

    } 

 

    return false; 

} 

 

 

// Check if the player has any moves remaining 

bool check_game_over(int board[][5], int numrows = 5) 

{ 

    for (int r = 0; r < numrows; r++) 

    { 

        for (int c = 0; c < 5; c++) 

        { 

            // Check for empty spaces 

            if (board[r][c] == 0) 

            { 

                return false; 

            } 

 

            // Check number below 

            if (r + 1 < numrows) 

            { 

                if (board[r][c] == board[r + 1][c]) 

                { 

                    return false; 

                } 

            } 

 

            // Check number to the right 

            if (c + 1 < 5) 

            { 

                if (board[r][c] == board[r][c + 1]) 

                { 

                    return false; 

                } 

            } 

        } 

    } 

 

    return true; 

} 