#include "shared_pointer.h"

int main() {
    std::cout << "==== straight forward definition" << std::endl;
    shared_ptr<int> foo;
    shared_ptr<int> bar (new int(10));

    std::cout << "==== copy bar to foo" << std::endl;
    foo = bar;
    std::cout << "==== make_shared bar" << std::endl;
    bar = make_shared<int> (20);

    std::cout << "==== reset bar and check if exists" << std::endl;
    bar.reset();
    assert(!bar);

    std::cout << "==== reset foo with init" << std::endl;
    foo.reset(new int(30), default_delete);
    std::cout << "==== foo pointed to: " << *foo << std::endl;
    bar = foo;
    std::cout << "==== bar count: " << bar.use_count() << std::endl;
    return 0;
}