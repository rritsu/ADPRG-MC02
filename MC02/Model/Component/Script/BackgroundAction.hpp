#pragma once

#include "../../../Controller/Manager/SceneManager.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../Enum/SceneTag.hpp"
#include "../Component.hpp"
#include "../Input/BackgroundInput.hpp"

namespace components {
    using namespace managers;
    using namespace components;

    class BackgroundAction : public Component {
        public:
            BackgroundAction(std::string strName);

        public:
            void perform();
    };
}
