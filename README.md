CS211 Group Project – Team Pear 

Course: CS211 – Programming 

Session: MW 

Group: Team Pear 

Programming Language: C++ 

GitHub Repository: https://github.com/smg9000/cs211-project-mw-team-pear 

 

1. Team Members 

 

Team Member 1: Cameron 

- GitHub Username: Blackpeary819840104 

-student ID: g227b276 

 

Team Member 2: Reagan  

-GitHub Username: Techen77 

-student ID: k748c493 

 

Team Member 3: Zach  

-GitHub Username: smg9000 

-student ID: k894m447 

 

2. Project Overview 

This project includes two independent programs developed in C++ by Team Pear for CS211. The first program is a modified version of the 2048 puzzle game that uses a 5×5 playing board. The second program is a Luhn Checksum Validator that determines if a 16-digit number satisfies the Luhn checksum algorithm or not. 

Both programs contain fundamental programming concepts, including functions, loops, conditional statements, arrays, strings, input validation, and problem-solving techniques. Each program contains its own main function and operates independently. 

 

3. Program One – 2048 Game 

Program Description 

The 2048 game is a puzzle game where the player moves numbered tiles around a 5×5 board. The objective is to combine tiles of equal value until a tile with the value of 2048 is created. When two tiles containing the same number collide during a valid move, they merge into one tile with twice the original value. For example, two tiles containing 4 combine to create a tile containing 8. Each successful merge increases the player’s score. The program uses the SFML graphics library to create a graphical interface that displays the playing board, numbered tiles, current score, and game status. 

Game Features 

The game starts with two randomly generated tiles placed on the board. These tiles contain either the number 2 or the number 4. The player can move the tiles upward, downward, left, or right using the keyboard. After a successful move that changes the board, the program generates another random tile, provided the game has not reached a stopping condition. Matching tiles combine, and the score increases according to the values of the merged tiles. The program also includes win detection, game-over detection, a restart option, and the ability to save and load game progress. Once the player reaches 2048, freeplay mode can be enabled to continue playing past the number 2048. 

Game Controls 

The game uses these keyboard controls: 

- Up Arrow or 2: Moves tiles upward. 

- Down Arrow or 4: Moves tiles downward. 

- Left Arrow or 1: Moves tiles to the left. 

- Right Arrow or 3: Moves tiles to the right. 

- S: Saves the current game. 

- O: Opens a previously saved game. 

- R: Restarts the game. 

- F: Enables freeplay after winning. 

- Escape: Closes the game. 

 

Saving and Loading 

The 2048 program includes a save and load feature that allows the player to preserve game progress of a game left unfinished. When the player presses S, the program writes the current score and the values of the 5×5 board to a text file named save.txt, located inside the 2048 folder. The first line of the file contains the player’s score. The following five lines contain the values of the board, with five numbers representing each row. When the player presses O, the program reads the saved information and restores the score and board values. The program uses relative file paths, so the 2048 folder has to be accessible from the program’s working directory. 

Important Functions 

-The program uses several helper functions to organize the game logic. 

-The move_up() function moves and merges tiles toward the top of the board. 

-The move_down() function moves and merges tiles toward the bottom of the board. 

-The move_left() function moves and merges tiles toward the left side of the board. 

-The move_right() function moves and merges tiles toward the right side of the board. 

-The insert_random() function spawns a new tile and places it in an available position. 

-The board_changed() function determines whether the board changed after a movement command. 

-The check_win() function checks if a tile with 2048 has been created. 

-The check_game_over() function checks if any legal moves are available. 

-The print_board() function displays the board values in the console. 

-These functions separate the board operations from the graphical interface and make the program easier to organize and maintain. 

Compiling and Running the 2048 Game 

The 2048 game requires a C++ compiler and the SFML graphics library. The supplied arial.ttf font file has to also be available. A common compilation command for a Linux environment with SFML 2.x installed is: 

g++ -std=c++17 2048/main.cpp -o game2048 -lsfml-graphics -lsfml-window -lsfml-system 

 

The program can then be started using: 

./game2048 

All of these commands have been verified against the team’s specific development environment. When using Windows or Visual Studio Code, the compiler and SFML library paths have to be configured for the installed version of SFML. The program should be launched from the repository’s root directory so that it can locate the required font and save files. 

 

4. Program Two – Luhn Checksum Validator 

Program Description 

The Luhn Checksum Validator is a console-based C++ program that checks a 16-digit number to see if it satisfies the Luhn checksum algorithm. The Luhn algorithm is commonly used to detect errors in identification numbers, including payment card numbers. It works by performing a series of calculations on the digits of a number and figuring out if the resulting checksum is divisible by 10. The program allows the user to enter a number, checks whether the input meets the required format, performs the checksum calculation, and displays the result. A number passing the Luhn checksum doesn’t always mean that the number belongs to a real or active account. 

Program Features 

The program uses a menu that allows the user to check a number or exit. When the program starts, the user can enter c to check a number or e to exit the program. If the user selects c, the program asks the user for a 16-digit number. Before performing the checksum calculation, the program checks the input to make sure that it contains exactly 16 digits and does not contain spaces or nonnumeric characters. If the input doesn’t meet the requirements, the program displays the appropriate error information. If the input meets the requirements, the program performs the Luhn checksum calculation and reports if the number passes or fails the validation. The user can continue checking additional numbers until choosing to exit. 

Luhn Algorithm 

The Luhn checksum algorithm follows a series of mathematical steps. First, the program starts with the rightmost digit of the number and moves toward the left. Every second digit is doubled. If doubling a digit produces a number greater than 9, the program subtracts 9 from that result. The adjusted values are then added together with the digits that were not doubled. After calculating the total, the program checks whether the sum is divisible by 10. If the remainder is zero, the number passes the Luhn checksum validation. If the remainder is not zero, the number fails the validation. 

Important Functions 

-The main() function controls the program’s menu and handles the user’s selections. 

-The read_and_check() function checks the entered number to determine whether it meets the required input format. 

-The luhn_checksum_validation() function performs the checksum calculation and reports the validation result. 

-Separating these operations into functions makes the program easier to read and allows each function to handle a specific responsibility. 

Compiling and Running the Luhn Validator 

The Luhn program requires a C++ compiler but does not require an external graphics library. 

From the repository’s root directory, the program can be compiled using: 

g++ -std=c++17 luhn/main.cpp luhn/luhn.cpp -o luhn_validator 

 

On Linux or macOS, the compiled program can be executed using: 

./luhn_validator 

 

On Windows, the executable can be run using: 

.\luhn_validator.exe 

 

Once the program starts, the user follows the menu instructions to check a number or exit. 

 

5. Project File Organization 

-The project is divided into separate folders for the 2048 game and the Luhn Checksum Validator. 

-The 2048 folder contains main.cpp, 2048_helper.h, arial.ttf, and save.txt. 

-The main.cpp file controls the graphical interface, keyboard input, game initialization, and saving and loading operations. 

-The 2048_helper.h file contains the helper functions responsible for moving and merging tiles, generating random tiles, and checking game conditions. 

-The arial.ttf file provides the font used to display text in the graphical interface. 

-The save.txt file stores saved game information. 

-The Luhn folder contains main.cpp, luhn.cpp, and luhn.h. 

-The main.cpp file handles the menu and user interaction. 

-The luhn.cpp file contains the input-checking and checksum-validation functions. 

-The luhn.h file contains the function declarations used by the program. 

-The repository also includes a .vscode folder containing launch.json and tasks.json, which are used for development and debugging configuration in Visual Studio Code. 

-The Luhn program’s files were reviewed on the luhn-validation branch. Both programs should be included together in the submission. 

6. Program Design 

Both programs were developed using functions to separate different tasks and make the code more organized. 

The 2048 game separates the graphical interface from the operations performed on the playing board. The main function handles the game window, keyboard input, and display, while the helper functions perform tile movement, merging, random tile generation, and checks for winning or losing conditions. 

The Luhn Checksum Validator separates the menu, input checking, and mathematical calculations into different functions. This makes it possible for the program to check if the user’s input meets the requirements before attempting the checksum calculation. Both programs show how dividing a larger problem into smaller functions can improve readability and simplify the development process. 

 

7. Known Limitations 

2048 Game 

The 2048 game requires the SFML graphics library and the appropriate font resource to display the graphical interface correctly. The program uses relative file paths for its font and save file, meaning that the expected folder structure must be maintained. The current loading function restores the saved board and score but does not independently recalculate every game-state flag after loading. The program also expects saved data to follow the correct format. Incomplete or incorrectly formatted save files are not fully handled. 

Luhn Checksum Validator 

The Luhn Checksum Validator is designed specifically for 16-digit numbers. The program rejects input containing spaces, letters, or other nonnumeric characters. The program only determines whether a number satisfies the Luhn checksum algorithm. It doesn’t tell you if an account exists, a payment card is active, or if a number is associated with a specific financial institution. 

 

8. Conclusion 

This project exhibits the application of fundamental C++ programming concepts through two different programs. The 2048 game combines arrays, functions, conditional statements, random number generation, file operations, and graphical rendering to create an interactive puzzle game. It explained how individual functions can work together to manage game logic, user input, and program state. The Luhn Checksum Validator demonstrates the use of strings, loops, input validation, functions, and mathematical operations to solve a practical validation problem. Together, these programs show the importance of program organization, logical problem-solving, and the use of functions to develop software that is easier to understand and maintain. 

CS211 – Team Pear – MW Session 
