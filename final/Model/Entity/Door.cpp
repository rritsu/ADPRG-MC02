#include "Door.hpp"

using namespace entities;

Door::Door(DoorType EType, std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
    this->vecPosition = sf::Vector2f(0.0f, 0.0f);
    this->EType = EType;
    this->bPlayerCollision = false;
}

void Door::initialize() {

    this->initializePosition();
    this->pSprite->setPosition(this->vecPosition);   

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);
}



void Door::onCollisionEnter(GameObject* pGameObject) {
    if(pGameObject->getName() == "Player") {
        this->bPlayerCollision = true;
      //  std::cout << "door player collision" << std::endl;
    }
}

void Door::onCollisionExit(GameObject* pGameObject) { 
    if(pGameObject->getName() == "Player") {
        this->bPlayerCollision = false;
      //  std::cout << "door player exit" << std::endl;
    }
    
}

void Door::initializePosition() {
    if(this->EType == DoorType::TOP || this->EType == DoorType::ENTRY_TOP) {
        this->vecPosition = sf::Vector2f(600.0f, 0.0f);
        this->setFrame(0);
    }

    else if(this->EType == DoorType::LEFT || this->EType == DoorType::ENTRY_LEFT) {
        this->vecPosition = sf::Vector2f(0.0f, 300.0f);
        this->setFrame(1);
    }

    else if(this->EType == DoorType::BOTTOM || this->EType == DoorType::ENTRY_BOTTOM) {
        this->vecPosition = sf::Vector2f(600.0f, 600.0f);
        this->setFrame(2);
    }

    else if(this->EType == DoorType::RIGHT || this->EType == DoorType::ENTRY_RIGHT) {
        this->vecPosition = sf::Vector2f(1100.0f, 300.0f);
        this->setFrame(3);
    }
}

sf::Vector2f Door::getPostition() {
    return this->vecPosition;
}

bool Door::getPlayerCollision() {
    return this->bPlayerCollision;
}

DoorType Door::getType() {
    return this->EType;
}