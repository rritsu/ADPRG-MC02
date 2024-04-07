#pragma once

#include "GameObject.hpp"

namespace models {
    class EmptyGameObject : public GameObject {
        public:
            EmptyGameObject(std::string strName);
        
        public:
            void initialize();
    };
}