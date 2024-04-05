#include "SFXManager.hpp"

using namespace controllers;

void SFXManager::loadMainMenu() {}

void SFXManager::loadGame() {}

void SFXManager::unloadAll() {
    sf::Sound* pSound;
    for(int i = 0; i < this->vecSound.size(); i++) {
        if(pSound->getStatus() == sf::Sound::Stopped) {
            delete this->vecSound[i];
        }
    }
    this->vecSound.clear();
}

sf::Sound* SFXManager::getSound(SFXType EType) {
    return this->mapSound[EType];
}

void SFXManager::create(SFXType EType, std::string strPath) {
    sf::Sound* pSound = new sf::Sound();
    sf::SoundBuffer* pBuffer = new sf::SoundBuffer();
    
    pBuffer->loadFromFile(strPath);
    pSound->setBuffer(*pBuffer);
    this->add(EType, pSound);
}

void SFXManager::add(SFXType EType, sf::Sound* pSound) {
    this->mapSound[EType] = pSound;
    this->vecSound.push_back(pSound);
}

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */
SFXManager* SFXManager::P_SHARED_INSTANCE = NULL;
SFXManager::SFXManager() {}
SFXManager::SFXManager(const SFXManager&) {}

SFXManager* SFXManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new SFXManager();

    return P_SHARED_INSTANCE;
}
/* * * * * * * * * * * * * * * * * * * * */
