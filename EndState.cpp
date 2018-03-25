#include "EndState.h"
#include "MenuState.h"

namespace memoryGame {

	namespace State {


		EndState::EndState(GameDataRef d, Player p)
			:winner(p), data(d)
		{
			audioBuffer.loadFromFile("Resources/endingTheme.wav");
			s.setBuffer(audioBuffer);
			s.setVolume(60.0f);
			s.play();

			text.setString("HA VINTO IL:" + winner.getName());
			text.setCharacterSize(45);
			f.loadFromFile("Resources/Mistral.ttf");
			text.setFont(f);
			exit.setString("PREMI ESC PER TORNARE AL MENU");
			exit.setCharacterSize(45);
			exit.setFont(f);
			exit.setPosition({300.0f,550.0f});
		}

		void EndState::draw()
		{
			data->window.clear();
			data->window.draw(text);
			data->window.draw(exit);
			data->window.display();
			r = rand() % 256;
			g = rand() % 256;
			b = rand() % 256;
		}

		void EndState::update()
		{

			text.setFillColor(sf::Color(r, g, b, 255));
		}

		void EndState::handleInput()
		{
			sf::Event e;
			while (data->window.pollEvent(e)) {
				if (sf::Event::Closed == e.type)
				{
					this->data->window.close();
				}
				if (e.type == sf::Event::KeyPressed) {
					if (e.key.code == sf::Keyboard::Escape) {
						data->machine.Add((StateRef)(std::make_unique<MenuState>(data)), true);
					}
				}
			}
		}

	}
}
