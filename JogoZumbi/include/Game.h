#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <State.h>
#include <string>
#include <iostream>

class Game
{
private:
    Game(std::string title, int width, int height);
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;
public:
    ~Game();
    void Run();
    SDL_Renderer* GetRenderer();
    State& GetState();
    static Game& GetInstance();
};

#endif