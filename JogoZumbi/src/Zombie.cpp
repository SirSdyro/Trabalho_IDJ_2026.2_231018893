#include <Zombie.h>
#include <GameObject.h>
#include <SpriteRenderer.h>
#include <Animator.h>

Zombie::Zombie(GameObject& associated) : Component(associated){
    hitpoints = 100;

    SpriteRenderer* spriteRenderer = new SpriteRenderer(associated, "../recursos/img/Enemy.png", 3, 2);
    associated.AddComponent(spriteRenderer);

    Animator* animator = new Animator(associated);
    animator->AddAnimation("walking",Animation(0,3,10));
    animator->AddAnimation("dead",Animation(5,5,0));

    animator->SetAnimation("walking");
    associated.AddComponent(animator);
}

void Zombie::Damage(int damage){
    hitpoints -= damage;
    
    if(hitpoints <= 0){
        SpriteRenderer* spriteRenderer = associated.GetComponent<SpriteRenderer>();

        if (spriteRenderer != nullptr) {
            spriteRenderer->SetFrame(5);
        }
    }
}

void Zombie::Update(float dt){
    Damage(1);
}

void Zombie::Render(){
}