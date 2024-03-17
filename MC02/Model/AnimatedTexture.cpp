#include "AnimatedTexture.hpp"

using namespace models;

AnimatedTexture::AnimatedTexture(std::vector<sf::Texture*> vecFrames) {
    this->vecFrames = vecFrames;
    this->nCurrentFrame = 0;
}

void AnimatedTexture::incrementFrame() {
    this->setCurrentFrame(this->nCurrentFrame + 1);
}

//getter
sf::Texture* AnimatedTexture::getFrame() {
    return this->vecFrames[this->nCurrentFrame];
}

//setter 
void AnimatedTexture::setCurrentFrame(int nCurrentFrame) {
    if(nCurrentFrame >= 0 && nCurrentFrame <= this->vecFrames.size()) {
        this->nCurrentFrame = nCurrentFrame;
    }
    else{
        this->nCurrentFrame = 0;
        std::cout << "nCurrentFrame out of bounds, resetting to 0" << std::endl;
    }
}
