#pragma once

#include <SFML/Graphics.hpp>


namespace memoryGame {


	
	bool isSpriteClicked(sf::Sprite s, sf::Mouse::Button b, sf::RenderWindow& w);
	sf::Vector2i getMousePosition(sf::RenderWindow& w);
	bool isSpriteReleased(sf::Event e, sf::Mouse::Button b, sf::RenderWindow& w,sf::Sprite s);


}