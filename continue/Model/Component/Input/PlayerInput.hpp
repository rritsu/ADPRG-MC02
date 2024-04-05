#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        private:
            bool bUp;
            bool bDown;
            bool bLeft;
            bool bRight;
            bool bInteract;
            bool bPickup;
            
        public:
            PlayerInput(std::string strName);

        public:
            void perform();
            void resetInteract();
            void resetMovement();

        private:
            void processKeyInput(bool bPressed);

        public:
            bool getInteract();
            bool getUp();
            bool getDown();
            bool getLeft();
            bool getRight();
    };
}
