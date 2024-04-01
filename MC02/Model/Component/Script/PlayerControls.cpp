#include "PlayerControls.hpp"

using namespace components;

PlayerControls::PlayerControls(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fX = 0.0f;
    this->fX = 0.0f;
}

void PlayerControls::perform() {
    Player* pPlayer = (Player*)this->getOwner();
    sf::Sprite* pSprite = pPlayer->getSprite();
    PlayerInput* pPlayerInput = (PlayerInput*)pPlayer->findComponentByName(this->pOwner->getName() + " Input");
    
    if(pPlayerInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {

        this->fX = pSprite->getPosition().x;
        this->fY = pSprite->getPosition().y;
        
        if(pPlayerInput->getUp()) {
            pSprite->setPosition(this->fX, this->fY - 100.0f);
            pPlayerInput->resetMovement();
        }

        else if(pPlayerInput->getDown()) {
            pSprite->setPosition(this->fX, this->fY + 100.0f);
            pPlayerInput->resetMovement();
        }
        
        else if(pPlayerInput->getLeft()) {
            pPlayer->setFrame(1);
            pSprite->setPosition(this->fX - 100.0f, this->fY);
            pPlayerInput->resetMovement();
        }

        else if(pPlayerInput->getRight()) {
            pPlayer->setFrame(0);
            pSprite->setPosition(this->fX + 100.0f, this->fY);
            pPlayerInput->resetMovement();  
        }

        this->boundPlayer();
        
    }
}

void PlayerControls::boundPlayer() {
    sf::Sprite* pSprite = this->getOwner()->getSprite();

    if(this->fX >= SCREEN_WIDTH) {
        pSprite->setPosition(SCREEN_WIDTH - 100.0F, this->fY);
    }

    if(this->fX < 0.0f) {
        pSprite->setPosition(0.0f, this->fY);
    }

    if(this->fY >= SCREEN_HEIGHT) {
        pSprite->setPosition(this->fX, SCREEN_HEIGHT - 100.0f);
    }

    if(this->fY < 0.0f) {
        pSprite->setPosition(this->fX, 0.0f);
    }
}
