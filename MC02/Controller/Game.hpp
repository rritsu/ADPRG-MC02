#pragma once

#include <SFML/Graphics.hpp>


#include "../Model/AnimatedTexture.hpp"
#include "Manager/TextureManager.hpp"
#include "Manager/GameObjectManager.hpp"
#include "Manager/SceneManager.hpp"

#include "../Model/Scene/MainMenuScene.hpp"
#include "../Model/Scene/ShipScene.hpp"
#include "../Model/Scene/RoomScene.hpp"

#include "../Config/Settings.hpp"

namespace controllers {
    using namespace models;
    using namespace managers;
    using namespace entities;
    using namespace scenes;

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