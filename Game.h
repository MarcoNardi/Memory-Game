#pragma once

#include "TextureHolder.h"
#include "StateMachine.h"
#include "InputManager.h"

namespace memoryGame {

	struct GameData {
		sf::RenderWindow window;
		Textures::TextureHolder assetManager;
		State::StateMachine machine;
	};
	typedef std::shared_ptr<GameData> GameDataRef;
	//using GameDataRef = std::shared_ptr<GameData>;

	class Game {
	public:
		Game();
		void run();
		//void push(GameState* g);
		//void pop();
		//void changeState(GameState* g);
		//GameState * top();

	private:

		GameDataRef data = std::make_shared<GameData>();

	};
}
