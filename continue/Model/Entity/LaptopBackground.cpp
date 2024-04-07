#include "LaptopBackground.hpp"
using namespace entities;

LaptopBackground::LaptopBackground(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture){}

void LaptopBackground::initialize() {
    this->centerOrigin();
    this->getSprite()->setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    LaptopBackgroundInput* pInput = new LaptopBackgroundInput(this->strName + " Input");
    this->attachComponent(pInput);

    LaptopBackgroundAction* pAction = new LaptopBackgroundAction(this->strName + " Action");
    this->attachComponent(pAction);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}