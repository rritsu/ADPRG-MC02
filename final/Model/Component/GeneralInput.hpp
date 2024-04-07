#pragma once

#include "SFML/Graphics.hpp"
#include "Component.hpp"

namespace components {
    class GeneralInput : public Component {
        protected:
            sf::Event CEvent;

        public:
            GeneralInput(std::string strName);
        
        public:
            void assignEvent(sf::Event CEvent);
            
        public:
            virtual void perform() = 0;
            
    };
}