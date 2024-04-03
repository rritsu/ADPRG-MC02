#include "../../Enum/ItemTag.hpp"
#include "../Model/GameObject.hpp"    

namespace poolables {
    using namespace models;
    
    class Item : public GameObject {
        protected:
            ItemTag ETag;
            PoolTag EPoolTag;

        public:
            Item(ItemTag ETag, PoolTag EPoolTag, std::string strName, AnimatedTexture* pTexture);

        public:
            virtual void initialize()       = 0;
            virtual void onActivate()       = 0;  //initial setup
            virtual void onRelease()        = 0;
            virtual PoolableObject* clone() = 0;

        public:
            PoolTag getTag();
    };
}
