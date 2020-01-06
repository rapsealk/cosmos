# Cosmos: Computer based System Modeling & Simulation
![C++11](https://img.shields.io/badge/language-C++11-purple.svg)
![Python 3](https://img.shields.io/badge/language-Python%203-blue.svg)

* Course: [시스템 모델링 시뮬레이션 입문](www.edwith.org/isms1)

## Build
```
# macOS
$ brew install cmake
cosmos $ cmake CMakeLists.txt
cosmos $ make
```

## Conventions / Style Guides
| Language | Following Convention |
| -------- | -------------------- |
| C++      | [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) |
| Python   | [PEP 8](https://www.python.org/dev/peps/pep-0008/) |

### Lint
| Language | Linter |
| -------- | ------ |
| Python   | [flake8](http://flake8.pycqa.org) |

### Unit test
| Language | Library |
| -------- | ------- |
| C++      | [gtest](https://github.com/google/googletest) |
| Python   | [unittest](https://docs.python.org/3/library/unittest.html) |

# Chapter 2. 시스템 모델링 개념
## 2. 시스템 정의 및 분류
### 1. 시스템 및 복합시스템 (System of Systems)
* 시스템(체계) 정의 [출처: IEEE Standard Dictionary]
> "A combination of components that act together to perform a function not possible with any of the individual parts."
    * -> 여러 개의 구성요소(Component)들이 모여서 개별 구성요소들만으로는 불가능했던 기능을 만족시키는 구성요소들의 조합
* 복합시스템 (System of Systems: SoS) 정의
    * 시스템 정의에서 시스템을 구성하는 구성요소들이 독립적인 역할을 수행하는 시스템인 경우 이들의 조합
### 2. 시스템 계층구조 및 구성요소들
* 시스템 및 구성요소: 미 국방표준 [MIL-STD-499B](http://www.acqnotes.com/Attachments/Systems%20Engineering%20Standards%20A%20Summary.pdf)
* 주의! 시스템 입/출력 및 구성요소는 M&S 목적에 따라 달라질 수 있다.
### 4. 추상화 수준에 따른 시스템 분류
* 연속 상태
    * 시스템 동작을 미시적으로 묘사함.
    * 시스템 자체 지능 거의 없음.
* 이산 상태
    * 시스템 동작을 거시적으로 묘사함.
    * 시스템 자체 지능 있음.
#### 상태 x 시간
* 연속 상태 x 연속 시간
    * 연속 시간 시스템
    * 미분방정식
    * 아날로그 시스템
* 연속 상태 x 이산 시간 (+ 시간 이산화)
    * 이산 시간 시스템
    * 차분방정식
    * 샘플데이터 시스템
* 이산 상태 x 이산 시간 (+ 상태 이산화)
    * 디지털 시스템
    * 유한상태기계
    * VLSI 시스템
* 이산 상태 x 연속 시간 (+ 시간 무시 사건기반)
    * 이산 사건 시스템
    * DEVS 형식론
    * 생산 시스템

## DEVS 모델링 방법론 개요
### DEVS (Discrete Event Systems Specifiaction) 형식론
* 1976~1984년 Bernard P. Zeigler 교수에 의해 고안
* B.P. Zeigler, T.G. Kim, H. Praehofer, Theory of Modeling and Simulation, Academic Press, 2000.
* 이산사건 모델링을 위한 수학적 틀 (3S4F)
    * -> 완전성, 검증 가능, 수정/확장 용이, 효율적 유지 보수
* 집합론을 이용한 시스템 이론적 모델 표현
    * -> 연속시간 모델 표현과 호환성(입력, 출력, 상태, 상태천이 함수)
* 모듈화된 모델의 계층적 명세 기법
    * -> 모델과 인터페이스가 분리된 구조화된 모델링
* 학술적 연구 및 다양한 분야(국방, 교통, 재난 등)의 실용적 적용

### DEVS M&S 개념
* 모델과 시뮬레이션 알고리즘은 별개로 분리하여 구현됨
    * -> 모델과 시뮬레이션 알고리즘이 쌍으로 존재함
* DEVS 모델 클래스
    * 1) 원자 모델 (Atomic Model): 분해 불가능한 최소 단위 모델
    * 2) 결합 모델 (Coupled Model): 원자 혹은 결합 모델들의 결합체
* 시뮬레이션 엔진
    * 원자모델 시뮬레이션 알고리즘 - 원자 모델 해석기
    * 결합모델 시뮬레이션 알고리즘 - 결합 모델 해석기

### DEVS 모델과 시뮬레이터 구조

### 계층적으로 모듈화된 구조적 모델링
* 모델 설계: Top-down 접근법
* 모델 구현: Bottom-up 접근법

### 계층적 모델링: 재사용 + 정보 은닉
* 1) 모델 재사용 측면: A와 B가 결합된 AB는 ABC의 부 모델로 재사용
* 2) 정보 은닉 측면: AB의 부 모델인 A와 B는 C로/로부터 직접 접근 불가

### 모듈화된 모델링: 명시적인 입/출력 인터페이스
* 연결 구조 명세와 모델 명세 분리: 모델 라이브러리화 및 재사용 용이
* 연결 구조 명세를 모델 명세에 포함: 모델 라이브러리화 및 재사용 제한적

## DEVS
### Atomic Model (3S4F)
```
M = <X, Y, Q, δext, δint, ta, λ>
```
* 입력(X), 출력(Y), 상태변수(Q)의 집합을 구한다.
* ta: 상태 집합 Q의 각 원소 q에 대한 최대 체류시간을 정의한다.
    * 명세하는 경우:
        * 시간 간격 불규칙: 이산사건 모델
        * 시간 간격 일정: 이산시간 모델
    * 명세하지 않는 경우: Finite State Machine/Automata
* δext: 입력 집합 X와 상태 집합 Q의 모든 가능한 조합(QxX)에 대하여 다음 상태를 정의한다.
* δint: 상태 집합 Q의 각 원소 q에 대한 다음 상태를 정의한다.
* λ: 상태 집합 Q의 각 원소 q에 대한 출력 집합 Y의 각 원소 y를 정의한다.

### Coupled Model
```
DN = <X, Y, M, EIC, EOC, IC, SELECT>
```
* 입력(X)/출력(Y) 사건 집합
* M: DN 내부에 있는 모든 컴포넌트 DEVS 모델
* EIC (External Input Coupling): 외부 입력 연결 관계 (DN.X x Mi.Xi)
* Coupling Relation (CR)
    * EOC (External Output Coupling): 외부 출력 연결 관계 (Mi.Yi x DN.Y)
    * IC (Internal Coupling): 내부 연결 관계 (Mi.Yi x Mj.Xj)
    * SELECT: 우선 이벤트 선택 규칙 (2^M - ∅ -> M)
    ```
    # f: 우선 순위 결정 함수
    f({ M1, M2 }) = M1
    f({ M1, M3 }) = M3
    ...
    ```

* 멱집합 (Power Set): 동시 발생 이벤트 우선순위 표현
```
2^A = { B | B ⊆ A }
```

* Coupling Relation (CR)
    * 두 모델간의 유향성 결합 관계 (Directional Coupling Relation)
```
(M1, M2) (M1.out, M2.in) (M10.ready, M20.go)
```
* 주의! 어떤 모델의 연결 명세도 모델 내부에 포함시키지 않고 별도의 CR로 명세한다.

### Simulation Engine
```
1. 시간을 초기화한다. (t = 0)
2. 종료 조건을 검사한다.
    2-1. 종료 조건이 성립하지 않으면 모델을 실행하고 시간을 업데이트한다.
```
* t: 현재 시각(시뮬레이션 시각)
* 종료 조건
* t = t + T1에서 T1은 상수인가 난수인가?

* 모델 해석
* 시간 진행 관리
* 모델 선택 / 데이터 전달

## DEVS 모델의 시뮬레이션 엔진 구조 및 원자모델 시뮬레이션 알고리즘

### DEVS 모델의 계층적 시뮬레이션의 특징
* 계층적 시뮬레이터 구조 = DEVS 모델 구조
    * 원자모델 (AM) <-> 원자 모델 실행기 (S:AM)
    * 결합모델 (CM) <-> 결합 모델 실행기 (C:CM)
* 계층적 시뮬레이션 알고리즘
    * 시뮬레이션 엔진의 3대 기능 수행
    * 모델 해석, 시간 진행 관리, 모델 선택 및 데이터 전달
* 분산 알고리즘
    * 전역 정보를 가지고 있지 않음
    * 순차적 컴퓨팅 환경 및 분산 / 병렬 환경에서 구현 가능

### 모델 실행기의 입/출력 정의
#### 입력
* (x, t): 외부 입력 x가 시각 t에 도착
* (*, t): TO(*)이 시각 t에 발생했음을 알려주는 것
#### 출력
* (y, t): 출력 y를 시각 t에 발생시킴
* (done, t_N): 사건 처리가 완료되었고 다음 실행 시각은 t_N 이다.
#### 상태
* t: 현재 시뮬레이션 시각
* t_L: 이전 시뮬레이션 시각
* t_N: 다음 시뮬레이션 시각
* e = t - t_N: 경과 시간

### 원자 모델 실행기 알고리즘 의사 코드
```
# (x, t)
when_receive(x, t)
done := false
if t_L <= t <= t_N then
    e := t - t_L
    q := δext((q, e), x)
    t_L := t
    t_N := t + ta(q)
else error
done := true

# (*, t)
when_receive(*, t)
done := false
if t = t_N then
    y := ∀(q)
    q := δint(q)
    t_L := t
    t_N := t + ta(q)
else error
done := true
```

## DEVS 결합모델 시뮬레이션 알고리즘
* Influence: **M1** -> **M2** (M2 is an influencee of M1.)

### 결합 모델 실행기 알고리즘 의사 코드
```
# (x, t)
when_receive(x, t)
done := false
if t_L <= t <= t_N then
    send (x, t) to connected component(s)
    wait all component(s) done
    t_L := t
    t_N := min(t_N_i | i: component)
else error
done := true

# (*, t)
when_receive(*, t)
done := false
if t = t_N else
    find component(s) with t_N
    select one i*
    send (*, t) to i*
    translate y_i_* to x
    send x to its influencees
    wait i* and its influencees done
    t_L := t
    t_N := min(t_N_i | i: i* + its influencees)
else error
done := true
```

### 스케줄 충돌 시 우선순위 명세의 중요성
* 주의! 우선순위 명세는 대상 시스템에서 처리되는 실제 순위와 일치하도록 명세해야 한다.
    * -> 우선순위 명세가 달라지면 시뮬레이션 결과가 달라진다.

### DEVS 형식론에서 Select 함수의 불편한 진실
* 모델이 복잡해질수록 우선순위 표현도 복잡해진다.
    * 고찰: DEVS 형식론의 집합론 기반과 계층적 모델 명세의 한계점
    * -> DEVS M&S 환경에서는 API를 사용하여 모든 모델의 우선순위를 한번에 명세