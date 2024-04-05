#include "Border.hpp"

using namespace entities;

Border::Border(std::string strName, sf::FloatRect CBounds) : GameObject(strName, NULL) {
    this->CBounds = CBounds;
}

void Border::initialize() {
    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);

    if(SHOW_COLLIDERS) {        
        sf::RectangleShape* pRectangle = new sf::RectangleShape();
        pRectangle->setSize({this->CBounds.width, this->CBounds.height});
        pRectangle->setPosition({this->CBounds.left, this->CBounds.top});
        pRectangle->setFillColor(sf::Color(255, 0, 0, 150));

        Renderer* pRenderer = new Renderer(this->strName + " Renderer");
        pRenderer->assignDrawable(pRectangle);
        this->attachComponent(pRenderer);
    }
}

void Border::onCollisionEnter(GameObject* pGameObject) {}

void Border::onCollisionExit(GameObject* pGameObject) {}

sf::FloatRect Border::getGlobalBounds() {
    return this->CBounds;
}
