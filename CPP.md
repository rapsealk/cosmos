# C++

## Keywords
* const
```
int value = 100;

// [1] 포인터가 가리키는 곳이 불변이 된다.
const int* ptr = &value;
ptr = &value; // OK
*ptr = 10;    // FAIL

// [2] 포인터 변수 자체가 불변이 된다. (단, reference에는 사용 불가!)
int* const ptr = &value;
ptr = &value; // FAIL
*ptr = 10;    // OK

// [3] 함수 내부에서 멤버 변수의 값을 변경하지 않는다. 또한 const 함수만 호출할 수 있다.
int GetPointer() const;
```