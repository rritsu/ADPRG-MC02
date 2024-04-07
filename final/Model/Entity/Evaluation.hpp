#pragma once

#include "../GameObject.hpp"
#include "../Component/Input/EvaluationInput.hpp"
#include "../Component/Script/EvaluationAction.hpp"

namespace entities {
    using namespace models;
    using namespace components;

    class Evaluation : public GameObject{
        public: 
            Evaluation(std::string strName, AnimatedTexture* pTexture);
    
        public:
            void initialize();
    
    };

}