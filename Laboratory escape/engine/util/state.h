#pragma once

class State
{
public:
    virtual void Start() = 0;
    virtual void Pause() = 0;
    virtual void Resume() = 0;
    virtual void Stop() = 0;

    virtual void Update() = 0;
};
