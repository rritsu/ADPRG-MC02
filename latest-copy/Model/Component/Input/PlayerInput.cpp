#include "PlayerInput.hpp"

using namespace components;

PlayerInput::PlayerInput(std::string strName) : GeneralInput(strName) {
    this->bUp = false;
    this->bDown = false;
    this->bLeft = false;
    this->bRight = false;
    this->bInteract = false;
}

void PlayerInput::perform() {
    switch(this->CEvent.type) {
        case sf::Event::KeyPressed:
            this->processKeyInput(true);
            break;
            
        case sf::Event::KeyReleased:
            this->processKeyInput(false);
            break;

        default:
            break;
    }
}

void PlayerInput::processKeyInput(bool bPressed) {
    sf::Keyboard::Key CKey = this->CEvent.key.code;

    switch(CKey) {
        case sf::Keyboard::W:
            this->bUp = bPressed;
            break;

        case sf::Keyboard::S:
            this->bDown = bPressed;
            break;

        case sf::Keyboard::A:
            this->bLeft = bPressed;
            break;

        case sf::Keyboard::D:
            this->bRight = bPressed;
            break;
        
        case sf::Keyboard::E:
            this->bInteract = bPressed;
            break;

        default:
            break;
    }
}

void PlayerInput::resetInteract() {
    this->bInteract = false;
}

void PlayerInput::resetMovement() {
    this->bUp = false;
    this->bLeft = false;
    this->bRight = false;
    this->bDown = false;
}

bool PlayerInput::getInteract() {
    return this->bInteract;
}

bool PlayerInput::getUp() {
    return this->bUp;
}

bool PlayerInput::getDown() {
    return this->bDown;
}

bool PlayerInput::getLeft() {
    return this->bLeft;
}

bool PlayerInput::getRight() {
    return this->bRight;
}
