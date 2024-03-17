    #include "BackgroundInput.hpp"
using namespace components;

BackgroundInput::BackgroundInput(std::string strName) : GeneralInput(strName) {
    this->bMainMenuScene = false;
    this->bGameScene = false;
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
        case sf::Keyboard::Space:
            this->bMainMenuScene = bPressed;
            break;
        case sf::Keyboard::Q:
            this->bGameScene = bPressed;
            break;

        default:
            break;
    }
}

bool BackgroundInput::getChangeScene() {
    return this->bChangeScene;
}

bool BackgroundInput::getMainMenuScene() {
    return this->bMainMenuScene;
}

bool BackgroundInput::getGameScene() {
    return this->bGameScene;
}