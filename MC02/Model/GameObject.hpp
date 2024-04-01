#pragma once


#include "AnimatedTexture.hpp"
#include "Component/Component.hpp"
#include "Component/GeneralInput.hpp"
#include "Component/Renderer/Renderer.hpp"

#include "../Config/Settings.hpp"

namespace models {
    using namespace components;

    class GameObject {
        protected:
            bool bEnabled;
            std::string strName;
            sf::Sprite* pSprite;
            AnimatedTexture* pTexture;;
            std::vector<Component*> vecComponents; 
            GameObject* pShade;

        public:
            GameObject(std::string strName, AnimatedTexture* pTexture);
        
        public:
            virtual void initialize() = 0; 
            virtual void processEvents(sf::Event CEvent); 
            virtual void update(sf::Time tDeltaTime);
            virtual void draw(sf::RenderWindow* pWindow);

        public:
            void centerOrigin();
            void attachComponent(Component* pComponent);
            void detachComponent(Component* pComponent);
            Component* findComponentByName(std::string strName);
            void assignShade(GameObject* pShade);
            

        public:
            bool getEnabled();
            void setEnabled(bool bEnabled);
            std::string getName();
            sf::Sprite* getSprite();
            std::vector<Component*> getComponents(ComponentType EType);
            float getHalfWidth();
            float getHalfHeight();
            sf::FloatRect getGlobalBounds();
            GameObject* getShade();
            void setShadeSetting(sf::Vector2f vecScale, sf::Color cColor);
            void setFrame(int nFrame);
    };
}