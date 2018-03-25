#pragma once
#include <SFML\Audio.hpp>
#include "GameState.h"
#include "Game.h"
#include "Player.h"

namespace memoryGame {

	namespace State {


		class EndState :public GameState{
		public:
			EndState(GameDataRef d,Player p);
			void draw();
			void update();
			void handleInput();
		private:

			int r=0;
			int g=0;
			int b=0;

			sf::Sound s;
			sf::SoundBuffer audioBuffer;
			Player winner;
			sf::Font f;
			sf::Text text;
			sf::Text exit;
			GameDataRef data;
		};
	}
}