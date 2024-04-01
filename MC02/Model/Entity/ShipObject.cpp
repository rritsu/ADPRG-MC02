#include "ShipObject.hpp"
using namespace entities;

ShipObject::ShipObject(std::string strName, AnimatedTexture* pTexture, sf::Vector2f vecPosition) : GameObject(strName, pTexture) {
    this->vecPosition = vecPosition;
    this->bPlayerCollision = false;
}

void ShipObject::initialize() {
   // LaptopInput* pInput = new LaptopInput(this->strName + " Input");
    //this->attachComponent(pInput);
   // this->pSprite->setPosition(100.0f, 100.0f);
    this->getSprite()->setPosition(this->vecPosition);

    std::cout << this->strName << std::endl;

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);

}


void ShipObject::onCollisionEnter(GameObject* pGameObject) {
    if(pGameObject->getName() == "Player") {
        this->bPlayerCollision = true;
      //  std::cout << this->getShade()->getName() << std::endl;
      //  this->pShade->setShadeSetting(sf::Vector2f(1.05f, 1.05f), COLOR_GREEN);
     //   this->getShade()->setShadeSetting(sf::Vector2f(1.05f, 1.05f), COLOR_GREEN);
    }
}

void ShipObject::onCollisionExit(GameObject* pGameObject) {
    if(pGameObject->getName() == "Player") {
        this->bPlayerCollision = false;
        //this->getShade()->setShadeSetting(sf::Vector2f(1.05f, 1.05f), COLOR_BLACK);
    }
}

bool ShipObject::getPlayerCollision() {
    return this->bPlayerCollision;
}