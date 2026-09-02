#include <Music.h>
#include <iostream>
#include <Resources.h>

Music::Music(){
    music = nullptr;
}

Music::Music(string file){
    music = nullptr;
    Open(file);
}

void Music::Play(int times){
    if(music != nullptr){
        Mix_PlayMusic(music, times);
    }
    else{
        cout << "Erro ao carregar áudio: " << SDL_GetError() << endl;
        return;
    }
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
    if (music != nullptr){
        Stop();
        music = nullptr;
    }

    music = Resources::GetMusic(file);
    if(music == nullptr){
        cout << "Erro ao carregar áudio: " << SDL_GetError() << endl;
        return;
    }
}

bool Music::IsOpen(){
    return (music != nullptr);
}

Music::~Music(){
    Stop();
}