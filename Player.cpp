#include "Player.h"
#include <sstream>
memoryGame::Player::Player(sf::Font & f, sf::Color c)
	:font(f), color(c)
{
	text.setFont(f);
	text.setFillColor(color);
	text.setCharacterSize(45);
}

void memoryGame::Player::changeTurn()
{
	isTurn = true;
}

void memoryGame::Player::setPosition(sf::Vector2f position)
{
	text.setPosition(position);
}

sf::Text& memoryGame::Player::getSprite()
{
	std::stringstream ss;
	copy = text;
	ss << (std::string) text.getString() << ":";
	ss << nrOfCopies;
	text.setString(ss.str());
	return text;
}

std::string memoryGame::Player::getName()
{
	return text.getString();
}
