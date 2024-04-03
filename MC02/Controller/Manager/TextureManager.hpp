#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "../../Model/Enum/AssetType.hpp"
#include "../../Model/Enum/SceneTag.hpp"

namespace managers {
    class TextureManager {
        private: 
            std::unordered_map<AssetType, std::vector<sf::Texture*>> mapTexture;
            std::vector<AssetType> vecAssetTypes;

        public:
            void loadMainMenu();
            void loadShip();
            void loadArea();
            void loadScrap();
            std::vector<sf::Texture*> getTexture(AssetType EType);
            sf::Texture* getTextureAt(AssetType EType, int nFrame);
            void unloadAll();
        
        private:
            void loadPlayer();

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