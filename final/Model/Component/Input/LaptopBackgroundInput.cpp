#include "LaptopBackgroundInput.hpp"

using namespace components;

LaptopBackgroundInput::LaptopBackgroundInput(std::string strName) : GeneralInput(strName) {
    this->bMainMenuScene = false;
    this->bNextDay = false;
}

void LaptopBackgroundInput::perform() {
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

void LaptopBackgroundInput::processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed) {
    switch(CKey){
        case sf::Keyboard::Space:
            this->bMainMenuScene = bPressed;
            break;
        case sf::Keyboard::C:
            this->bNextDay = bPressed;
            break;

        default:
            break;
    }
}

bool LaptopBackgroundInput::getChangeScene() {
    return this->bChangeScene;
}

bool LaptopBackgroundInput::getMenuScene() {
    return this->bMainMenuScene;
}

bool LaptopBackgroundInput::isNextDay() {
    return this->bNextDay;
}