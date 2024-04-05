#pragma once

#include <SFML/Graphics.hpp>

#include "../Component.hpp"

namespace components {
    class Renderer : public Component {
        private:
            sf::RenderWindow* pWindow;
            std::vector<sf::Drawable*> vecDrawables;
        
        public:
            Renderer(std::string strName);
            
        public:
            void perform();
            void assignTargetWindow(sf::RenderWindow* pWindow);
            void assignDrawable(sf::Drawable* pDrawable);

    };
}