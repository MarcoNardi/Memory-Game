#pragma once
#include <SFML\Graphics.hpp>
#include <string>

namespace memoryGame {

	class Player {
	private:
		int nrOfCopies = 0;//number of copies that the player has guessed
		bool isTurn = false;
		sf::Text text;
		sf::Color color;//color for highlighting
		sf::Font font;
		sf::Text copy;


	public:
		Player(sf::Font& f, sf::Color c);
		void changeTurn();//used for switchign isTurn
		inline void setName(std::string s) { text.setString(s); }
		inline void score() { nrOfCopies++; }
		inline int getScore() { return nrOfCopies; }
		void setPosition(sf::Vector2f position);
		void reset() { text = copy; }
		sf::Text& getSprite();//used when drawing
		std::string getName();
	};

}