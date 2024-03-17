#pragma once

#include "../../Model/GameObject.hpp"
#include "../../Model/Component/Component.hpp"
#include "../../Model/Enum/ComponentType.hpp"

namespace managers {
    using namespace models;
    using namespace components;

    class PhysicsManager : public Component {
        private:
            std::string strName;

        public:
            void perform();

//public:
          //  static void initialize(std::string strName, GameObject* pHolder);

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


        