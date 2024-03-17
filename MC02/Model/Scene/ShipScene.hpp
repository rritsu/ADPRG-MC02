#pragma once

#include "../Scene.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../Entity/Background.hpp"
#include "../Entity/Player.hpp"
#include "../../Controller/Pooling/GameObjectPool.hpp"
#include "../../Controller/Manager/ObjectPoolManager.hpp"

namespace scenes {
    using namespace models;
    using namespace entities;
    using namespace poolables;
    using namespace managers;

    class ShipScene : public Scene {
        public: 
            ShipScene();
        
        private:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
           // void onUnloadObjects();

        private:
            void createBackGround();
            void createPlayer();
            void createObjectPools();
    };
}