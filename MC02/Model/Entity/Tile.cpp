#include "Tile.hpp"
using namespace entities;

Tile::Tile(std::string strName, AnimatedTexture* pTexture, sf::Vector2f vecPosition) : GameObject(strName, pTexture) {
    this->vecPosition = vecPosition;
}

void Tile::initialize() {
    this->getSprite()->setPosition(this->vecPosition);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}