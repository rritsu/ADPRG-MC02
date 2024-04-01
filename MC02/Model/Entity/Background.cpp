#include "Background.hpp"
using namespace entities;

Background::Background(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture){}

void Background::initialize() {
    BackgroundInput* pInput = new BackgroundInput(this->strName + " Input");
    this->attachComponent(pInput);

    //BackgroundAction* pAction = new BackgroundAction(this->strName + " Action");
    //this->attachComponent(pAction);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}