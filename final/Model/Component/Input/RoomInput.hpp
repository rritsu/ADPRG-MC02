#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class RoomInput : public GeneralInput {
        private:
            bool bDoorInteract;
        
        public:
            RoomInput(std::string strName);

        public: 
            void perform();
            void resetDoorInteract();

        private:
            void processKeyInput(bool bPressed);

        public:
            bool getDoorInteract();
    };
}