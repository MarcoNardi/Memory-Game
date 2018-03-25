#include "MenuState.h"
#include "SelectionState.h"
#include <iostream>

namespace memoryGame {
	namespace State {
		MenuState::MenuState(GameDataRef d)
			:data(d), play(), quit()
		{
			playTexture = data->assetManager.get(Textures::PLAY);
			play.setTexture(playTexture);
			play.setPosition(sf::Vector2f((data->window.getSize() - playTexture.getSize()) / 2u));
			play.move({ 0.0f,-200.0f });

			quitTexture = data->assetManager.get(Textures::QUIT);
			quit.setTexture(quitTexture);
			quit.setPosition(sf::Vector2f((data->window.getSize() - playTexture.getSize()) / 2u));
			quit.move({ 0.0f,200.0f });
		}

		void MenuState::draw()
		{
			data->window.clear(sf::Color(101, 66, 255));
			data->window.draw(play);
			data->window.draw(quit);
			data->window.display();
		}

		void MenuState::update()
		{
			
		}

		void MenuState::handleInput()
		{
			sf::Event e;
			while (data->window.pollEvent(e))
			{
				if (sf::Event::Closed == e.type)
				{
					this->data->window.close();
				}

			}
				if (isSpriteClicked(play, sf::Mouse::Button::Left, data->window)) {
					data->machine.Add(StateRef(std::make_unique<State::SelectionState>(data)), true);
				}
				else if (isSpriteClicked(quit, sf::Mouse::Button::Left, data->window)) {

					this->data->window.close();
				}












			/*
			while (data->window.pollEvent(e)) {
				if (sf::Event::Closed == e.type)
				{
					this->data->window.close();
				}
				if (e.type == sf::Event::MouseButtonPressed) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(data->window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (e.mouseButton.button == sf::Mouse::Button::Left) {
						if (play.sprite.getGlobalBounds().contains(mousePosF)) {
							play.isPressed = true;


						}
					}
				}
				else if (e.type == sf::Event::MouseButtonReleased) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(data->window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

					if (e.mouseButton.button == sf::Mouse::Button::Left) {
						if (play.sprite.getGlobalBounds().contains(mousePosF)) {
							change = true; 
							data->machine.Add(State::StateRef(std::make_unique<State::SelectionState>(data)), true);

						}
						if (quit.sprite.getGlobalBounds().contains(sf::Vector2f(e.mouseButton.x, e.mouseButton.y))) {
							data->window.close();
						}
					}
					
				}
				
			}
			
			*/
		}


	}
}
