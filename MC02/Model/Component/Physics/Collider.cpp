#include "Collider.hpp"
using namespace components;

Collider::Collider(std::string strName) : Component(strName, ComponentType::PHYSICS) {
    this->pListener = NULL;
    this->COffset = sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f);
    this->vecCollided = {};
    this->bCleanUp = false;
}

void Collider::perform() {}


bool Collider:: isColliding(Collider* pCollider) {
    return false;
}


void Collider:: onColllisionEnter(GameObject* pGameObject) {}


void Collider:: onCollisionExit(GameObject* pGameObject) {}


void Collider:: assignListener(CollisionListener* pListener) {
    this->pListener = pListener;
}


sf::FloatRect Collider:: getGlobalBounds() {
    return sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f);
}