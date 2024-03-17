#pragma once

#include "../Scene.hpp"
#include "../AnimatedTexture.hpp"
#include "../Entity/Player.hpp"
#include "../../Controller/Manager/TextureManager.hpp"

namespace scenes {
    using namespace models;
    using namespace entities;
    using namespace managers;
    
    class ShipScene : public Scene {
        public:
            ShipScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();

        private:
            void createPlayer();
    };
} 