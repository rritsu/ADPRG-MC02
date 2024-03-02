
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "SFML/Graphics.hpp"

#include "Controller/Game.cpp"
#include "Controller/Manager/TextureManager.cpp"
#include "Controller/Manager/GameObjectManager.cpp"
#include "Controller/Manager/SceneManager.cpp"

#include "Model/GameObject.cpp"
#include "Model/AnimatedTexture.cpp"
#include "Model/Component/Component.cpp"
#include "Model/Component/GeneralInput.cpp"
#include "Model/Component/Renderer/Renderer.cpp"

#include "Model/Scene.cpp"

int main(){
    Game CGame;
    CGame.run();

    return 0;
}