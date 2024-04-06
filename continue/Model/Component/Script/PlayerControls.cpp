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
        
        if(pPlayerInput->getUp() && !pPlayer->getTopBounds()) {
            pSprite->setPosition(this->fX, this->fY - 100.0f);
            pPlayerInput->resetMovement();
        }

        else if(pPlayerInput->getLeft() && !pPlayer->getLeftBounds()) {
            pPlayer->setFrame(1);
            pSprite->setPosition(this->fX - 100.0f, this->fY);
            pPlayerInput->resetMovement();
        }

        else if(pPlayerInput->getDown() && !pPlayer->getBottomBounds()) {
            pSprite->setPosition(this->fX, this->fY + 100.0f);
            pPlayerInput->resetMovement();
        }

        else if(pPlayerInput->getRight() && !pPlayer->getRightBounds()) {
            pPlayer->setFrame(0);
            pSprite->setPosition(this->fX + 100.0f, this->fY);
            pPlayerInput->resetMovement();  
        }

        else if(pPlayerInput->getInteract() && pPlayer->getItem() != NULL) {

            if (pPlayer->getItem()->getName().find("Scrap") != std::string::npos){

                Scrap* pScrap = (Scrap*)pPlayer->getItem();
                pScrap->onPickup(this->getOwner());

            }

        }
        
    }
}