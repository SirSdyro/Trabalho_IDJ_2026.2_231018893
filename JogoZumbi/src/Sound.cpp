#include <Sound.h>
#include <Resources.h>
#include <iostream>

Sound::Sound(){
    chunk = nullptr;
}

Sound::Sound(std::string file) : Sound(){
    Open(file);
}

void Sound::Play(int times){
    if (chunk == nullptr){
        return;
    }
    
    channel = Mix_PlayChannel(-1, chunk, times - 1);

    if(channel == -1){
        std::cout << "Erro ao reproduzir audio: " << SDL_GetError() << std::endl;
    }
}

void Sound::Stop(){ 
    if(chunk != nullptr && channel != -1){
        Mix_HaltChannel(channel);
        channel = -1;
    }
}

void Sound::Open(std::string file){
    if (chunk != nullptr){
        Stop();
        chunk = nullptr;
    }

    chunk = Resources::GetSound(file);

    if(chunk == nullptr){
        std::cout << "Erro ao carregar audio: " << SDL_GetError() << std::endl;
        return;
    }
}

Sound::~Sound(){}

bool Sound::IsOpen(){
    return chunk != nullptr;
}