#pragma once

#include <type_traits>
#include "state.h"


template <typename StateType, typename std::enable_if<std::is_base_of<State, StateType>::value>::type* = nullptr>
class StateMachine
{
public:
	void Push(StateType * state, bool replace);
	void Pop();
	StateType * Top() const;
};
