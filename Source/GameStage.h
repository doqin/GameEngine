#pragma once

class GameScreen;

class GameStage {
public:
    virtual ~GameStage() = default;

    virtual void Init() = 0;
    virtual void Cleanup() = 0;

    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void HandleEvents() = 0;
    virtual void FixedUpdate() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

};