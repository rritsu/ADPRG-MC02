#include "Border.hpp"

using namespace entities;

Border::Border(std::string strName) : GameObject(strName, NULL) {

}

void Border::initialize() {
    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
}

void Border::onCollisionEnter(GameObject* pGameObject) {
    
}

void Border::onCollisionExit(GameObject* pGameObject) {}