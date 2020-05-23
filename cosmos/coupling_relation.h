#ifndef _COSMOS_COUPLING_RELATION_H
#define _COSMOS_COUPLING_RELATION_H

#include <utility>
#include <vector>

#include "model.h"
#include "event.h"

namespace cosmos {

class CouplingRelation {
private:
    std::vector<std::pair<Event&, Event&>> couplings_;
public:
    CouplingRelation() { }
    ~CouplingRelation() { }

    static CouplingRelation& instance() {
        static CouplingRelation instance;
        return instance;
    }

    void bind(Event& src, Event& dst) {
        for (auto itr = couplings_.begin(); itr != couplings_.end(); ++itr) {
            if (itr->first == src && itr->second == dst) {
                return;
            }
        }

        auto coupling = std::make_pair(src, dst);
        couplings_.push_back(coupling);
    }
};

}

#endif  // _COSMOS_COUPLING_RELATION_H