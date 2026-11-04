#include <iostream> 

#include "2048_helper.h" 

#include <SFML/Graphics.hpp> 

#include <fstream> 

#include <vector> 

 

using namespace std; 

 

int main() 

{ 

    int size = 5; 

 

    // Initialize the 5x5 board 

    int board[5][5] = { 

        {0, 0, 0, 0, 0}, 

        {0, 0, 0, 0, 0}, 

        {0, 0, 0, 0, 0}, 

        {0, 0, 0, 0, 0}, 

        {0, 0, 0, 0, 0} 

    }; 

 

    // Initialize random numbers 

    std::random_device rd; 

    srand(rd()); 

 

    // Insert two starting tiles 

    insert_random(board, size); 

    insert_random(board, size); 

 

    cout << "Initial Board:" << endl; 

    print_board(board, size); 

 

    // Create fullscreen game window 

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode(); 
    sf::RenderWindow window(desktopMode, "2048+", sf::Style::Fullscreen); 
    window.setFramerateLimit(60); 
    // Load the font 
    sf::Font font; 
    if (!font.loadFromFile("2048/arial.ttf")) 
    { 

        cerr << "Could not load arial.ttf. " 

             << "Put it in the working directory." << endl; 

    } 

 

    // Board measurements 

    float cellSize = 100.f; 

    float gap = 10.f; 

 

    float boardWidth = 5 * cellSize + 4 * gap; 

 

    float startX = (desktopMode.width - boardWidth) / 2.f; 

    float startY = (desktopMode.height - boardWidth) / 2.f; 

 

    sf::RectangleShape rectangle( 

        sf::Vector2f(cellSize, cellSize) 

    ); 

 

    bool won = false; 

    bool gameOver = false; 

 

    // Main game loop 

    while (window.isOpen()) 

    { 

        sf::Event event; 

 

        while (window.pollEvent(event)) 

        { 

            // Close the window 

            if (event.type == sf::Event::Closed) 

                window.close(); 

 

            // Check keyboard input 

            if (event.type == sf::Event::KeyPressed) 

            { 

                if (event.key.code == sf::Keyboard::Escape) 

                    window.close(); 

 

                // Restart the game 

                if (event.key.code == sf::Keyboard::R) 

                { 

                    for (int r = 0; r < size; r++) 

                    { 

                        for (int c = 0; c < 5; c++) 

                            board[r][c] = 0; 

                    } 

 

                    score = 0; 

                    won = false; 

                    gameOver = false; 

 

                    insert_random(board, size); 

                    insert_random(board, size); 

                } 

 

                // Allow movement while the game is active 

                else if (won == false && gameOver == false) 

                { 

                    // Save the old board 

                    int old_board[5][5]; 

 

                    for (int r = 0; r < size; r++) 

                    { 

                        for (int c = 0; c < 5; c++) 

                            old_board[r][c] = board[r][c]; 

                    } 

 

                    bool moved = false; 

 

                    // Move up 

                    if (event.key.code == sf::Keyboard::Up) 

                    { 

                        move_up(board, size); 

                        moved = true; 

                    } 

 

                    // Move down 

                    else if (event.key.code == sf::Keyboard::Down) 

                    { 

                        move_down(board, size); 

                        moved = true; 

                    } 

 

                    // Move right 

                    else if (event.key.code == sf::Keyboard::Right) 

                    { 

                        move_right(board, size); 

                        moved = true; 

                    } 

 

                    // Move left 

                    else if (event.key.code == sf::Keyboard::Left) 

                    { 

                        move_left(board, size); 

                        moved = true; 

                    } 

 

                    // Check whether movement occurred 

                    if (moved == true) 

                    { 

                        // Check for winning before adding a tile 

                        won = check_win(board, size); 

 

                        if (board_changed(board, old_board, size) 

                            && won == false) 

                        { 

                            insert_random(board, size); 

 

                            cout << "Updated Board:" << endl; 

                            print_board(board, size); 

                        } 

 

                        if (won == false) 

                            gameOver = check_game_over(board, size); 

                    } 

                } 

            } 

        } 

 

        // Clear the screen 

        window.clear(sf::Color(20, 20, 20)); 

 

        // Display game title 

        sf::Text title; 

 

        title.setFont(font); 

        title.setString("2048+"); 

        title.setCharacterSize(50); 

        title.setFillColor(sf::Color::White); 

        title.setPosition(startX, startY - 100); 

 

        window.draw(title); 

 

        // Display score 

        sf::Text scoreText; 

 

        scoreText.setFont(font); 

        scoreText.setString("Score: " + to_string(score)); 

        scoreText.setCharacterSize(25); 

        scoreText.setFillColor(sf::Color::White); 

        scoreText.setPosition(startX + 300, startY - 75); 

 

        window.draw(scoreText); 

 

        // Draw the 5x5 game board 

        for (int r = 0; r < size; r++) 

        { 

            for (int c = 0; c < 5; c++) 

            { 

                rectangle.setPosition( 

                    startX + c * (cellSize + gap), 

                    startY + r * (cellSize + gap) 

                ); 

 

                // Set tile colors 

                if (board[r][c] == 0) 

                    rectangle.setFillColor( 

                        sf::Color(100, 100, 100) 

                    ); 

 

                else if (board[r][c] == 2) 

                    rectangle.setFillColor( 

                        sf::Color(238, 228, 218) 

                    ); 

 

                else if (board[r][c] == 4) 

                    rectangle.setFillColor( 

                        sf::Color(237, 224, 200) 

                    ); 

 

                else if (board[r][c] == 8) 

                    rectangle.setFillColor( 

                        sf::Color(242, 177, 121) 

                    ); 

 

                else if (board[r][c] == 16) 

                    rectangle.setFillColor( 

                        sf::Color(245, 149, 99) 

                    ); 

 

                else if (board[r][c] == 32) 

                    rectangle.setFillColor( 

                        sf::Color(246, 124, 95) 

                    ); 

 

                else if (board[r][c] == 64) 

                    rectangle.setFillColor( 

                        sf::Color(246, 94, 59) 

                    ); 

 

                else 

                    rectangle.setFillColor( 

                        sf::Color(237, 207, 114) 

                    ); 

 

                window.draw(rectangle); 

 

                // Display tile number 

                if (board[r][c] != 0) 

                { 

                    sf::Text number; 

 

                    number.setFont(font); 

                    number.setString( 

                        to_string(board[r][c]) 

                    ); 

 

                    number.setCharacterSize(30); 

                    number.setFillColor(sf::Color::Black); 

 

                    // Center number inside rectangle 

                    sf::FloatRect bounds = 

                        number.getLocalBounds(); 

 

                    number.setOrigin( 

                        bounds.left + bounds.width / 2.f, 

                        bounds.top + bounds.height / 2.f 

                    ); 

 

                    number.setPosition( 

                        startX + c * (cellSize + gap) 

                            + cellSize / 2.f, 

 

                        startY + r * (cellSize + gap) 

                            + cellSize / 2.f 

                    ); 

 

                    window.draw(number); 

                } 

            } 

        } 

 

        // Display win or game-over message 

        if (won == true || gameOver == true) 

        { 

            sf::Text message; 

 

            message.setFont(font); 

 

            if (won == true) 

            { 

                message.setString( 

                    "YOU WIN! Press R to restart" 

                ); 

 

                message.setFillColor(sf::Color::Green); 

            } 

            else 

            { 

                message.setString( 

                    "GAME OVER! Press R to restart" 

                ); 

 

                message.setFillColor(sf::Color::Red); 

            } 

 

            message.setCharacterSize(28); 

            message.setPosition( 

                startX, startY + 560 

            ); 

 

            window.draw(message); 

        } 

 

        // Display everything 

        window.display(); 

    } 

 

    return 0; 

} 