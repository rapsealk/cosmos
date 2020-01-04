#include <iostream>

#include "model.h"

typedef void (*Function)();

void func_a() {
    std::cout << "func_a()" << std::endl;
}

int main()
{
    cosmos::Model* model = new cosmos::Model();
    model->SetInternalTransition(func_a);
    model->TriggerInternalTransition();
    return 0;
}