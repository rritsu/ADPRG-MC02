#include "PlayerControls.hpp"

using namespace components;

PlayerControls::PlayerControls(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fSpeed = 300.0f;
}

void PlayerControls::perform() {
    PlayerInput* pPayerInput = (PlayerInput*)this->getOwner()->findComponentByName(this->pOwner->getName() + " Input");
    
    if(pPayerInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();
        
        if(pPayerInput->getUp()) {
             this->getOwner()->getSprite()->move(0.0f, -fOffset);
        }

        if(pPayerInput->getDown())
             this->getOwner()->getSprite()->move(0.0f, fOffset);
        
        if(pPayerInput->getLeft())
            this->getOwner()->getSprite()->move(-fOffset, 0.0f);

        if(pPayerInput->getRight())
            this->getOwner()->getSprite()->move(fOffset, 0.0f);

      //  if(pPayerInput->getSpace()) {
         //   pPayerInput->resetSpace();
          //  ObjectPoolManager::getInstance()->getPool(PoolTag::PLAYER_BULLET)->requestPoolable();
      //  }
    }
}
