#pragma once

#include <unordered_map>
#include "../../Model/Enum/SceneTag.hpp"
#include "../../Model/Scene.hpp"

namespace managers {
    using namespace models;

    class SceneManager {
        private:
            std::unordered_map<SceneTag, Scene*> mapScenes;
            Scene* pActiveScene;
            bool bLoading;
            SceneTag ESceneToLoad;

        public:
            void registerScene(Scene* pScene);
            void loadScene(SceneTag ETag);
            void unloadScene();
            void checkLoadScene();
        
        public:
            bool getLoaded(SceneTag ETag);


        private:
            static SceneManager* P_SHARED_INSTANCE;

        private:
            SceneManager();
            SceneManager(const SceneManager&);
            SceneManager& operator = (const SceneManager&);

        public:
            static SceneManager* getInstance();

    };
}
