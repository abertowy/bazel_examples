#include "memory_pool.h"

int main() {
    MemoryPool pool(sizeof(int), 10);

    int* p = static_cast<int*>(pool.allocate());
    *p = 42;
    std::cout << *p << std::endl;

    pool.deallocate(p);

    return 0;
}