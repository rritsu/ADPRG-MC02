#include "RoomManager.hpp"

using namespace managers;

void RoomManager::generateRooms() { 
    this->generateRoomIndeces();
    this->setCurrentRoom(this->nEntryRoom);
   // SceneManager::getInstance()->loadScene(this->getRoomTag(this->nEntryRoom));
    std::cout << "entryyy " << this->nEntryRoom << std::endl;
}

void RoomManager::generateRoomIndeces() {
    this->initializeIndeces();
    std::vector<int> vecRemove = this->initializeRemove();

    for(int i = 0; i < vecRemove.size(); i++) {
        std::cout << "remove " << vecRemove[i] << std::endl; 
    }

    this->removeIndeces(vecRemove);
    this->instantiateRooms();
}

std::vector<int> RoomManager::initializeRemove() {
    int nIndex = -1, nTempIndex = -1;
    std::vector<int> vecRemove = {};
    std::vector<int> vecAdjacent = {};
 
    int nNumRemove = Utility::getInstance()->getRandomNumber(0, 5);
    std::cout << "numRemove: " << nNumRemove << std::endl;

    if(nNumRemove != 0) {
        do{
            nIndex = Utility::getInstance()->getRandomNumber(1, 10);
        }while(nIndex == 0);
    }

    for(int i = 0; i < nNumRemove; i++) {
        vecAdjacent = this->getAdjacentRooms(nIndex);   
        vecRemove.push_back(nIndex);

        do{
            nTempIndex = Utility::getInstance()->getRandomNumber(0 , vecAdjacent.size() - 1);
        }while(this->checkDuplicate(vecAdjacent[nTempIndex], vecRemove) || vecAdjacent[nTempIndex] == 5);

        nIndex = vecAdjacent[nTempIndex];
        vecAdjacent.clear();
    }
    
    return vecRemove;
}

void RoomManager::removeIndeces(std::vector<int> vecRemove) {
    int k = 0;
    bool bErase = false;
    for(int i = 0; i < vecRemove.size(); i++) {
        for(int j = 0; j < this->vecIndeces.size(); j++) {
            if(vecRemove[i] == this->vecIndeces[j] && bErase == false) {
                bErase = true;
                k = j;
            }
        }
        if(bErase == true) {
            this->vecIndeces.erase(this->vecIndeces.begin() + k);
        }

        bErase = false;
    }

    std::cout << std::endl;
    std::cout << "size " << this->vecIndeces.size() << std::endl;
    for(int i = 0; i < this->vecIndeces.size(); i++) {
        std::cout << "room " << this->vecIndeces[i] << std::endl;
    }
}

void RoomManager::instantiateRooms() {
    int nTempIndex = -1;

    for(int i = 0; i < this->vecIndeces.size(); i++) {
        int nRoomIndex = this->vecIndeces[i];
        Room* pRoom = new Room("Room "+std::to_string(nRoomIndex), NULL, nRoomIndex);
        SceneManager::getInstance()->registerScene(new RoomScene(this->getRoomTag(nRoomIndex), nRoomIndex));
        this->addRoom(pRoom);

   
 
    }

    //randomize entry room
    do{
        nTempIndex = Utility::getInstance()->getRandomNumber(0 , this->vecIndeces.size() - 1);
    }while(this->vecIndeces[nTempIndex] == 5);

    this->nEntryRoom = this->vecIndeces[nTempIndex];
    Room* pRoom = this->findRoomByIndex(this->vecIndeces[nTempIndex]);
    pRoom->setHasEntryDoor(true);
}


void RoomManager::addRoom(Room* pRoom) {
    this->mapRooms[pRoom->getRoomIndex()] = pRoom;
    this->vecRooms.push_back(pRoom);
   // GameObjectManager::getInstance()->addObject(pRoom);
 //   pRoom->initialize();
}

Room* RoomManager::findRoomByIndex(int nRoomIndex) {
    return this->mapRooms[nRoomIndex];
}

void RoomManager::deleteAllRooms() {
    std::vector<Room*> vecRooms = this->vecRooms;

    for(int i = 0; i < vecRooms.size(); i++) {
        delete this->vecRooms[i];
    }

    this->vecIndeces.clear();
    this->vecRooms.clear();
    this->mapRooms.clear();

}

std::string RoomManager::determineEntryDoor(int nRoomIndex) {
    std::string sRet = "";

    if(nRoomIndex < 4) {
        sRet = "Top Entry Door";
    }
    else if (nRoomIndex > 6) {
        sRet = "Bottom Entry Door";
    }
    else if (nRoomIndex == 4) {
        sRet = "Left Entry Door";
    }
    else if (nRoomIndex == 6) {
        sRet = "Right Entry Door";
    }
    return sRet;
}

bool RoomManager::checkDuplicate (int nNum, std::vector<int> vecIndeces) {
    for(int i = 0; i < vecIndeces.size(); i++) {
        if(nNum == vecIndeces[i])
            return true;    
    }
    return false;
}

std::vector<int> RoomManager::getAdjacentRooms(int nRoomIndex) {
    std::vector<int> vecAdjacent;
    switch(nRoomIndex) {
        case 1:
            vecAdjacent.push_back(2);
            vecAdjacent.push_back(4);
            break;
            
        case 2:
            vecAdjacent.push_back(1);
            vecAdjacent.push_back(3);
            vecAdjacent.push_back(5);
            break;

        case 3:
            vecAdjacent.push_back(2);
            vecAdjacent.push_back(6);
            break;

        case 4:
            vecAdjacent.push_back(1);
            vecAdjacent.push_back(5);
            vecAdjacent.push_back(7);
            break;
        
        case 5:
            vecAdjacent.push_back(2);
            vecAdjacent.push_back(4);
            vecAdjacent.push_back(6);
            vecAdjacent.push_back(8);
            break;

        case 6:
            vecAdjacent.push_back(3);
            vecAdjacent.push_back(5);
            vecAdjacent.push_back(9);
            break;

        case 7:
            vecAdjacent.push_back(4);
            vecAdjacent.push_back(8);
            break;

        case 8:
            vecAdjacent.push_back(5);
            vecAdjacent.push_back(7);
            vecAdjacent.push_back(9);
            break;

        case 9:
            vecAdjacent.push_back(6);
            vecAdjacent.push_back(8);
            break;

        default:
            break;
    }

    return vecAdjacent;
}

void RoomManager::initializeIndeces() {
    for(int i = 1; i <= 9; i++) {
        this->vecIndeces.push_back(i);
    }
}

void RoomManager::clearIndeces() {
    this->vecIndeces.clear();
}

int RoomManager::getRandomNumber(int nLowerbound, int nUpperbound) {
    return rand() % (nUpperbound - nLowerbound + 1);
  //  return nLowerbound + rand() % nUpperbound;
}

std::vector<Room*> RoomManager::getVecRooms() {
    return this->vecRooms;
}

SceneTag RoomManager::getRoomTag(int nIndex) {
    SceneTag nRet;
    switch(nIndex) {
        case 1: nRet = SceneTag::ROOM1_SCENE; break;
        case 2: nRet = SceneTag::ROOM2_SCENE; break;
        case 3: nRet = SceneTag::ROOM3_SCENE; break;
        case 4: nRet = SceneTag::ROOM4_SCENE; break;
        case 5: nRet = SceneTag::ROOM5_SCENE; break;
        case 6: nRet = SceneTag::ROOM6_SCENE; break;
        case 7: nRet = SceneTag::ROOM7_SCENE; break;
        case 8: nRet = SceneTag::ROOM8_SCENE; break;
        case 9: nRet = SceneTag::ROOM9_SCENE; break;
        default: break;
    }
    return nRet;
}

int RoomManager::getEntryRoom() {
    return this->nEntryRoom;
}

int RoomManager::getCurrentRoom() {
    return this->nCurrentRoom;
}

void RoomManager::setCurrentRoom(int nCurrentRoom) {
    this->nCurrentRoom = nCurrentRoom;
}


RoomManager* RoomManager::P_SHARED_INSTANCE = NULL;
RoomManager::RoomManager() {
    this->nNumRooms = 0;
    this->nEntryRoom = 5;
 //   this->nPrevRoom = 0;
  //  this->nCurrentRoom = 0;
    this->vecRooms = {};
    this->vecIndeces = {};
    this->bGenerated = false;
}
RoomManager::RoomManager(const RoomManager&) {}

RoomManager* RoomManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new RoomManager();

    return P_SHARED_INSTANCE;
}