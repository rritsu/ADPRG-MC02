#include "RoomManager.hpp"

using namespace managers;

<<<<<<< Updated upstream
void RoomManager::generateArea() { 
    //generate how many scraps
    //generate how many rooms
    //connection of rooms
    //doors smth smth
    //enemies
    
    this->generateRooms();
=======
void RoomManager::generateRooms() { 

  //  this->generateRoomIndeces();
>>>>>>> Stashed changes
    SceneManager::getInstance()->loadScene(this->getRoomTag(this->nEntryRoom));
    std::cout << "entryyy " << this->nEntryRoom << std::endl;
}

<<<<<<< Updated upstream
void RoomManager::generateRooms() {
=======
void RoomManager::generateRoomIndeces() {
>>>>>>> Stashed changes
    int nTempIndex = 0;

    this->nNumRooms = this->getRandomNumber(4, 9-3);
    std::cout << nNumRooms << std::endl;
    
    while(this->nEntryRoom == 5) {
        this->nEntryRoom = this->getRandomNumber(1, 9);
    }
    this->nCurrentRoom = this->nEntryRoom;

    //nvm its still buggy
    for(int i = 1; i <= nNumRooms; i++) {
        this->vecIndeces = this->getAdjacentRooms(this->nCurrentRoom);
        Room* pRoom = new Room("Room "+std::to_string(this->nCurrentRoom), NULL, this->nCurrentRoom);
        this->addRoom(pRoom);
        this->nPrevRoom = this->nCurrentRoom;

        do{
            nTempIndex = this->getRandomNumber(0, this->vecIndeces.size());
           // std::cout << "stuck" << std::endl;
        }while(this->checkDuplicate(nTempIndex));

   //     std::cout << this->nCurrentRoom << std::endl;

        this->nCurrentRoom = this->vecIndeces[nTempIndex];
        this->clearIndeces();

       // std::cout << "loop" << std::endl;
    }

    //checking
    for(Room* pRoom : this->vecRooms) {
        std::cout << "room " << pRoom->getRoomIndex() << std::endl;
    }
}

void RoomManager::addRoom(Room* pRoom) {
    this->mapRooms[pRoom->getRoomIndex()] = pRoom;
    this->vecRooms.push_back(pRoom);
    GameObjectManager::getInstance()->addObject(pRoom);
   // pRoom->initialize();
}

Room* RoomManager::findRoomByIndex(int nRoomIndex) {
    return this->mapRooms[nRoomIndex];
}

void RoomManager::deleteAllRooms() {
    std::vector<Room*> vecRooms = this->vecRooms;

    for(int i = 0; i < vecRooms.size(); i++) {
        delete this->vecRooms[i];
    }

    this->vecRooms.clear();
    this->mapRooms.clear();
}

bool RoomManager::checkDuplicate (int nIndex) {
    for(Room* pRoom : this->vecRooms) {
        if(pRoom->getRoomIndex() == this->vecIndeces[nIndex])
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

void RoomManager::clearIndeces() {
    this->vecIndeces.clear();
}

int RoomManager::getRandomNumber(int nLowerbound, int nUpperbound) {

    return nLowerbound + rand() % nUpperbound;;
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

/*
std::vector<int> AreaManager::getAdjacentRooms(int nRoom) {
    std::vector<int> vecAdjacent;


    return vecAdjacent;
}
*/

RoomManager* RoomManager::P_SHARED_INSTANCE = NULL;
RoomManager::RoomManager() {
    this->nNumRooms = 0;
    this->nEntryRoom = 5;
    this->nPrevRoom = 0;
    this->nCurrentRoom = 0;
    this->vecRooms = {};
    this->vecIndeces = {};
}
RoomManager::RoomManager(const RoomManager&) {}

RoomManager* RoomManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new RoomManager();

    return P_SHARED_INSTANCE;
}