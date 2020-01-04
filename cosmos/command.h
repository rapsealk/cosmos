#ifndef _COSMOS_COMMAND_H
#define _COSMOS_COMMAND_H

namespace cosmos {

class Command {
public:
    Command();
    ~Command();

    virtual void Execute();
};

}

#endif  // _COSMOS_COMMAND_H