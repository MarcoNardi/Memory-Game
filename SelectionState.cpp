#include "SelectionState.h"
#include <sstream>
#include "PlayingState.h"
#include "MenuState.h"

namespace memoryGame {

	namespace State {
		SelectionState::SelectionState(GameDataRef d)
			:data(d), nrInt(1)
		{
			//plus
			plusTexture = data->assetManager.get(Textures::PLUS);
			plus.setTexture(plusTexture);
			plus.setPosition(sf::Vector2f((data->window.getSize() - plusTexture.getSize()) / 2u));
			plus.setScale(0.65f, 0.65f);
			plus.move(150.0f, 0.0f);

			//minus
			minusTexture = data->assetManager.get(Textures::MINUS);
			minus.setTexture(minusTexture);
			minus.setPosition(sf::Vector2f((data->window.getSize() - minusTexture.getSize()) / 2u));
			minus.setScale(0.85f, 0.85f);
			minus.move(-150.0f, 0.0f);

			//gioca
			giocaTexture = data->assetManager.get(Textures::PLAY_INVERTED);
			gioca.setTexture(giocaTexture);
			gioca.setPosition(sf::Vector2f((data->window.getSize() - giocaTexture.getSize()) / 2u));
			gioca.move(0, 150.0f);

			//testo bello
			f.loadFromFile("Resources/Mistral.ttf");
			nrText.setFont(f);
			nrText.setString("SCEGLI IL NUMERO GIOCATORI (MAX 4)");
			nrText.setCharacterSize(72);
			nrText.setFillColor({ 255,116,35,255 });//arancione
			nrText.move(180.0f, 0.0f);

			numero.setFont(f);
			numero.setString("");
			numero.setCharacterSize(72);
			numero.setFillColor({ 255,116,35,255 });


			numero.setPosition(sf::Vector2f((data->window.getSize()) / 2u));
			numero.move(-(float)numero.getCharacterSize(), -(float)numero.getCharacterSize());
		}
		void SelectionState::draw()
		{

			std::stringstream ss;
			ss << nrInt;
			numero.setString(ss.str());
			data->window.clear(sf::Color(101, 66, 255));
			data->window.draw(plus);
			data->window.draw(minus);
			data->window.draw(gioca);
			data->window.draw(nrText);
			data->window.draw(numero);
			data->window.display();
		}

		void SelectionState::update()
		{
		}

		void SelectionState::handleInput()
		{
			sf::Event e;
			while (data->window.pollEvent(e)) {
				if (sf::Event::Closed == e.type)
				{
					this->data->window.close();
				}
				else if (isSpriteReleased(e, sf::Mouse::Button::Left, data->window, plus)) {
					if (nrInt < 4) {
						nrInt++;

					}
				}
				else if (isSpriteReleased(e, sf::Mouse::Button::Left, data->window, minus)) {
					if (!(nrInt <= 1)) {
						nrInt--;
					}
				}
				else if (isSpriteReleased(e, sf::Mouse::Button::Left, data->window, gioca)) {
					data->machine.Add(StateRef(std::make_unique<PlayingState>(nrInt, data)), true);
				}

			}

		}

	}


}