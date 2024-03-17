
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "SFML/Graphics.hpp"

#include "Controller/Game.cpp"
#include "Controller/Manager/TextureManager.cpp"
#include "Controller/Manager/GameObjectManager.cpp"
#include "Controller/Manager/SceneManager.cpp"
#include "Controller/Manager/ObjectPoolManager.cpp"
#include "Controller/Manager/PhysicsManager.cpp"

#include "Controller/Pooling/GameObjectPool.cpp"

#include "Model/GameObject.cpp"
#include "Model/AnimatedTexture.cpp"
#include "Model/Component/Component.cpp"
#include "Model/Component/GeneralInput.cpp"
#include "Model/Component/Renderer/Renderer.cpp"
#include "Model/Component/Physics/Collider.cpp"

#include "Model/Entity/Player.cpp"
#include "Model/Component/Input/PlayerInput.cpp"
#include "Model/Component/Script/PlayerScript.cpp"

#include "Model/Scene.cpp"
#include "Model/Scene/ShipScene.cpp"

int main(){
    Game CGame;
    CGame.run();

    return 0;
}