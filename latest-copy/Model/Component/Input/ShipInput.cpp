#include "ShipInput.hpp"
using namespace components;

ShipInput::ShipInput(std::string strName) : GeneralInput(strName) {
    this->bInteract = false;
}

void ShipInput::perform() {
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

void ShipInput::processKeyInput(bool bPressed) {
    sf::Keyboard::Key CKey = this->CEvent.key.code;
    switch(CKey) {
        case sf::Keyboard::E:
            this->bInteract = bPressed;
            break;

        default:
            break;
    }
}


void ShipInput::resetInteract() {
    this->bInteract = false;
}

bool ShipInput::getInteract() {
    return this->bInteract;
}