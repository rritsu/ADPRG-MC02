#pragma once

#include "../GameObject.hpp"
//#include "../Component/Input/LaptopInput.hpp"
//#include "../Component/Script/LaptopAction.hpp"

namespace entities {
    using namespace models;
    using namespace components;

    class Tile : public GameObject{
        private:
            sf::Vector2f vecPosition;

        public: 
            Tile(std::string strName, AnimatedTexture* pTexture, sf::Vector2f vecPosition);
    
        public:
            void initialize();
    
    };

}