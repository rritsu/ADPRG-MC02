#include "Player.hpp"

using namespace entities;

Player::Player(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture), CollisionListener(){
    this->CNormalColor = sf::Color(0, 0, 0, 255);
    this->bTopBounds = false;
    this->bLeftBounds = false;
    this->bBottomBounds = false;
    this->bRightBounds = false;
}

void Player::initialize() {
    //this->centerOrigin();
    //this->pSprite->setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    //this->pSprite->setPosition(SCREEN_WIDTH/2, /);

    this->setFrame(0);

    PlayerInput* pInput = new PlayerInput(this->strName + " Input");
    this->attachComponent(pInput);

    PlayerControls* pControls = new PlayerControls(this->strName + " Controls");
    this->attachComponent(pControls);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);   

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);

}

void Player::onCollisionEnter(GameObject* pGameObject) {
    if(pGameObject->getName() == "Top Border") 
        this->bTopBounds = true;
    

    if(pGameObject->getName() == "Left Border")
        this->bLeftBounds = true;

    if(pGameObject->getName() == "Bottom Border")
        this->bBottomBounds = true;

    if(pGameObject->getName() == "Right Border")
        this->bRightBounds = true;
}

void Player::onCollisionExit(GameObject* pGameObject) {
    if(pGameObject->getName() == "Top Border")
        this->bTopBounds = false;
    
    if(pGameObject->getName() == "Left Border")
        this->bLeftBounds = false;
    
    if(pGameObject->getName() == "Bottom Border")
        this->bBottomBounds = false;
    
    if(pGameObject->getName() == "Right Border")
        this->bRightBounds = false;
}

bool Player::getTopBounds() {
    return this->bTopBounds;
}

bool Player::getLeftBounds() {
    return this->bLeftBounds;
}

bool Player::getBottomBounds() {
    return this->bBottomBounds;
}

bool Player::getRightBounds() {
    return this->bRightBounds;
}