#ifndef _COSMOS_MODEL_H
#define _COSMOS_MODEL_H

#include <set>
#include <vector>

namespace cosmos {

/**
 * DEVS Atomic Model: 3S4F
 */
class AtomicModel {
private:
    std::set<int> x_;   // In-Events set
    std::set<int> y_;   // Out-Events set
    std::set<int> q_;   // States set
    /**
     * ta: 사건과 사건 사이의 시간 간격 (각 상태에 대한 최대 체류시간)
     * * 명세하는 경우:
     *      * 시간 간격 불규칙: 이산사건 모델
     *      * 시간 간격 일정: 이산시간 모델
     * * 명세하지 않는 경우: Finite State Machine/Automata
     */
    //void* time_advance_;
    /**
     * 상태 집합 Q의 각 원소 q에 대한 출력 집합 Y의 원소 y를 정의
    //void* lambda_;  // Output function
    /**
     * 상태 집합 Q에 대한 다음 상태 정의
     */
    //void (*internal_transition_)();
    /**
     * 입력 집합과 상태 집합의 모든 가능한 조합(QxX)에 대하여 다음 상태 정의
     */
    //void (*external_transition_)();
public:
    AtomicModel();
    ~AtomicModel();

    double ta;
    //double TimeAdvance();
    //void SetInternalTransition(void itf());
    //void TriggerInternalTransition();
};  // class AtomicModel

class CoupledModel {
private:
    std::vector<AtomicModel*> m_;
    int (*select_)();

public:
    CoupledModel();
    ~CoupledModel();
};  // class CoupledModel

}   // namespace cosmos

#endif  // _COSMOS_MODEL_H