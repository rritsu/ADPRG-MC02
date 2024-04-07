#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

namespace models {
    class AnimatedTexture {
        private:
            std::vector<sf::Texture*> vecFrames;
            int nCurrentFrame;
        
        public:
            AnimatedTexture(std::vector<sf::Texture*> vecFrames);

        public:
            void incrementFrame();

        public:
            sf::Texture* getFrame();
            void setCurrentFrame(int nCurrentFrame);
    };
}
