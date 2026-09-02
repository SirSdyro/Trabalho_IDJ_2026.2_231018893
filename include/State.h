#ifndef STATE_H
#define STATE_H

#include <Sprite.h>
#include <Music.h>
#include <GameObject.h>
#include <memory>
#include <vector>

class State{
    private:
        Music music;
        bool quitRequested;
        std::vector<std::unique_ptr<GameObject>> objectArray;

    public:
        State();
        ~State();

        bool QuitResquested();

        void LoadAssets();
        void Update(float dt);
        void Render();
        void AddObject(GameObject* go);
};

#endif