#include "BackgroundInput.hpp"

using namespace components;

BackgroundInput::BackgroundInput(std::string strName) : GeneralInput(strName) {
    this->bEnter = false;
}

void BackgroundInput::perform() {
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

void BackgroundInput::processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed) {
    switch(CKey){
        case sf::Keyboard::Enter:
            this->bEnter = bPressed;
            break;

        default:
            break;
    }
}


void BackgroundInput::resetEnter() {
    this->bEnter = false;
}

bool BackgroundInput::getEnter() {
    return this->bEnter;
}