#include "PlayerInput.hpp"

using namespace components;

PlayerInput::PlayerInput(std::string strName) : GeneralInput(strName) {
    this->bMovingUp = false;
    this->bMovingDown = false;
    this->bMovingLeft = false;
    this->bMovingRight = false;
}

void PlayerInput::perform() {
    switch(this->CEvent.type) {
        case sf::Event::KeyPressed:
            this->processKeyboardInput(this->CEvent.key.code, true);
            break;

        case sf::Event::KeyReleased:
            this->processKeyboardInput(this->CEvent.key.code, false);
            break;

        default:
            break;
    }
}

void PlayerInput::processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed) {
    switch(CKey) {
        case sf::Keyboard::W:
            this->setMovingUp(bPressed);
            std::cout << "W" << std::endl;
            break;

        case sf::Keyboard::S:
            this->setMovingDown(bPressed);
            std::cout << "S" << std::endl;
            break;

        case sf::Keyboard::A:
            this->setMovingLeft(bPressed);
            std::cout << "A" << std::endl;
            break;

        case sf::Keyboard::D:
            this->setMovingRight(bPressed);
            std::cout << "D" << std::endl;
            break;

        default:
            break;
    }
}

bool PlayerInput::getMovingUp() {   
    return this->bMovingUp;
}

void PlayerInput::setMovingUp(bool bMovingUp) {
    this->bMovingUp = bMovingUp;
}

bool PlayerInput::getMovingDown() {
    return this->bMovingDown;
}

void PlayerInput::setMovingDown(bool bMovingDown) {
    this->bMovingDown = bMovingDown;
}

bool PlayerInput::getMovingLeft() {
    return this->bMovingLeft;
}

void PlayerInput::setMovingLeft(bool bMovingLeft) {
    this->bMovingLeft = bMovingLeft;
}

bool PlayerInput::getMovingRight() {
    return this->bMovingRight;
}

void PlayerInput::setMovingRight(bool bMovingRight) {
    this->bMovingRight = bMovingRight;
}