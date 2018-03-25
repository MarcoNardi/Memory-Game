#include "PlayingState.h"
#include "EndState.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>


namespace memoryGame {


	namespace State {
		PlayingState::PlayingState(int nrP, GameDataRef d)
			:data(d), nrOfPlayers(nrP)
		{

			//loading textures and data
			textureBack = data->assetManager.get(Textures::BACK6);
			font.loadFromFile("Resources/Mistral.ttf");
			Textures::ID array[5] = { Textures::PICCHE1, Textures::PICCHE2 ,Textures::PICCHE3 ,
									   Textures::PICCHE4 ,Textures::PICCHE5 };
			int cont = 0;
			int k = 0;
			for (auto i = cards.begin(); i < cards.end(); i++) {
				if (cont == 0) {
					i->texture = data->assetManager.get(array[k]);
					i->textureId = array[k];
					cont++;
				}
				else if (cont == 1) {
					i->texture = data->assetManager.get(array[k]);
					i->textureId = array[k];
					cont = 0;
					k++;
				}
				i->sprite.setTexture(textureBack);
			}
			shuffle();
			float offset = (data->window.getSize().x) / 10.0f;
			int times = 0;
			//adjusting cards position
			for (auto i = cards.begin(); i < cards.end(); i++) {
				i->sprite.setPosition({ offset*times,0.0f });
				times++;
			}
			moveCards({ 0.0f,100.0f });
			//players text
			std::string defaultName = "GIOCATORE";
			std::stringstream ss;
			players.reserve(nrOfPlayers);
			sf::Color c;
			for (unsigned int i = 0; i < (unsigned)nrOfPlayers; i++) {
				ss << i + 1;
				if (i == 0)
					c = sf::Color::Red;
				if (i == 1)
					c = sf::Color::Blue;
				if (i == 2)
					c = sf::Color::Green;
				if (i == 3)
					c = sf::Color::Magenta;
				players.emplace_back(font, c);
				players[i].setPosition({ (float)(data->window.getSize() / 4u * i).x ,0.0f });
				players[i].setName(defaultName + ss.str());

				ss.str(std::string());
			}
			
			//text to show who has the turn
			std::string stringturn="TURNO DI: GIOCATORE 1";
			showTurn.setString(stringturn);
			showTurn.setFont(font);
			showTurn.setCharacterSize(45);
			showTurn.setFillColor(sf::Color::Red);
			showTurn.setPosition({ 100.0f,(float)data->window.getSize().y-100u });
			

		}


		void PlayingState::update()
		{
			if (pairsFound == NUMBER_OF_CARDS / 2) {
				auto max = players.begin();
				for (auto a = players.begin() + 1; a < players.end(); a++) {
					if (max->getScore() < a->getScore())
						max = a;
				}
				data->machine.Add((StateRef)(std::make_unique<EndState>(data, *max)), true);
			}
			
			if (selectedID.first == selectedID.second && selectedID.first != Textures::missing && selectedIndex.first!=selectedIndex.second && selectedIndex.first != -1) {
				players[turn].score();

				selectedID.first = Textures::missing;
				selectedID.second = Textures::missing;

				selectedIndex.first = -1;
				selectedIndex.second = -1;

				selection = 0;
				pairsFound++;
			}
			if (selectedID.first != selectedID.second && selection == 2 && clock.getElapsedTime().asSeconds() > sf::seconds(1.5f).asSeconds()) {
				//sf::sleep(sf::seconds(5));
				cards[selectedIndex.first].sprite.setTexture(textureBack);
				cards[selectedIndex.second].sprite.setTexture(textureBack);
				cards[selectedIndex.first].selected = false;
				cards[selectedIndex.second].selected = false;
				selectedID.first = Textures::missing;
				selectedID.second = Textures::missing;

				selectedIndex.first = -1;
				selectedIndex.second = -1;

				selection = 0;
				if (turn < nrOfPlayers) {
					turn++;
					if (turn == nrOfPlayers) {
						turn = 0;
					}
				}
				else {
					turn = 0;
				}
			}
			std::stringstream ss;
			ss << turn;
			showTurn.setString("TURNO DI: GIOCATORE "+ss.str());
			if (turn == 0)
				showTurn.setFillColor(sf::Color::Red);
			if (turn == 1)
				showTurn.setFillColor(sf::Color::Blue);
			if (turn == 2)
				showTurn.setFillColor(sf::Color::Green);
			if (turn == 3)
				showTurn.setFillColor(sf::Color::Magenta);
			
		}
		void PlayingState::draw()
		{
			data->window.clear();

			for (auto& a : players) {
				data->window.draw(a.getSprite());
				a.reset();
			}
			for (auto& a : cards) {
				data->window.draw(a.sprite);
			}
			data->window.draw(showTurn);
			data->window.display();
		}

		void PlayingState::handleInput()
		{
			sf::Event e;
			while (data->window.pollEvent(e)) {
				if (sf::Event::Closed == e.type)
				{
					this->data->window.close();
				}
				int x = 0;
				if (selection <= 1) {
					for (auto i = cards.begin(); i < cards.end(); i++) {
						if (isSpriteReleased(e, sf::Mouse::Button::Left, data->window, i->sprite) && i->selected==false) {
							i->selected = true;
							i->sprite.setTexture(i->texture);
							if (selectedID.first == Textures::missing) {
								selectedID.first = i->textureId;
								selectedIndex.first = x;
								selection++;
							}
							else if (selectedID.second == Textures::missing && selectedIndex.first!=x) {
								selectedID.second = i->textureId;
								selectedIndex.second = x;
								clock.restart();
								//sf::sleep(sf::seconds(5));
								selection++;
							}
							break;
						}
						x++;
					}
				}
			}
		}


		void PlayingState::shuffle()
		{
			srand(time(NULL));
			for (int i = 0; i < NUMBER_OF_CARDS * 5; i++) {
				int k = rand() % NUMBER_OF_CARDS;
				int j = rand() % NUMBER_OF_CARDS;
				std::swap(cards[k], cards[j]);
			}

		}
		void PlayingState::moveCards(const sf::Vector2f& offset)
		{
			for (auto i = cards.begin(); i < cards.end(); i++) {
				i->sprite.move(offset);
			}
		}
	}
}
