#pragma once

#include "../GameObject.hpp"

namespace interfaces {
    using namespace models;
    class IPickupable {
        public:
            virtual void onPickup(GameObject* pGameObject) = 0;
            virtual void onDrop(GameObject* pGameObject) = 0;
    };
}