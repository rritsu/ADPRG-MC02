#pragma once

namespace managers {
    class AreaManager {
        private:
            

        public:


        private:
            static AreaManager* P_SHARED_INSTANCE;

        private:
            AreaManager();
            AreaManager(const AreaManager&);
            AreaManager& operator = (const AreaManager&);

        public:
            static AreaManager* getInstance();
    };

}
