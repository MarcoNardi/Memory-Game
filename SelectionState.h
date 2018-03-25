#pragma once

#include "GameState.h"
#include "Game.h"

namespace memoryGame {


	namespace State {

		class SelectionState :public GameState {
		public:
			SelectionState(GameDataRef d);
			void draw();
			void update();
			void handleInput();
		private:
			GameDataRef data;
			int nrInt;//numero di giocatori
			sf::Text numero;//numero di giocatori mostrato a video
			
			sf::Text nrText;//testo
			sf::Font f;//font utilizzato
			
			sf::Sprite plus;//sprite del +
			sf::Texture plusTexture;//texture del +

			sf::Sprite minus;//sprite del -
			sf::Texture minusTexture;//texture del -
			
			sf::Sprite gioca;
			sf::Texture giocaTexture;



		};
	}
}