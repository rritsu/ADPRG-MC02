#include "ShipScript.hpp"
using namespace components;

ShipScript::ShipScript(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void ShipScript::perform() {
    ShipInput* pInput = (ShipInput*)this->getOwner()->findComponentByName(this->getOwner()->getName() + " Input");
    Player* pPlayer = (Player*)GameObjectManager::getInstance()->findObjectByName("Player");
    ShipObject* pPortal = (ShipObject*)GameObjectManager::getInstance()->findObjectByName("Portal");

    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }

    else {
        this->applyShade(pPortal);


        if(pInput->getInteract()) {
            pInput->resetInteract();

            if(pPortal->getPlayerCollision()) {
                //SceneManager::getInstance()->loadScene(SceneTag::AREA_SCENE); 
                //start day wowowowowo
                RoomManager::getInstance()->generateArea();
            }
        }

    }
}

void ShipScript::applyShade(ShipObject* pShipObject) {
    if(pShipObject->getPlayerCollision()) 
        pShipObject->getShade()->setShadeSetting(sf::Vector2f(1.05f, 1.05f), COLOR_GREEN);
    else
        pShipObject->getShade()->setShadeSetting(sf::Vector2f(1.05f, 1.05f), COLOR_BLACK);
}

