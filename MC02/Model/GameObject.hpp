#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "AnimatedTexture.hpp"
#include "Component/Component.hpp"
#include "Component/GeneralInput.hpp"
#include "Component/Renderer/Renderer.hpp"

namespace models {
    using namespace components;

    class GameObject {
        protected:
            bool bEnabled;
            std::string strName;
            sf::Sprite* pSprite;
            AnimatedTexture* pTexture;
            std::vector<Component*> vecComponents;
           // float fSpeed;
        
        public:
            GameObject(std::string strName, AnimatedTexture* pTexture);

        public:
            virtual void initialize() = 0;
            virtual void processEvents(sf::Event CEvent);
            virtual void update(sf::Time tDeltatime);
            virtual void draw(sf::RenderWindow* pWindow);

        public:
            void attachComponent(Component* pComponent);
            void detachComponent(Component* pComponent);
            Component* findComponentByName(std::string strName);

        public:
            bool getEnabled();
            std::string getName();
            sf::Sprite* getSprite();
            std::vector<Component*> getComponents(ComponentType EType);

            void setFrame(int nFrame);

            //void setTexture(sf::Texture CTexture);
            //float getSpeed();
            
    };
}