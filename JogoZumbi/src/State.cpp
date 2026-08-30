#include <State.h>
#include <SpriteRenderer.h>
#include <Zombie.h>
#include <SDL2/SDL.h>

State::State(){
    quitRequested = false;

    GameObject* bg = new GameObject();
    SpriteRenderer* spriteRenderer = new SpriteRenderer(*bg, "../recursos/img/Background.png");
    bg->AddComponent(spriteRenderer);
    AddObject(bg);

    GameObject* zombie = new GameObject();
    Zombie* zombieCpt = new Zombie(*zombie);
    zombie->AddComponent(zombieCpt);
    
    zombie->box.x = 600;
    zombie->box.y = 450;
    AddObject(zombie);

    music.Open("../recursos/audio/BGM.wav");
    music.Play();
    Mix_VolumeMusic(48);
}

State::~State(){
    objectArray.clear();
}

void State::LoadAssets(){
    
}

void State::Update(float dt){
    for(int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Update(dt);
    }

    if(SDL_QuitRequested()){
        quitRequested = true;
    }

    for(int i = objectArray.size() - 1; i >= 0; i--){
        if(objectArray[i]->IsDead()){
            objectArray.erase(objectArray.begin() + i);
        }
    }
}

void State::Render(){
    for(int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Render();
    }
}

bool State::QuitResquested(){
    return quitRequested;
}

void State::AddObject(GameObject* go){
    objectArray.emplace_back(go);
}