#include <Sprite.h>
#include <Game.h>
#include <SDL2/SDL_image.h>
#include <Resources.h>
#include <iostream>

Sprite::Sprite(){
    texture = nullptr;
    width = 0, height = 0;
    SetFrameCount(1, 1);
}

Sprite::Sprite(string file, int frameCountW, int frameCountH){
    texture = nullptr;
    this->frameCountW = frameCountW;
    this->frameCountH = frameCountH;
    Open(file);
}

Sprite::~Sprite(){}

void Sprite::Open(string file){
    texture = Resources::GetImage(file);
    
    if(texture == nullptr){
        cout << "Erro ao carregar imagem: " << SDL_GetError() << endl;
        return;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    SetFrame(0);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect = {x,y,w,h};
}

void Sprite::Render(int x, int y, int w, int h){
    SDL_Rect dstRect;

    dstRect = {x,y,w,h};

    SDL_RenderCopy(Game::GetInstance().GetRenderer(),texture,&clipRect,&dstRect);
}

int Sprite::GetWidth(){
    return width/frameCountW;
}

int Sprite::GetHeight(){
    return height/frameCountH;
}

bool Sprite::IsOpen(){
    return (texture != nullptr);
}

void Sprite::SetFrame(int frame){
    if(frame < 0 || frame >= frameCountW * frameCountH){
        return;
    }

    int frameW = width/frameCountW;
    int frameH = height/frameCountH;

    int frameX = frame % frameCountW;
    int frameY = frame / frameCountW;

    int x = frameX * frameW;
    int y = frameY * frameH;

    SetClip(x, y, frameW, frameH);
}

void Sprite::SetFrameCount(int frameCountW, int frameCountH){
    this->frameCountW = frameCountW;
    this->frameCountH = frameCountH;
}