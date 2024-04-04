#include "Ship.hpp"
using namespace entities;

Ship::Ship(std::string strName) : GameObject(strName, NULL){}

void Ship::initialize() {
   // BackgroundInput* pInput = new BackgroundInput(this->strName + " Input");
    //this->attachComponent(pInput);

    //BackgroundAction* pAction = new BackgroundAction(this->strName + " Action");
    //this->attachComponent(pAction);
    ShipInput* pShipInput = new ShipInput(this->strName + " Input");
     this->attachComponent(pShipInput);

    ShipScript* pShipScript = new ShipScript(this->strName + " Script");
    this->attachComponent(pShipScript);
    
   // Renderer* pRenderer = new Renderer(this->strName + " Renderer");
   // pRenderer->assignDrawable(this->pSprite);
    //this->attachComponent(pRenderer);
}