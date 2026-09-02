#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <Rect.h>
#include <Component.h>

class GameObject{
    public:
        GameObject();
        ~GameObject();
        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component* cpt);
        void RemoveComponent(Component* cpt);
        
        template <typename T>
        T* GetComponent();

        Rect box;
    private:
        std::vector<Component*> components;
        bool isDead;
};

#include <GetComponent.h>

#endif