#include "state_machine.h"
#include <cassert>


template <typename StateType>
void StateMachine<StateType>::Push(StateType * state, StatePushMode mode)
{
	assert(awaiting_push_mode == StatePushMode::IGNORE);
	awaiting_state = state;
	awaiting_push_mode = mode;
}
