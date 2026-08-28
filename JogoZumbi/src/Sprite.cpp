#include <Sprite.h>
#include <Game.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(string file){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::Open(string file){
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
    }
    
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if(texture == nullptr){
        cout << "Erro ao carregar imagem: " << SDL_GetError() << endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    SetClip(0,0,width,height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect = {x,y,w,h};
}

void Sprite::Render(int x, int y){
    SDL_Rect dstRect;

    dstRect = {x,y,clipRect.w,clipRect.h};

    SDL_RenderCopy(Game::GetInstance().GetRenderer(),texture,&clipRect,&dstRect);
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    return (texture != nullptr);
}