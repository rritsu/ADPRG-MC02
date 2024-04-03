#include "Item.hpp"

using namespace poolables;

Item::Item(ItemTag ETag, PoolTag EPoolTag, std::string strName, AnimatedTexture* pTexture) : PoolableObject(EPoolTag, strName, pTexture){
    this->ETag = ETag;
    this->EPoolTag = EPoolTag;
    this->strName = strName;
}