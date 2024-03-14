#pragma once

#include "../../Model/Component/Component.hpp"
#include "../../Model/GameObject.hpp"

namespace managers {
    using namespace components;
    using namespace models;

    class PhysicsManager : public Component {
        public:
            void perform();

        private:
            static PhysicsManager* P_SHARED_INSTANCE;

        private:
            PhysicsManager(std::string strName);
            PhysicsManager(const PhysicsManager& CObject);
            PhysicsManager& operator = (const PhysicsManager& CObject);
        
        public:
            static PhysicsManager* getInstance(std::string strName);
            static void initialize(std::string strName, GameObject* pHolder);

    };
}