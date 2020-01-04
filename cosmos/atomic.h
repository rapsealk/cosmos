#ifndef _COSMOS_ATOMIC_H
#define _COSMOS_ATOMIC_H

#include "cosmos/model.h"

namespace cosmos {

class Atomic : Model {
private:
public:
    Atomic();
    ~Atomic();

    virtual double TriggerTimeAdvance();
    virtual void TriggerInternalTransition();
    virtual void TriggerExternalTransition();
    virtual void TriggerOutputFunction();
};

}

#endif  // _COSMOS_ATOMIC_H