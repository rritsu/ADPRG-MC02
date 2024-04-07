#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "../../Model/Enum/AssetType.hpp"
#include "../../Model/Enum/SceneTag.hpp"
#include "../../Model/AnimatedTexture.hpp"

namespace managers {
    using namespace models;

    class TextureManager {
        private: 
            std::unordered_map<AssetType, std::vector<sf::Texture*>> mapTexture;
            std::vector<AssetType> vecAssetTypes;

        public:
            void loadMainMenu();
            void loadLaptopMenu();
            void loadEvaluation();
            void loadShip();
            void loadArea();
            void loadScraps();
            void loadPlayer();
            std::vector<sf::Texture*> getTexture(AssetType EType);
            sf::Texture* getTextureAt(AssetType EType, int nFrame);
            void unloadAll();
        
        
        private:
            void loadDoors();
            void loadEntryDoors();

        private:
            static TextureManager* P_SHARED_INSTANCE;

        private:
            TextureManager();
            TextureManager(const TextureManager&);
            TextureManager& operator = (const TextureManager&);

        public:
            static TextureManager* getInstance();

    };

}