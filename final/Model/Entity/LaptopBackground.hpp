#pragma once

#include "../GameObject.hpp"
#include "../Component/Input/LaptopBackgroundInput.hpp"
#include "../Component/Script/LaptopBackgroundAction.hpp"

namespace entities {
    using namespace models;
    using namespace components;

    class LaptopBackground : public GameObject{
        public: 
            LaptopBackground(std::string strName, AnimatedTexture* pTexture);
    
        public:
            void initialize();
    
    };

}