#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class BackgroundInput : public GeneralInput {
        private:
            bool bChangeScene;
            bool bMainMenuScene;
            bool bGameScene;

        public:
            BackgroundInput(std::string strName);
        
        public:
            void perform();
        
        private:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed);

        public:
            bool getChangeScene();
            bool getMainMenuScene();
            bool getGameScene();
    };
}
