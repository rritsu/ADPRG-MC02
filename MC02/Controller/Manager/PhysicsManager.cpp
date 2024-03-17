#include "PhysicsManager.hpp"
using namespace managers;

void PhysicsManager::perform() {
    
}

PhysicsManager* PhysicsManager::P_SHARED_INSTANCE = NULL;
PhysicsManager::PhysicsManager(std::string strName) : Component(strName, ComponentType::SCRIPT){}
PhysicsManager::PhysicsManager(const PhysicsManager& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

PhysicsManager* PhysicsManager::getInstance(std::string strName){
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new PhysicsManager(strName);
    
    return P_SHARED_INSTANCE;
}

void PhysicsManager::initialize(std::string strName, GameObject* pHolder) {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new PhysicsManager(strName);
        pHolder->attachComponent(P_SHARED_INSTANCE);
    }
}
