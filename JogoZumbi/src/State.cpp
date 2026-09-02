#include <State.h>
#include <SpriteRenderer.h>
#include <Zombie.h>
#include <TileMap.h>
#include <TileSet.h>
#include <SDL2/SDL.h>

State::State(){
    quitRequested = false;

    GameObject* bg = new GameObject();
    SpriteRenderer* spriteRenderer = new SpriteRenderer(*bg, "../recursos/img/Background.png");
    bg->AddComponent(spriteRenderer);
    AddObject(bg);

    GameObject* tileMap = new GameObject();
    TileSet* tileSet = new TileSet(64, 64, "../recursos/img/Tileset.png");
    TileMap* tileMapCpt = new TileMap(*tileMap, "../recursos/map/map.txt", tileSet);
    tileMap->AddComponent(tileMapCpt);

    tileMap->box.x = 0;
    tileMap->box.y = 0;
    AddObject(tileMap);

    GameObject* zombie1 = new GameObject();
    Zombie* zombieCpt1 = new Zombie(*zombie1);
    zombie1->AddComponent(zombieCpt1);
    
    zombie1->box.x = 600;
    zombie1->box.y = 450;
    AddObject(zombie1);

    GameObject* zombie2 = new GameObject();
    Zombie* zombieCpt2 = new Zombie(*zombie2);
    zombie2->AddComponent(zombieCpt2);
    
    zombie2->box.x = 800;
    zombie2->box.y = 450;
    AddObject(zombie2);

    GameObject* zombie3 = new GameObject();
    Zombie* zombieCpt3 = new Zombie(*zombie3);
    zombie3->AddComponent(zombieCpt3);
    
    zombie3->box.x = 700;
    zombie3->box.y = 650;
    AddObject(zombie3);

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