#include "Game.hpp"

using namespace controllers;


Game::Game() : CWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hello") {    
    std::vector<int> vecArea = {};
    vecArea.push_back(2);
    vecArea.push_back(4);
    
  //  SceneManager::getInstance()->registerScene(new MainMenuScene());
    SceneManager::getInstance()->registerScene(new ShipScene());
   // SceneManager::getInstance()->registerScene(new AreaScene(vecArea , 1, 0));
    SceneManager::getInstance()->loadScene(SceneTag::SHIP_SCENE);
    
}


void Game::run() {
    //sf::Time tDeltaTime;
    sf::Clock CClock = sf::Clock();
    sf::Time tTimePerFrame = sf::seconds(1.0f / FRAME_RATE_LIMIT);
    sf::Time tTimeSinceLastUpdate = sf::Time::Zero;

    while (this->CWindow.isOpen()) {
   //     std::cout << "process" << std::endl;
        this->processEvents();
        tTimeSinceLastUpdate += CClock.restart();
       // std::cout << "processed" << std::endl;
        while(tTimeSinceLastUpdate > tTimePerFrame){ 
            tTimeSinceLastUpdate -= tTimePerFrame;
            this->update(tTimePerFrame); 
        }
    //    std::cout << "update" << std::endl;
        SceneManager::getInstance()->checkLoadScene();
     //   std::cout << "done check load scene" << std::endl;
        this->render();

      //  std::cout << "render" << std::endl;
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

//RENDER
void Game::render() {
    this->CWindow.clear();
    GameObjectManager::getInstance()->draw(&this->CWindow);
    this->CWindow.display();
}
