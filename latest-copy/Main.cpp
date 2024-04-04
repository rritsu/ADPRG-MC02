#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>


#include "Controller/Manager/GameObjectManager.cpp"
#include "Controller/Manager/RoomManager.cpp"
#include "Controller/Manager/TextureManager.cpp"
#include "Controller/Manager/SceneManager.cpp"
//#include "Controller/Manager/SFXManager.cpp"
#include "Controller/Manager/AreaManager.cpp"
#include "Controller/Manager/PhysicsManager.cpp"
#include "Controller/Manager/ItemManager.cpp"

#include "Controller/Utility/Utility.cpp"

#include "Controller/Pooling/GameObjectPool.cpp"
#include "Controller/Manager/ObjectPoolManager.cpp"

#include "Controller/Game.cpp"

#include "Model/Component/Component.cpp"
#include "Model/Component/GeneralInput.cpp"
#include "Model/Component/Input/BackgroundInput.cpp"
#include "Model/Component/Input/ShipInput.cpp"
#include "Model/Component/Input/PlayerInput.cpp"
#include "Model/Component/Renderer/Renderer.cpp"
#include "Model/Component/Script/BackgroundAction.cpp"
#include "Model/Component/Script/ShipScript.cpp"
#include "Model/Component/Script/RoomScript.cpp"

#include "Model/Component/Script/PlayerControls.cpp"
#include "Model/Component/Physics/Collider.cpp"

#include "Model/Entity/Background.cpp"
#include "Model/Entity/Border.cpp"
#include "Model/Entity/Player.cpp"
#include "Model/Entity/ShipObject.cpp"
#include "Model/Entity/Tile.cpp"
#include "Model/Entity/Ship.cpp"
#include "Model/Entity/Door.cpp"
#include "Model/Entity/Room.cpp"
#include "Model/Entity/Item/Item.cpp"

#include "Model/Pooling/PoolableObject.cpp"
#include "Model/Pooling/Entity/Scrap.cpp"
#include "Model/Pooling/Entity/Enemy/Enemy.cpp"
#include "Model/Pooling/Entity/Enemy/Bug.cpp"
#include "Model/Pooling/Entity/Enemy/Coilhead.cpp"
#include "Model/Pooling/Entity/Enemy/Flea.cpp"

#include "Model/Scene/MainMenuScene.cpp"
#include "Model/Scene/ShipScene.cpp"
#include "Model/Scene/RoomScene.cpp"

#include "Model/AnimatedTexture.cpp"
#include "Model/EmptyGameObject.cpp"
#include "Model/GameObject.cpp"
#include "Model/Scene.cpp"


int main() {
    Game CGame;
    CGame.run();
  
    return 0;
}