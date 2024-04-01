#pragma once

#include "iostream"
#include "../EmptyGameObject.hpp"
#include "../Scene.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Pooling/GameObjectPool.hpp"
#include "../../Controller/Manager/ObjectPoolManager.hpp"
#include "../Entity/Background.hpp"
#include "../Entity/Player.hpp"
#include "../Entity/ShipObject.hpp"
#include "../Entity/Tile.hpp"
#include "../Entity/Ship.hpp"



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
            void createNullObjects();
            void createBackGround();
          //  void createGrid();
            void createPlayer();
            void createShip();
            void createShipObjects();
    };
}