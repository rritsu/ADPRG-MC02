#pragma once
/*
#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Input/ShipInput.hpp"
#include "../Component/Script/ShipScript.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;
    using namespace components;

    class Ship : public GameObject {
        private:

        public:
            Ship(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();

    };
}
*/


#include "../GameObject.hpp"
#include "../Component/Input/ShipInput.hpp"
#include "../Component/Script/ShipScript.hpp"
//#include "../Component/Input/ShipInput.hpp"
//#include "../Component/Script/ShipScript.hpp"

namespace entities {
    using namespace models;
    using namespace components;

    class Ship : public GameObject{
        public: 
            Ship(std::string strName, AnimatedTexture* pTexture);
    
        public:
            void initialize();
    
    };

}

