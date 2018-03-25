#pragma once

#include "GameState.h"
#include <memory>
#include <stack>


namespace memoryGame {

	namespace State {
		using StateRef = std::unique_ptr < GameState >;


		class StateMachine {

		private:
			std::stack<StateRef> states;
			StateRef newState;
			bool removing = false;
			bool adding = false;
			bool replacing = false;

		public:
			void Add(StateRef state, bool isReplacing = true);
			void Pop();
			void ProcessStateChanges();
			StateRef& GetTop();
		};
	}
}