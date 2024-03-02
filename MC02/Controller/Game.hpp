#pragma once

#include "../Model/GameObject.hpp"
#include "Manager/TextureManager.hpp"
#include "Manager/GameObjectManager.hpp"
#include "Manager/SceneManager.hpp"

namespace controllers {
    using namespace models;
    using namespace managers;

    class Game {
        private:
            sf::RenderWindow CWindow;

        public:
            Game();
        
        public:
            void run();

        private:
            void processEvents();
            void update(sf::Time tDeltaTime);
            void render();
    };
}