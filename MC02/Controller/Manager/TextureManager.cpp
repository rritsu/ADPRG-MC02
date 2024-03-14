#include "TextureManager.hpp"
using namespace managers;

void TextureManager::loadMainMenu() {}

void TextureManager::loadShip() {}

void TextureManager::unloadAll() {
    for(AssetType EType : this->vecAssetTypes) {
        std::vector<sf::Texture*> vecTextures = this->mapTexture[EType];
        for(int i = 0; i < vecTextures.size(); i++){
            delete this->mapTexture[EType][i];
        }
    }
}

std::vector<sf::Texture*> TextureManager::getTexture(AssetType EType) {
    return this->mapTexture[EType];
}

sf::Texture* TextureManager::getTextureAt(AssetType EType, int nFrame) {
    return this->mapTexture[EType][nFrame];
}




TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;

TextureManager::TextureManager() {}
TextureManager::TextureManager(const TextureManager&) {}

TextureManager* TextureManager::getInstance(){
    if(P_SHARED_INSTANCE == NULL);
        P_SHARED_INSTANCE = new TextureManager();

    return P_SHARED_INSTANCE; 
}