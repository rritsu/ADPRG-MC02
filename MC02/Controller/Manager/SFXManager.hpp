#pragma once

#include "../../Model/Enum/SFXType.hpp"

namespace controllers {
    class SFXManager {
        private:
            std::unordered_map<SFXType, sf::Sound*> mapSound;
            std::vector<sf::Sound*> vecSound;

        public:
            void loadMainMenu();
            void loadGame();
            void unloadAll();
            sf::Sound* getSound(SFXType EType);

        private:
            void create(SFXType EType, std::string strPath);
            void add(SFXType EType, sf::Sound* pSound);

        /* * * * * * * * * * * * * * * * * * * * * 
         *       SINGLETON-RELATED CONTENT       * 
         * * * * * * * * * * * * * * * * * * * * */
        private:
            static SFXManager* P_SHARED_INSTANCE;

        private:
            SFXManager();
            SFXManager(const SFXManager&);
            SFXManager& operator = (const SFXManager&);

        public:
            static SFXManager* getInstance();
    };
}
