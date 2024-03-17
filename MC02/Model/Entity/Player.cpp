#include "Player.hpp"

using namespace entities;

Player::Player(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {}

void Player::initialize() {
    //std::cout << "initialize player" << std::endl;
    //this->centerOrigin();                     //BUGGY
 //   this->pSprite->setPosition(300.0f, 300.0f);
   //

    //components
    PlayerInput* pInput = new PlayerInput(this->strName + " Input");
    this->attachComponent(pInput);

    PlayerScript* pScript = new PlayerScript(this->strName + " Script");
    this->attachComponent(pScript);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

     std::cout << "initialize player" << std::endl;
    //collider
}

//onCollisionEnter
//onCollisionExit