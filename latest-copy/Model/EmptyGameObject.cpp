#include "EmptyGameObject.hpp"

using namespace models;

EmptyGameObject::EmptyGameObject(std::string strName) : GameObject(strName, NULL) {}

void EmptyGameObject::initialize() {}

