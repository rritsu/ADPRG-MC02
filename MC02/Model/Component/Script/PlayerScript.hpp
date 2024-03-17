#pragma once

#include "../Component.hpp"
#include "../Input/PlayerInput.hpp"

namespace components {
    class PlayerScript : public Component {
        private:
            float fSpeed;
    
        public:
            PlayerScript(std::string strName);

        public:
            void perform();
    };
}