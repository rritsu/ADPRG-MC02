#include "RoomInput.hpp"

using namespace components;

RoomInput::RoomInput(std::string strName) : GeneralInput(strName) {
    this->bDoorInteract = false;
}

void RoomInput::perform() {
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

void RoomInput::processKeyInput(bool bPressed) {
    sf::Keyboard::Key CKey = this->CEvent.key.code;

    switch(CKey) {
        case sf::Keyboard::E:
            this->bDoorInteract = bPressed;
            break;

        default:
            break;
    }
}

void RoomInput::resetDoorInteract() {
    this->bDoorInteract = false;
}

bool RoomInput::getDoorInteract() {
    return this->bDoorInteract;
}