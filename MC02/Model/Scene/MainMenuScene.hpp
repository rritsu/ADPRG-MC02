#pragma once

#include "../Scene.hpp"
#include "../Enum/SceneTag.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../AnimatedTexture.hpp"
#include "../Entity/Background.hpp"

namespace scenes {
    using namespace managers;
    using namespace entities;
    using namespace models;

    class MainMenuScene : public Scene {
        public:
            MainMenuScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
           // void onUnloadObjects();
        
        private:
            void createBackground();
    };
}
