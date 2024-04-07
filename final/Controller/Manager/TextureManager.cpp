#include "TextureManager.hpp"
using namespace managers;


void TextureManager::loadMainMenu() {
    
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Screen/main_menu_bg.png");
    this->mapTexture[AssetType::MAIN_MENU_BACKGROUND].push_back(pTexture);
    
}

void TextureManager::loadLaptopMenu() {
    
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Screen/laptop_menu.png");
    this->mapTexture[AssetType::LAPTOP_BACKGROUND].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::LAPTOP_BACKGROUND);

}

void TextureManager::loadEvaluation() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Screen/quota_reached.png");
    this->mapTexture[AssetType::EVALLUATION_BACKGROUND].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Screen/quota_failed.png");
    this->mapTexture[AssetType::EVALLUATION_BACKGROUND].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::EVALLUATION_BACKGROUND);
}

void TextureManager::loadShip() { 
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Ship/ship-tile.png");
    this->mapTexture[AssetType::SHIP_TILE].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::SHIP_TILE);

/*
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Ship/ship-bg.png");
    this->mapTexture[AssetType::SHIP_BACKGROUND].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::SHIP_BACKGROUND);
*/
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

    this->loadDoors();
    this->loadEntryDoors();

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

void TextureManager::loadDoors() {
    sf::Texture* pTexture = new sf::Texture();
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
}

void TextureManager::loadEntryDoors() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Map/entry-door-top.png");
    this->mapTexture[AssetType::ENTRY_DOOR].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Map/entry-door-left.png");
    this->mapTexture[AssetType::ENTRY_DOOR].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Map/entry-door-bottom.png");
    this->mapTexture[AssetType::ENTRY_DOOR].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Map/entry-door-right.png");
    this->mapTexture[AssetType::ENTRY_DOOR].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::ENTRY_DOOR);
}

void TextureManager::loadScraps() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Scrap/airhorn.png");
    this->mapTexture[AssetType::AIRHORN].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::AIRHORN);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Scrap/axle.png");
    this->mapTexture[AssetType::LARGE_AXLE].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::LARGE_AXLE);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Scrap/metalsheet.png");
    this->mapTexture[AssetType::METAL_SHEET].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::METAL_SHEET);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Scrap/stopsign.png");
    this->mapTexture[AssetType::STOP_SIGN].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::STOP_SIGN);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Scrap/toycube.png");
    this->mapTexture[AssetType::TOY_CUBE].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::TOY_CUBE);
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