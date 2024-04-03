#include "TextureManager.hpp"
using namespace managers;


void TextureManager::loadMainMenu() {
    
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/main_menu_background.png");
    this->mapTexture[AssetType::MAIN_MENU_BACKGROUND].push_back(pTexture);
    

}

void TextureManager::loadShip() { 
  //  sf::Texture* pTexture = new sf::Texture();
  //  pTexture->loadFromFile("View/Image/Map/Ship.png");
  //  this->mapTexture[AssetType::SHIP_BACKGROUND].push_back(pTexture);
  //  this->vecAssetTypes.push_back(AssetType::SHIP_BACKGROUND);

    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Ship/ship-tile.png");
    this->mapTexture[AssetType::SHIP_TILE].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::SHIP_TILE);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Ship/ship-bg.png");
    this->mapTexture[AssetType::SHIP_BACKGROUND].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::SHIP_BACKGROUND);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Interact/laptop.png");
    this->mapTexture[AssetType::LAPTOP].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::LAPTOP);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Ship/test1.png");
    this->mapTexture[AssetType::PORTAL].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::PORTAL);
    
    this->loadPlayer();
}

void TextureManager::loadArea() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Map/area-tile.png");
    this->mapTexture[AssetType::AREA_TILE].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::AREA_TILE);

    //door
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Map/door-top.png");
    this->mapTexture[AssetType::DOOR].push_back(pTexture);
    
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Map/door-left.png");
    this->mapTexture[AssetType::DOOR].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Map/door-bottom.png");
    this->mapTexture[AssetType::DOOR].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Map/door-right.png");
    this->mapTexture[AssetType::DOOR].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::DOOR);

    this->loadPlayer();
}

void TextureManager::loadPlayer() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Player/right.png");
    this->mapTexture[AssetType::PLAYER].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Player/left.png");
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

    this->vecAssetTypes.clear();
    this->mapTexture.clear();
}

TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;
TextureManager::TextureManager() {}
TextureManager::TextureManager(const TextureManager&) {}

TextureManager* TextureManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new TextureManager();

    return P_SHARED_INSTANCE;
}