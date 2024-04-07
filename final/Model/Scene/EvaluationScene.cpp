#include "EvaluationScene.hpp"

using namespace scenes;

EvaluationScene::EvaluationScene() : Scene(SceneTag::EVALUATION_SCENE) {}

void EvaluationScene::onLoadResources() {
    TextureManager::getInstance()->loadEvaluation();
}

void EvaluationScene::onLoadObjects() {
    this->createEvaluation();
}

void EvaluationScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll();
}

void EvaluationScene::createEvaluation() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::EVALLUATION_BACKGROUND));
    Evaluation* pEvaluation = new Evaluation("Evaluation Screen", pTexture);
    this->registerObject(pEvaluation);
}