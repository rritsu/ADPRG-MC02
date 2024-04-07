#pragma once

#include "../../../Controller/Manager/SceneManager.hpp"
#include "../../../Controller/Manager/LevelManager.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../Enum/SceneTag.hpp"
#include "../Component.hpp"
#include "../Input/EvaluationInput.hpp"

namespace components {
    using namespace managers;

    class EvaluationAction : public Component {
        public:
            EvaluationAction(std::string strName);

        public:
            void perform();
    };
}
