#include "Player.hpp"

using namespace entities;

Player::Player(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture), CollisionListener(){
    this->CNormalColor = sf::Color(0, 0, 0, 255);
    this->pItem = NULL;
    this->bTopBounds = false;
    this->bLeftBounds = false;
    this->bBottomBounds = false;
    this->bRightBounds = false;
   // this->bEnteredDoor = false;
}

void Player::initialize() {
    this->setFrame(0);
    this->initializePosition();
   // this->setFrame(0);

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

void Player::initializePosition() {
    this->pSprite->setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2 - 50.0f);
    sf::Vector2f vecPosition = {};

    DoorType EType = AreaManager::getInstance()->getDoorType();

    if(EType == DoorType::TOP ) {
        vecPosition = sf::Vector2f(600.0f, 600.0f);
        std::cout << "DOOR ENTERED FROM TOP" << std::endl;
        this->pSprite->setPosition(vecPosition);
    }
    
    else if(EType == DoorType::LEFT ) {
        vecPosition = sf::Vector2f(1100.0f, 300.0f);
        std::cout << "DOOR ENTERED FROM LEFT" << std::endl;
        this->pSprite->setPosition(vecPosition);
        this->setFrame(1);
    }

    else if(EType == DoorType::BOTTOM) {
        vecPosition = sf::Vector2f(600.0f, 0.0f);
        std::cout << "DOOR ENTERED FROM BOTTOM" << std::endl;
        this->pSprite->setPosition(vecPosition);
    }

    else if(EType == DoorType::RIGHT ) {
        vecPosition = sf::Vector2f(0.0f, 300.0f);
        std::cout << "DOOR ENTERED FROM RIGHT" << std::endl;
        this->pSprite->setPosition(vecPosition);
        this->setFrame(0);
    }
    
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
        

    if(pGameObject->getName() == "Scrap")
        this->pItem = pGameObject;
}

void Player::onCollisionExit(GameObject* pGameObject) {
    if(pGameObject->getName() == "Scrap")
        this->pItem = NULL;

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

GameObject* Player::getItem() {
    return this->pItem;
}

/*
bool Player::getEnteredDoor() {
    return this->bEnteredDoor;
}

void Player::setEnteredDoor(bool bEnteredDoor) {
    this->bEnteredDoor = bEnteredDoor;
}
*/