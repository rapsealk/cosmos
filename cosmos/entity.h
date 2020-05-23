#ifndef _COSMOS_ENTITY_H
#define _COSMOS_ENTITY_H

#include <string>

namespace cosmos {

class Entity {
private:
    std::string name_;
public:
    Entity(std::string name)
        : name_(name) { }
};  // class Entity

}   // namespace cosmos

#endif  // _COSMOS_ENTITY_H