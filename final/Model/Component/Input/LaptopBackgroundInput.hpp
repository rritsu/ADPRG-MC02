#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class LaptopBackgroundInput : public GeneralInput {
        private:
            bool bChangeScene;
            bool bMainMenuScene;
            bool bNextDay;

        public:
             LaptopBackgroundInput(std::string strName);
        
        public:
            void perform();
        
        private:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed);

        public:
            bool getChangeScene();
            bool getMenuScene();
            bool isNextDay();
    };
}
