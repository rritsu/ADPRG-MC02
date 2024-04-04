#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strName, AnimatedTexture* pTexture) {
    this->bEnabled = true; 
    this->strName = strName;
    this->pSprite = new sf::Sprite();
    this->pTexture = pTexture;
    this->vecComponents = {};
    this->setFrame(0); 
    this->pShade = NULL;
}

void GameObject::processEvents(sf::Event CEvent) {
    std::vector<Component*> vecInputComponent;
    vecInputComponent = this->getComponents(ComponentType::INPUT);
    GeneralInput* pGeneralInput;

    for(Component* pComponent : vecInputComponent) {
        pGeneralInput = (GeneralInput*)pComponent;
        pGeneralInput->assignEvent(CEvent);
        pGeneralInput->perform();
    }
}


void GameObject::update(sf::Time tDeltatime){

    std::vector<Component*> vecScriptComponents = this->getComponents(ComponentType::SCRIPT);

    for(Component* pComponent : vecScriptComponents) {
        pComponent->perform();
        pComponent->setDeltaTime(tDeltatime);
    }
}


//RENDER
void GameObject::draw(sf::RenderWindow* pWindow) {
    std::vector<Component*> vecRendererComponents = this->getComponents(ComponentType::RENDERER);
    
    for(Component* pComponent : vecRendererComponents) {
        Renderer* pRenderer = (Renderer*)pComponent;
        pRenderer->assignTargetWindow(pWindow);
        pRenderer->perform();
    }
    //pWindow->draw(*this->pSprite);
}

void GameObject::centerOrigin() {
    if(this->pTexture != NULL) {
        int nWidth = this->pSprite->getTexture()->getSize().x;
        int nHeight = this->pSprite->getTexture()->getSize().y;
        this->pSprite->setOrigin(nWidth / 2.0f, nHeight / 2.0f);
    }
}

void GameObject::setTopRightOrigin() {
    if(this->pTexture != NULL) {
        int nWidth = this->pSprite->getTexture()->getSize().x;
        int nHeight = 0.0f;
        this->pSprite->setOrigin(nWidth, nHeight);
    }
}

void GameObject::resetOrigin() {
    if(this->pTexture != NULL) {
        this->pSprite->setOrigin(0.0f, 0.0f);
    }
}

void GameObject::attachComponent(Component* pComponent) {
    this->vecComponents.push_back(pComponent);
    pComponent->attachOwner(this);
}

    //might be wrong code
void  GameObject::detachComponent(Component* pComponent) {
  //  int nIndex = -1;
    int nIndex = 0;
    for(Component* pTemp : vecComponents){
        if(pTemp != pComponent)
            nIndex += 1;
        else
            break;
    }

    if(nIndex < this->vecComponents.size()) {
        this->vecComponents[nIndex]->detachOwner();
        this->vecComponents.erase(this->vecComponents.begin() + nIndex); 
    }
}


Component* GameObject::findComponentByName(std::string strName) {
    Component* pGetComponent;
    for(Component* pComponent : this->vecComponents ) {
        if(pComponent->getName() == strName)
            pGetComponent = pComponent;
    }
    return pGetComponent;
}

void GameObject::assignShade(GameObject* pShade) {
    this->pShade = pShade;
}

GameObject* GameObject::getShade() {
   return this->pShade;
}

void GameObject::setShadeSetting(sf::Vector2f vecScale, sf::Color cColor) {
    this->pSprite->setScale(vecScale);
    this->pSprite->setColor(cColor);
}

std::vector<Component*> GameObject::getComponents(ComponentType EType){
    std::vector<Component*> vecGetComponents = {};
    for(Component* pComponent : vecComponents) {
        if(pComponent->getType() == EType){
            vecGetComponents.push_back(pComponent);
        }
    }
    return vecGetComponents;
}

float GameObject::getHalfWidth() {
    if(this->pTexture != NULL) 
        return this->pSprite->getTexture()->getSize().x / 2.0f;
    return 0.0f;
}

float GameObject::getHalfHeight() {
    if(this->pTexture != NULL) 
        return this->pSprite->getTexture()->getSize().y / 2.0f;
    return 0.0f;
}

sf::FloatRect GameObject::getGlobalBounds() {
    if(this->pSprite != NULL)
        return this->pSprite->getGlobalBounds();
    return sf::FloatRect();
}

bool GameObject::getEnabled() {
    return this->bEnabled;
}

void GameObject::setEnabled(bool bEnabled) {
    this->bEnabled = bEnabled;
}

std::string GameObject::getName() {
    return this->strName;
}

sf::Sprite* GameObject::getSprite() {
    return this->pSprite;
}

void GameObject::setFrame(int nFrame) {
    if(this->pTexture != NULL){
        this->pTexture->setCurrentFrame(nFrame);
        this->pSprite->setTexture(*this->pTexture->getFrame());
    }
}