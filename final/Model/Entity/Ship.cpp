#include "Ship.hpp"
using namespace entities;

Ship::Ship(std::string strName) : GameObject(strName, NULL){}

void Ship::initialize() {
    ShipInput* pShipInput = new ShipInput(this->strName + " Input");
     this->attachComponent(pShipInput);

    ShipScript* pShipScript = new ShipScript(this->strName + " Script");
    this->attachComponent(pShipScript);
    
}