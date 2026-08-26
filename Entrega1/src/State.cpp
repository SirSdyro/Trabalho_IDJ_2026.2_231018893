#include <State.h>
#include <SDL2/SDL.h>

State::State(){
    quitRequested = false;

    bg.Open("../recursos/img/Background.png");
    music.Open("../recursos/audio/BGM.wav");
    music.Play();
}

void State::LoadAssets(){
    
}

void State::Update(float dt){
    if(SDL_QuitRequested()){
        quitRequested = true;
    }
}

void State::Render(){
    bg.Render(0,0);
}

bool State::QuitResquested(){
    return quitRequested;
}