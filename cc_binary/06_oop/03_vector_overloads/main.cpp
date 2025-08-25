#include "operator_overload.h"

int main() {
    Vector v1({1, 2, 3});
    Vector v2({4, 5, 6});

    Vector v3 = v1 + v2;
    v3.print();

    return 0;
}