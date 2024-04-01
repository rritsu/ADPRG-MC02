#pragma once

namespace managers {
    class LevelManager {
        private:
            


        private:
            static LevelManager* P_SHARED_INSTANCE;

        private:
            LevelManager();
            LevelManager(const LevelManager&);
            LevelManager& operator = (const LevelManager&);

        public:
            static LevelManager* getInstance();

    };
}