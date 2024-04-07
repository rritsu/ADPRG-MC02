#include "EvaluationInput.hpp"

using namespace components;

EvaluationInput::EvaluationInput(std::string strName) : GeneralInput(strName) {
    this->bSpace = false;
}

void EvaluationInput::perform() {
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

void EvaluationInput::processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed) {
    switch(CKey){
        case sf::Keyboard::Space:
            this->bSpace = bPressed;
            break;

        default:
            break;
    }
}


void EvaluationInput::resetSpace() {
    this->bSpace = false;
}


bool EvaluationInput::getSpace() {
    return this->bSpace;
}