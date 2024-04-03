#include "Door.hpp"

using namespace entities;

Door::Door(DoorType EType, std::string strName, AnimatedTexture* pTexture, sf::Vector2f vecPosition) : GameObject(strName, pTexture) {
    this->vecPosition = vecPosition;
    this->EType = EType;
}

void Door::initialize() {
    this->pSprite->setPosition(this->vecPosition);
    this->setDoorFrame();

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

void Door::setDoorFrame() {
    if(this->EType == DoorType::TOP)
        this->setFrame(0);

    else if(this->EType == DoorType::LEFT)
    this->setFrame(1);

    else if(this->EType == DoorType::BOTTOM)
        this->setFrame(2);

    else if(this->EType == DoorType::RIGHT)
        this->setFrame(3);
}
