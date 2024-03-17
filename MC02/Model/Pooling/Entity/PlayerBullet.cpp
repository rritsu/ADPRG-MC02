#include "PlayerBullet.hpp"

using namespace poolables;

PlayerBullet::PlayerBullet(std::string strName, AnimatedTexture* pTexture, Ship* pShip) : PoolableObject(PoolTag::PLAYER_BULLET, strName, pTexture) {
    this->pShip = pShip;
}

void PlayerBullet::initialize() {
    this->centerOrigin();

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    BulletMovement* pBulletMovement = new BulletMovement(this->strName + " Movement");
    this->attachComponent(pBulletMovement);
    

    //BulletMovement* pBulletMovement = new BulletMovement*
}

void PlayerBullet::onActivate() {
   // this->pSprite->setPosition(this->pShip->getSprite()->getPosition().x, this->pShip->getSprite()->getPosition().y);
    float x = this->pShip->getSprite()->getPosition().x;
    this->pSprite->setPosition(this->pShip->getHalfWidth() + x, this->pShip->getSprite()->getPosition().y);
}

void PlayerBullet::onRelease() {
}

PoolableObject* PlayerBullet::clone() {
    PoolableObject* pPoolableObject = new PlayerBullet(this->strName, new AnimatedTexture(*this->pTexture), this->pShip);

    return pPoolableObject;
}