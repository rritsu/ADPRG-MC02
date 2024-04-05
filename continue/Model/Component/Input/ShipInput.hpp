#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class ShipInput : public GeneralInput {
        private:
            bool bInteract;
            
        public:
            ShipInput(std::string strName);

        public:
            void perform();
            void resetInteract();

        private:
            void processKeyInput(bool bPressed);

        public:
            bool getInteract();
    };
}