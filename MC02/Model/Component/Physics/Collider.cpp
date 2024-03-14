#include "Collider.hpp"
using namespace components;

Collider::Collider(std::string strName) : Component(strName, ComponentType::PHYSICS) {
    this->pListener = NULL;
    this->COffset = sf::FloatRect{0.0f, 0.0f, 0.0f, 0.0f};
    this->vecCollided = {};
    this->bCleanup = false;
}

void Collider::peform() {

}

bool Collider::isColliding(Collider* pCollider) {
    return false;
}

void Collider::onCollisionEnter(GameObject* pGameObject) {

}

void Collider::onCollisionExit(GameObject* pGameObject) {

}

void Collider::assignListener(CollisionListener* pListener) {
    this->pListener = pListener;
}

sf::FloatRect Collider::getGlobalGrounds() {
    return sf::FloatRect{0.0f, 0.0f, 0.0f, 0.0f};
}