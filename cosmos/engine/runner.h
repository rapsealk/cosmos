#ifndef _COSMOS_ENGINE_RUNNER_H
#define _COSMOS_ENGINE_RUNNER_H

#include "../model.h"

namespace cosmos {

class Runner {
private:
    enum State {
        wait,
        processing
    } state_;
    friend class Model;
public:
    Runner()
        : state_(wait) { }
    ~Runner();
};

}

#endif  // _COSMOS_ENGINE_RUNNER_H