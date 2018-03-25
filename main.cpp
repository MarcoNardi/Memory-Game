#include "Game.h"

int main() {
	memoryGame::Game game;
	game.run();
	return 0;
}













/*
int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Memory!", sf::Style::Default);
	
	sf::RectangleShape rect;
	rect.setSize({ 50, 50 });
	rect.setFillColor(sf::Color::Green);
	
	
	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) {
				window.close();
			}
			if (e.type == sf::Event::MouseButtonPressed) {
				if (e.mouseButton.button == sf::Mouse::Button::Left) {
					if (rect.getGlobalBounds().contains(sf::Vector2f(e.mouseButton.x, e.mouseButton.y))) {
						std::cout << "premuto" << std::endl;
						
					}
				}
			}

		}
		window.clear();
		window.draw(rect);
		window.display();

	}

	return 0;



}
*/