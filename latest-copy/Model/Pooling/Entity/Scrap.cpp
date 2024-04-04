#include "Scrap.hpp"

using namespace poolables;

Scrap::Scrap(std::string strName, AnimatedTexture* pTexture) : PoolableObject(PoolTag::SCRAP_POOL, strName, pTexture) {
    this->nValue = 0;
    this->ETag = ScrapTag::NONE;
    this->bPickedup = false;
    this->vecPosition = new sf::Vector2f(0.0f, 0.0f);
    this->nRoomIndex = 0;
}
void Scrap::initialize() {
    AnimatedTexture* pTexture = NULL;
    int nRandom = Utility::getInstance()->getRandomNumber(0, 4);
    this->centerOrigin();

    switch(nRandom){
        case 0:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::METAL_SHEET));
            this->pTexture = pTexture;
            this->nValue = 16;
            this->ETag = ScrapTag::METAL_SHEET;
            break;

        case 1:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::AIRHORN));
            this->pTexture = pTexture;
            this->nValue = 62;
            this->ETag = ScrapTag::AIRHORN;
            break;

        case 2:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::STOP_SIGN));
            this->pTexture = pTexture;
            this->nValue = 36;
            this->ETag = ScrapTag::STOP_SIGN;
            break;

        case 3:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::LARGE_AXLE));
            this->pTexture = pTexture;
            this->nValue = 48;
            this->ETag = ScrapTag::LARGE_AXLE;
            break;

        case 4:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TOY_CUBE));
            this->pTexture = pTexture;
            this->nValue = 34;
            this->ETag = ScrapTag::TOY_CUBE;
            break;
    };

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);

}

void Scrap::onActivate() {

    Collider* pCollider = (Collider*)this->findComponentByName(this->strName + " Collider");
    PhysicsManager::getInstance()->trackCollider(pCollider);
    
}

void Scrap::onRelease() {
    Collider* pCollider = (Collider*)this->findComponentByName(this->strName + " Collider");
    PhysicsManager::getInstance()->untrackCollider(pCollider);

}

void Scrap::onCollisionEnter(GameObject* pGameObject) {

}

void Scrap::onCollisionExit(GameObject* pGameObject) {

}

PoolableObject* Scrap::clone() {

    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::METAL_SHEET));
    PoolableObject* pScrap = new Scrap(this->strName, pTexture);
    return pScrap;  
}


int Scrap::getValue() {
    return this->nValue;
}

ScrapTag Scrap::getTag() {
    return this->ETag;
}

void Scrap::setRoomIndex(int nRoomIndex) {
    this->nRoomIndex = nRoomIndex;
}

