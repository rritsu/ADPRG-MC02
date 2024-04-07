#include "Utility.hpp"

using namespace utilities;

int Utility::getRandomNumber(int nLowerbound, int nUpperbound) {
    int nRet = rand() % (nUpperbound - nLowerbound + 1);
    return nRet;
}


//SINGLETON
Utility* Utility::P_SHARED_INSTANCE = NULL;
Utility::Utility() {}
Utility::Utility(const Utility&) {}

Utility* Utility::getInstance() {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new Utility();
    }

    return P_SHARED_INSTANCE;
}
