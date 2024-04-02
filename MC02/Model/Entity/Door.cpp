#include "Door.hpp"

using namespace entities;

Door::Door(std::string strName, AnimatedTexture* pTexture, sf::Vector2f vecPosition) : GameObject(strName, pTexture) {
    this->vecPosition = vecPosition;
}

void Door::initialize() {
    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);
}

void Door::onCollisionEnter(GameObject* pGameObject) {
    
}

void Door::onCollisionExit(GameObject* pGameObject) {
    
}

