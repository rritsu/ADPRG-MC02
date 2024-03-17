#include "PlayerScript.hpp"

using namespace components;

PlayerScript::PlayerScript(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fSpeed = 300.0f;
}

void PlayerScript::perform() {
   // PlayerInput* pPlayerInput = (PlayerInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];
    PlayerInput* pPlayerInput = (PlayerInput*)this->getOwner()->findComponentByName(this->getOwner()->getName() + " Input");
    sf::Sprite* pSprite = this->getOwner()->getSprite();

    if(pPlayerInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();

        if(pPlayerInput->getMovingUp()) {
            pSprite->move(0.0f, -fOffset);
        }

        if(pPlayerInput->getMovingDown()) {
            pSprite->move(0.0f, fOffset);
        }

        if(pPlayerInput->getMovingLeft()) {
            pSprite->move(-fOffset, 0.0f);
        }

        if(pPlayerInput->getMovingRight()) {
            pSprite->move(fOffset, 0.0f);
        }

    }
}