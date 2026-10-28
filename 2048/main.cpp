#include <iostream>
#include "2048_helper.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	// int size = 5;
	// int board[5][5] = {
	// 	{0, 4, 2, 4, 0},
	// 	{0, 0, 0, 0, 0},
	// 	{2, 0, 2, 0, 2},
	// 	{0, 0, 2, 0, 0},
	// 	{2, 2, 2, 2, 2},
	// };
	// //while getch == x loop for up down left right

	// cout << "Initial Board : [5x5] :" << endl;
	// print_board(board);

	// char choice = 'u';	//initialized
	// while (choice != 'e')
	// {

	// 	cout << "Please enter choice:{u,d,l,r,e} for UP, DOWN, LEFT, RIGHT, Exit: " << endl;
	// 	cout << "Choice: ";
	// 	cin >> choice;

	// 	if (choice == 'u')
	// 		move_up(board, size);
	// 	else if (choice == 'd')
	// 		move_down(board, size);
	// 	else if (choice == 'l')
	// 		move_left(board, size);
	// 	else if (choice == 'r')
	// 		move_right(board, size);

	// 	insert_random(board, size);
	// 	print_board(board);

	// }

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktopMode, "2048+", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    sf::Font font;
    if (!font.loadFromFile("cs211-project-mw-team-pear/2048/arial.ttf")) {
        std::cerr << "Error loading arial.ttf!\n";
    }
	sf::RectangleShape rectangle({100.f, 100.f});
	rectangle.setFillColor(sf::Color(150, 50, 250));
    while (window.isOpen()) {
        sf::Event event;
		
		
		
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) window.close();
                if (event.key.code == sf::Keyboard::Up) {
					if (rectangle.getPosition().y > 0){
						rectangle.move({0, -50.f});
					}
					
                }
				if (event.key.code == sf::Keyboard::Down) {
					if (rectangle.getPosition().y < desktopMode.height - rectangle.getSize().y){
						rectangle.move({0, 50.f});
					}
                }
				if (event.key.code == sf::Keyboard::Right) {
					if (rectangle.getPosition().x < desktopMode.width - rectangle.getSize().x){
						rectangle.move({50.f, 0});
					}
                }

                if (event.key.code == sf::Keyboard::Left) {
					if (rectangle.getPosition().x > 0){
						rectangle.move({-50.f, 0});
					}
                }
            }


            
            if (event.type == sf::Event::MouseButtonPressed) {
            
            }
        }

        window.clear(sf::Color(20, 20, 20));
		window.draw(rectangle);
        window.display();
    }

    return 0;
}


