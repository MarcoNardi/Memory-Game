#pragma once
#include "GameState.h"
#include "Game.h"

namespace memoryGame {

	namespace State {

		class MenuState :public GameState {
		public:
			MenuState(GameDataRef d);
			void draw();
			void update();
			void handleInput();

		private:
			int playersNr;
			bool change=false;

			sf::Sprite play;
			sf::Texture playTexture;

			sf::Sprite quit;
			sf::Texture quitTexture;
			GameDataRef data;
		};

	}
}
