#include <Resources.h>
#include <Game.h>
#include <SDL2/SDL_image.h>
#include <iostream>

std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(std::string file){
    auto it = imageTable.find(file);

    if(it != imageTable.end()){
        return it->second;
    }

    SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(),file.c_str());

    if(texture == nullptr){
        std::cout << "Erro ao carregar imagem: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    imageTable.insert(std::make_pair(file, texture));

    return texture;
}

void Resources::ClearImages(){
    for(auto it = imageTable.begin(); it != imageTable.end(); ++it){
        SDL_DestroyTexture(it->second);
    }
    
    imageTable.clear();
}

Mix_Music* Resources::GetMusic(std::string file){
    auto it = musicTable.find(file);

    if(it != musicTable.end()){
        return it->second;
    }

    Mix_Music* music = Mix_LoadMUS(file.c_str());

    if(music == nullptr){
        std::cerr << "Erro ao carregar música: "
                  << Mix_GetError() << std::endl;
        return nullptr;
    }

    musicTable.insert(std::make_pair(file, music));

    return music;
}

void Resources::ClearMusics(){
    for(auto it = musicTable.begin(); it != musicTable.end(); ++it){
        Mix_FreeMusic(it->second);
    }

    musicTable.clear();
}

Mix_Chunk* Resources::GetSound(std::string file){
    auto it = soundTable.find(file);

    if(it != soundTable.end()){
        return it->second;
    }

    Mix_Chunk* sound = Mix_LoadWAV(file.c_str());

    if(sound == nullptr){
        std::cerr << "Erro ao carregar som: "
                  << Mix_GetError() << std::endl;
        return nullptr;
    }

    soundTable.insert(std::make_pair(file, sound));

    return sound;
}

void Resources::ClearSounds(){
    for(auto it = soundTable.begin(); it != soundTable.end(); ++it){
        Mix_FreeChunk(it->second);
    }

    soundTable.clear();
}