#ifndef _COSMOS_EVENT_H
#define _COSMOS_EVENT_H

#include <string>

#include "cosmos/model.h"

namespace cosmos {

class Event {
private:
    Model* model_;
    std::string name_;
public:
    Event(Model* model, std::string name)
        : model_(model), name_(name) { }

    bool operator==(Event& other) {
        return this->model_ == other.model_
                && this->name_ == other.name_;
    }
};

}

#endif  // _COSMOS_EVENT_H