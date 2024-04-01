#pragma once

#include "iostream"
#include "../Scene.hpp"
#include "../Enum/SceneTag.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Utility/Utility.hpp"
#include "../AnimatedTexture.hpp"
#include "../Entity/Tile.hpp"
#include "../Entity/Player.hpp"
#include "../../Config/Settings.hpp"

namespace scenes {
    using namespace managers;
    using namespace utilities;
    using namespace entities;
    using namespace models;

    class AreaScene : public Scene {
        private:
            int nAreaIndex;
            int nConnectedIndex;
            int nBackIndex;

        public:
            AreaScene(std::vector<int> vecArea, int nAreaIndex, int nBackIndex);

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
        
        private:
            void createGrid();
            void createPlayer();

        public:
            int getAreaIndex();
    };
}
