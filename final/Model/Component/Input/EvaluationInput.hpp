#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class EvaluationInput : public GeneralInput {
        private:
            bool bSpace;

        public:
            EvaluationInput(std::string strName);
        
        public:
            void perform();
            void resetSpace();
        
        private:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed);

        public:
            bool getSpace();


    };
}