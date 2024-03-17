#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        private:
            bool bMovingUp;
            bool bMovingDown;
            bool bMovingLeft;
            bool bMovingRight;

        public:
            PlayerInput(std::string strName);

        public:
            void perform();
            
        private:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed);
        
        public:
            bool getMovingUp();
            void setMovingUp(bool bMovingUp);
            bool getMovingDown();
            void setMovingDown(bool bMovingDown);
            bool getMovingLeft();
            void setMovingLeft(bool bMovingLeft);
            bool getMovingRight();
            void setMovingRight(bool bMovingRight);

    };
}