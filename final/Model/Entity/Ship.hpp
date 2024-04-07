#pragma once

#include "../Scene/ShipScene.hpp"
#include "../GameObject.hpp"
#include "../Component/Input/ShipInput.hpp"
#include "../Component/Script/ShipScript.hpp"

namespace entities {
    using namespace models;
    using namespace components;
    using namespace scenes;

    class Ship : public GameObject{
        public: 
            Ship(std::string strName);
    
        public:
            void initialize();
    
    };

}

