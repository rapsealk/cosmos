#ifndef _COSMOS_ENGINE_H
#define _COSMOS_ENGINE_H

namespace cosmos {

class Engine {
private:
    double time_;
public:
    Engine();

    void run() {
        while (!condition_matches()) {
            // Do something.
        }
    }

    virtual bool condition_matches();
}

}

#endif  // _COSMOS_ENGINE_H