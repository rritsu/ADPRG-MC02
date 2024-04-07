#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class BackgroundInput : public GeneralInput {
        private:
            bool bEnter;
            bool bQuit;

        public:
            BackgroundInput(std::string strName);
        
        public:
            void perform();
            void resetEnter();
            void resetSpace();
        
        private:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed);

        public:
            bool getEnter();
            bool getQuit();


    };
}
