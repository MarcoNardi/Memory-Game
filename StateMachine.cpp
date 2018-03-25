#include "StateMachine.h"

namespace memoryGame {

	namespace State {
		void StateMachine::Add(StateRef  state, bool isReplacing )
		{

			adding = true;
			replacing = isReplacing;
			newState = std::move(state);

		}
		void StateMachine::Pop()
		{
			removing = true;

		}
		void StateMachine::ProcessStateChanges()
		{
			if (removing && !states.empty()) {
				states.pop();
				removing = false;
			}
			if (adding) {

				if (replacing && !states.empty()) {
					states.pop();
				}
				states.push(std::move(newState));
				adding = false;
			}

		}
		StateRef & StateMachine::GetTop()
		{
			return states.top();
		}
	}
}
