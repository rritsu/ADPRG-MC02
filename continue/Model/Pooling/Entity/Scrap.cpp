#include "Scrap.hpp"

using namespace poolables;

Scrap::Scrap(std::string strName, AnimatedTexture* pTexture, ScrapTag ETag) : PoolableObject(PoolTag::SCRAP_POOL, strName, pTexture) {
    this->ETag = ETag;
    this->bInRange = false;
    this->bPickedup = false;
    this->vecPosition = new sf::Vector2f(0.0f, 0.0f);
    this->nRoomIndex = 0;
}
void Scrap::initialize() {

    //this->centerOrigin();

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    //PhysicsManager::getInstance()->trackCollider(pCollider);

}

void Scrap::onActivate() {

    Collider* pCollider = (Collider*)this->findComponentByName(this->strName + " Collider");
    PhysicsManager::getInstance()->trackCollider(pCollider);
    
}

void Scrap::onRelease() {
    // Collider* pCollider = (Collider*)this->findComponentByName(this->strName + " Collider");
    // PhysicsManager::getInstance()->untrackCollider(pCollider);


}

void Scrap::onCollisionEnter(GameObject* pGameObject) {
    if(pGameObject->getName() == "Player") {
        this->bInRange = true;
        std::cout << "scrap touch" << std::endl;
    }
}

void Scrap::onCollisionExit(GameObject* pGameObject) {
    if(pGameObject->getName() == "Player") {
        this->bInRange = false;
    }
}


void Scrap::onPickup(GameObject* pGameObject) {

    this->bInRange = false;
    Collider* pCollider = (Collider*)this->findComponentByName(this->strName + " Collider");
    PhysicsManager::getInstance()->untrackCollider(pCollider);

}

void Scrap::onDrop(GameObject* pGameObject) {

    this->bInRange = true;
    this->getSprite()->setPosition(pGameObject->getSprite()->getPosition());
    Collider* pCollider = (Collider*)this->findComponentByName(this->strName + " Collider");
    PhysicsManager::getInstance()->trackCollider(pCollider);
}


PoolableObject* Scrap::clone() {

    int nRandom = Utility::getInstance()->getRandomNumber(0, 4);

    switch(nRandom){
        case 0:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::METAL_SHEET));
            this->pTexture = pTexture;
            this->ETag = ScrapTag::METAL_SHEET;
            break;

        case 1:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::AIRHORN));
            this->pTexture = pTexture;
            this->ETag = ScrapTag::AIRHORN;
            break;

        case 2:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::STOP_SIGN));
            this->pTexture = pTexture;
            this->ETag = ScrapTag::STOP_SIGN;
            break;

        case 3:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::LARGE_AXLE));
            this->pTexture = pTexture;
            this->ETag = ScrapTag::LARGE_AXLE;
            break;

        case 4:
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TOY_CUBE));
            this->pTexture = pTexture;
            this->ETag = ScrapTag::TOY_CUBE;
            break;
    };

    PoolableObject* pScrap = new Scrap(this->strName, pTexture, ETag);
    return pScrap;  
}

ScrapTag Scrap::getTag() {
    return this->ETag;
}

int Scrap::getRoomIndex() {
    return this->nRoomIndex;
}

bool Scrap::IsInRange(){
    return this->bInRange;
}

void Scrap::setTag(ScrapTag ETag){

    AnimatedTexture* pTexture;
    Renderer* pRenderer = (Renderer*)this->findComponentByName(this->strName + " Renderer");

    this->ETag = ETag;

    switch(ETag){

        case(ScrapTag::AIRHORN):
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::AIRHORN));
            this->pTexture = pTexture;
            this->pSprite->setTexture(*this->pTexture->getFrame(), true);
            pRenderer->assignDrawable(this->pSprite);
            break;
        
        case(ScrapTag::STOP_SIGN):
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::STOP_SIGN));
            this->pTexture = pTexture;
            this->pSprite->setTexture(*this->pTexture->getFrame(), true);
            pRenderer->assignDrawable(this->pSprite);
            break;
        
        case(ScrapTag::LARGE_AXLE):
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::LARGE_AXLE));
            this->pTexture = pTexture;
            this->pSprite->setTexture(*this->pTexture->getFrame(), true);
            pRenderer->assignDrawable(this->pSprite);
            break;
        
        case(ScrapTag::METAL_SHEET):
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::METAL_SHEET));
            this->pTexture = pTexture;
            this->pSprite->setTexture(*this->pTexture->getFrame(), true);
            pRenderer->assignDrawable(this->pSprite);
            break;

        case(ScrapTag::TOY_CUBE):
            pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TOY_CUBE));
            this->pTexture = pTexture;
            this->pSprite->setTexture(*this->pTexture->getFrame(), true);
            pRenderer->assignDrawable(this->pSprite);
            break;

    };
}

void Scrap::setRoomIndex(int nRoomIndex) {
    this->nRoomIndex = nRoomIndex;
}


