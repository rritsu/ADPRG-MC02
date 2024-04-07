#pragma once

#include "../../Enum/ItemTag.hpp"
#include "../../GameObject.hpp"
#include "../../Enum/PoolTag.hpp"  
#include "../../Pooling/PoolableObject.hpp"  

namespace poolables {
    using namespace models;
    using namespace poolables;
    
  //  class Item : public GameObject {
    class Item : public PoolableObject {
        protected:
            ItemTag ETag;
            PoolTag EPoolTag;

        public:
            Item(ItemTag ETag, PoolTag EPoolTag, std::string strName, AnimatedTexture* pTexture);

        public:
        //    void initialize();
        //    void onActivate();  //initial setup
         //   void onRelease();
            
         //   PoolableObject* clone();

            virtual void initialize()       = 0;
            virtual void onActivate()       = 0;  //initial setup
            virtual void onRelease()        = 0;
            virtual PoolableObject* clone() = 0;

        public:
            PoolTag getTag();
    };
}
