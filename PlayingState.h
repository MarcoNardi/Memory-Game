#pragma once
#include <SFML\Graphics.hpp>
#include "GameState.h"
#include "Game.h"
#include <vector>
#include <array>
#include "Player.h"

#define NUMBER_OF_CARDS 10


namespace memoryGame {

	struct Card {
		sf::Sprite sprite;
		sf::Texture texture;
		Textures::ID textureId;
		bool selected=false;
	};


	namespace State {

		class PlayingState :public GameState {
		public:
			PlayingState(int nrP, GameDataRef d);
			void draw();
			void update();
			void handleInput();
		private:
			void shuffle();//shuffel the cards
			void moveCards(const sf::Vector2f& offset);//move ALL the cards
			
			const int nrOfPlayers;
			std::pair<Textures::ID, Textures::ID> selectedID = { Textures::missing ,Textures::missing };//pair of textures id of the selected cards
			std::pair<int, int> selectedIndex = { -1,-1 };
			int turn = 0;
			int selection = 0;//keeps count of how many cards you have selected
			int pairsFound = 0;
			//graphical objects
			sf::Texture textureBack;
			Textures::ID backID = Textures::BACK6;
			sf::Font font;
			sf::Text showTurn;
			
			//game objects
			sf::Clock clock;
			std::vector <Player> players;
			std::array <Card, NUMBER_OF_CARDS> cards;


			GameDataRef data;

		};
	}
}