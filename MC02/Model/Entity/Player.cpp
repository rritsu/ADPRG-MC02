#include "Player.hpp"

using namespace entities;

Player::Player(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture), CollisionListener(){
    this->CNormalColor = sf::Color(0, 0, 0, 255);
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

void Player::onCollisionEnter(GameObject* pGameObject) {}

void Player::onCollisionExit(GameObject* pGameObject) {}