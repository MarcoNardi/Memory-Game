#include "InputManager.h"


namespace memoryGame {
	bool isSpriteClicked(sf::Sprite s, sf::Mouse::Button b, sf::RenderWindow & w)
	{

		if (sf::Mouse::isButtonPressed(b)) {
			if (s.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(w))) {
				return true;
			}
		}
		return false;
	}

	sf::Vector2i getMousePosition(sf::RenderWindow & w)
	{
		return sf::Mouse::getPosition(w);
	}

	bool isSpriteReleased(sf::Event e, sf::Mouse::Button b, sf::RenderWindow & w, sf::Sprite s)
	{
		if (sf::Event::MouseButtonReleased == e.type) {
			if (e.mouseButton.button == b) {
				if (s.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(w))) {
					return true;
				}
			}
		}
		return false;
	}


}