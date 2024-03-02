#include "Game.hpp"

using namespace controllers;

Game::Game() : CWindow(sf::VideoMode(1280, 720), "Hello"){
    //register scenes below
}

void Game::run() {
    sf::Clock CClock = sf::Clock();
    sf::Time tTimePerFrame = sf::seconds(1.0f / 60.0f);
    sf::Time tTimeSinceLastUpdate = sf::Time::Zero;

    while (this->CWindow.isOpen()) {
        tTimeSinceLastUpdate += CClock.restart();

        while(tTimeSinceLastUpdate > tTimePerFrame){
            tTimeSinceLastUpdate -= tTimePerFrame;
            this->processEvents();
            this->update(tTimePerFrame); 
        }

        SceneManager::getInstance()->checkLoadScene();
        this->render();
    }
}

void Game::processEvents() {
    sf::Event CEvent;
    while (this->CWindow.pollEvent(CEvent)) {
        switch(CEvent.type){
            case sf::Event::Closed:
                this->CWindow.close();
                break;

            default:
                GameObjectManager::getInstance()->processEvents(CEvent);
                break;
        }
    }
}

void Game::update(sf::Time tDeltaTime) {
    GameObjectManager::getInstance()->update(tDeltaTime);    
}

void Game::render() {
    this->CWindow.clear();
    GameObjectManager::getInstance()->draw(&this->CWindow); 
    this->CWindow.display();
}
