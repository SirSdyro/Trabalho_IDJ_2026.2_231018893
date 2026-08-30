#include <GameObject.h>
#include <Component.h>

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    for(int i = components.size() - 1; i >= 0; i--){
        delete components[i];
    }
    components.clear();
}

void GameObject::Update(float dt){
    for(Component* component : components){
        component->Update(dt);
    }
}

void GameObject::Render(){
    for(Component* component : components){
        component->Render();
    }
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
    for (auto it = components.begin(); it != components.end(); ++it){
        if (*it == cpt){
            components.erase(it);
            return;
        }
    }
}