# Cosmos: Computer based System Modeling & Simulation
![C++11](https://img.shields.io/badge/language-C++11-blue.svg)

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

## DEVS
### Atomic Model (3S4F)
```
M = <X, Y, Q, δext, δint, ta, λ>
```
* 입력(X), 출력(Y), 상태변수(Q)의 집합을 구한다.
* ta: 상태 집합 Q의 각 원소 q에 대한 최대 체류시간을 정의한다.
* δext: 입력 집합 X와 상태 집합 Q의 모든 가능한 조합(QxX)에 대하여 다음 상태를 정의한다.
* δint: 상태 집합 Q의 각 원소 q에 대한 다음 상태를 정의한다.
* λ: 상태 집합 Q의 각 원소 q에 대한 출력 집합 Y의 각 원소 y를 정의한다.