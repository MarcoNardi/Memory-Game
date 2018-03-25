#pragma once



namespace memoryGame {

	namespace State {


		class GameState {
		public:
			virtual void draw() = 0;
			virtual void update() = 0;
			virtual void handleInput() = 0;
			virtual ~GameState() = default;
		};
	}
}
