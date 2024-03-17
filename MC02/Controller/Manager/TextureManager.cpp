#include "TextureManager.hpp"
using namespace managers;


void TextureManager::loadMainMenu() {
    /*
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/main_menu_background.png");
    this->mapTexture[AssetType::MAIN_MENU_BACKGROUND].push_back(pTexture);
    */

}

void TextureManager::loadShip() {
    //background
    /*
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/game_background.png");
    this->mapTexture[AssetType::GAME_BACKGROUND].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::GAME_BACKGROUND);
*/


    //player
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Player/idle.png");
    this->mapTexture[AssetType::PLAYER].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::PLAYER);
}

std::vector<sf::Texture*> TextureManager::getTexture(AssetType EType) {
    return this->mapTexture[EType];
}

sf::Texture* TextureManager::getTextureAt(AssetType EType, int nFrame) {
    return this->mapTexture[EType][nFrame];
}

void TextureManager::unloadAll() {
    for(AssetType EType : this->vecAssetTypes) {
        std::vector<sf::Texture*> vecTextures = this->mapTexture[EType];
        for(int i = 0; i < vecTextures.size(); i++) {
            delete this->mapTexture[EType][i];
        }
    }
}

TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;
TextureManager::TextureManager() {}
TextureManager::TextureManager(const TextureManager&) {}

TextureManager* TextureManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new TextureManager();

    return P_SHARED_INSTANCE;
}