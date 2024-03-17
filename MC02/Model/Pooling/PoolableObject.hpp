#pragma once

#include "../Enum/PoolTag.hpp"
#include "../GameObject.hpp"    

namespace poolables {
    using namespace models;
    
    class PoolableObject : public GameObject {
        protected:
            PoolTag ETag;

        public:
            PoolableObject(PoolTag ETag, std::string strName, AnimatedTexture* pTexture); 
            ~PoolableObject();

        public:
            virtual void initialize()       = 0;
            virtual void onActivate()       = 0;  //iniital setup
            virtual void onRelease()        = 0;
            virtual PoolableObject* clone() = 0;

        public:
            PoolTag getTag();
    };
}
