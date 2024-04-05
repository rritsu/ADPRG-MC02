#pragma once

#include "iostream"
#include "time.h"
#include "vector"

namespace utilities {
    class Utility {
        public:
            int getRandomNumber(int nLowerbound, int nUpperbound);
            void pushConnectedIndeces(std::vector<int>& vecIndex, int nIndex);

        private:
            static Utility* P_SHARED_INSTANCE;
        
        private:
            Utility();
            Utility(const Utility&);
            Utility& operator = (const Utility&);

        public:
            static Utility* getInstance();
    };
}