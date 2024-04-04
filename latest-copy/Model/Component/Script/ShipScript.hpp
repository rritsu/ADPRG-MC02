#pragma once

#include "../../Enum/ComponentType.hpp"

#include "../Component.hpp"
#include "../Input/ShipInput.hpp"
#include "../../Entity/ShipObject.hpp"
#include "../../Entity/Player.hpp"
#include "../../Entity/Ship.hpp"
#include "../../../Controller/Manager/GameObjectManager.hpp" 
#include "../../../Controller/Manager/SceneManager.hpp" 
#include "../../../Controller/Manager/AreaManager.hpp" 
#include "../../../Config/Theme.hpp"


namespace components {
    using namespace entities;
    using namespace managers;

    class ShipScript : public Component {
        public:
            ShipScript(std::string strName);

        public:
            void perform();

        private:
            void applyShade(ShipObject* pShipObject);
    
    };
}