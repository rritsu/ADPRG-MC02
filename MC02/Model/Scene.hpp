#pragma once

#include "Enum/SceneTag.hpp"
#include "GameObject.hpp"
#include "../Controller/Manager/GameObjectManager.hpp"

namespace models {
    using namespace managers;

    class Scene {
        private:
            SceneTag ETag;
        
        public:
            Scene(SceneTag ETag);

        public:
            virtual void onLoadResources() = 0;
            virtual void onLoadObjects() = 0;
            virtual void onUnloadResources() = 0;
            virtual void onUnloadObjects();
        
        protected:
            void registerObject(GameObject* pGameObject);

        public:
            SceneTag getTag();
    };
}