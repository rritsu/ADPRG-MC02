#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        private:
            bool bSpace;
            bool bUp;
            bool bDown;
            bool bLeft;
            bool bRight;
            
        public:
            PlayerInput(std::string strName);

        public:
            void perform();
            void resetSpace();

        private:
            void processKeyInput(bool bPressed);

        public:
            bool getSpace();
            bool getUp();
            bool getDown();
            bool getLeft();
            bool getRight();
    };
}
