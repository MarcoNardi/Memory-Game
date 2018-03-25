#include "Game.h"
#include <iostream>
#include "MenuState.h"


namespace memoryGame {

	Game::Game()
	{
		data->window.create(sf::VideoMode(1204, 720 ), "Memory!", sf::Style::Default);
		
		
		data->assetManager.load(Textures::PLAY, "play.png");
		data->assetManager.load(Textures::QUIT, "quit.png");
		data->assetManager.load(Textures::PLUS, "plus.png");
		data->assetManager.load(Textures::MINUS, "minus.png");
		data->assetManager.load(Textures::PLAY_INVERTED, "playInverted.png");
		data->assetManager.load(Textures::BACK6, "back6.png");
		data->assetManager.load(Textures::PICCHE1, "picche1.png");
		data->assetManager.load(Textures::PICCHE2, "picche2.png");
		data->assetManager.load(Textures::PICCHE3, "picche3.png");
		data->assetManager.load(Textures::PICCHE4, "picche4.png");
		data->assetManager.load(Textures::PICCHE5, "picche5.png");

		
		data->machine.Add(State::StateRef(std::make_unique<State::MenuState>(data)), true);
	
	}
	
	void Game::run()
	{
		while (data->window.isOpen()) {
			data->machine.ProcessStateChanges();
			data->machine.GetTop()->handleInput();
			data->machine.GetTop()->update();
			data->machine.GetTop()->draw();
		}
	}
	
}
