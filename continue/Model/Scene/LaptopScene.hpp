#pragma once

#include "../Scene.hpp"
#include "../Enum/SceneTag.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../AnimatedTexture.hpp"
#include "../Entity/LaptopBackground.hpp"

namespace scenes {
    using namespace managers;
    using namespace entities;
    using namespace models;

    class LaptopScene : public Scene {
        public:
            LaptopScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
           // void onUnloadObjects();
        
        private:
            void createBackground();
    };
}