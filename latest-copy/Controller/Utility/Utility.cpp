#include "Utility.hpp"

using namespace utilities;

int Utility::getRandomNumber(int nLowerbound, int nUpperbound) {
   srand(time(0));
   int nRet = rand() % (nUpperbound - nLowerbound + 1);
    std::cout << "nRet " << nRet << std::endl;
    return nRet;
}

void Utility::pushConnectedIndeces(std::vector<int>& vecIndex, int nIndex) {
    switch(nIndex) {
        case 1:
            vecIndex.push_back(2);
            vecIndex.push_back(4);
            break;
            
        case 2:
            vecIndex.push_back(1);
            vecIndex.push_back(3);
            break;

        case 3:
            vecIndex.push_back(2);
            vecIndex.push_back(6);
            break;

        case 4:
            vecIndex.push_back(1);
            vecIndex.push_back(7);
            break;

        case 6:
            vecIndex.push_back(3);
            vecIndex.push_back(9);
            break;

        case 7:
            vecIndex.push_back(4);
            vecIndex.push_back(8);
            break;

        case 8:
            vecIndex.push_back(7);
            vecIndex.push_back(9);
            break;

        case 9:
            vecIndex.push_back(6);
            vecIndex.push_back(8);
            break;

        default:
            break;
    }
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
