#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strName, AnimatedTexture* pTexture) { 
    this->bEnabled = true;
    this->strName = strName;
    this->pSprite = new sf::Sprite();
    this->pTexture = pTexture;
    this->vecComponents = {};
   // this->setFrame(0);
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

void GameObject::update(sf::Time tDeltaTime){
    std::vector<Component*> vecScriptComponents = this->getComponents(ComponentType::SCRIPT);
    for(Component* pComponent : vecScriptComponents) {
        pComponent->perform();
        pComponent->setDeltaTime(tDeltaTime);
    }
}

void GameObject::draw(sf::RenderWindow* pWindow) {
    std::vector<Component*> vecRenderComponents = this->getComponents(ComponentType::RENDERER);
    for(Component* pComponent : vecRenderComponents) {
        Renderer* pRenderer = (Renderer*)pComponent;
        pRenderer->assignTargetWindow(pWindow);
        pRenderer->perform();
    }
}

void GameObject::centerOrigin() {
    if(this->pTexture != NULL) {
        int nWidth = this->pSprite->getTexture()->getSize().x;
        int nHeight = this->pSprite->getTexture()->getSize().y;
        this->pSprite->setOrigin(nWidth / 2.0f, nHeight / 2.0f);
    }
}

void GameObject::attachComponent(Component* pComponent) {
    this->vecComponents.push_back(pComponent);
    pComponent->attachOwner(this);
}

//might be wrong code
void GameObject::detachComponent(Component* pComponent) {
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

std::vector<Component*> GameObject::getComponents(ComponentType EType) {
    std::vector<Component*> vecGetComponents = {};
    for(Component* pComponent: this->vecComponents){
        if(pComponent->getType() == EType){
            vecGetComponents.push_back(pComponent);
        }
    }
    return vecGetComponents;
}

void GameObject::setFrame(int nFrame) {
    if(this->pTexture != NULL){
        this->pTexture->setCurrentFrame(nFrame);
        this->pSprite->setTexture(*this->pTexture->getFrame());
    }
}