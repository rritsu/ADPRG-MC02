#pragma once

#include "../GeneralInput.hpp"
#include "../../Entity/Door.hpp"

namespace components {
    using namespace entities;

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
