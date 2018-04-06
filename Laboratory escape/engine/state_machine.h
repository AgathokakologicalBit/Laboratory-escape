#pragma once

#include <cassert>
#include <stack>
#include <type_traits>
#include "state.h"


template <typename StateType>
class StateMachine
{
public:
    enum StatePushMode
    {
        IGNORE,
        REPLACE,
        APPEND,
    };

private:
    std::stack<StateType *> states;
    StateType * awaiting_state;
    StatePushMode awaiting_push_mode;


public:
    void Push(StateType * state, StatePushMode mode)
    {
        assert(awaiting_push_mode == StatePushMode::IGNORE);
        awaiting_state = state;
        awaiting_push_mode = mode;
    }

    void Pop();
    StateType * Top() const
    {
        return states.empty() ? nullptr : states.top();
    }

    bool Empty() const
    {
        return states.empty() && awaiting_state == nullptr;
    }

    void Update()
    {
        if (!states.empty()) states.top()->Update();

        if (awaiting_push_mode == IGNORE) return;

        if (!states.empty())
            states.top()->Pause();

        if (awaiting_push_mode == REPLACE && !states.empty())
        {
            states.top()->Stop();
            states.pop();
        }

        states.push(awaiting_state);
        states.top()->Start();

        awaiting_push_mode = IGNORE;
        awaiting_state = nullptr;
    }
};
