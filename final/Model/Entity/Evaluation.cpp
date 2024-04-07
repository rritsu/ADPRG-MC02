#include "Evaluation.hpp"
using namespace entities;

Evaluation::Evaluation(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture){}

void Evaluation::initialize() {
    this->centerOrigin();
    this->getSprite()->setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);


    if(LevelManager::getInstance()->getHasFailed())
        this->setFrame(1);
    else
        this->setFrame(0);

    EvaluationInput* pInput = new EvaluationInput(this->strName + " Input");
    this->attachComponent(pInput);

    EvaluationAction* pAction = new EvaluationAction(this->strName + " Action");
    this->attachComponent(pAction);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}