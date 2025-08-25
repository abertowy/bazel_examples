#include "static_vector.h"

int main() {
    static_vector<int, 5> v1;
    std::cout << "Size: " << v1.size() << ", Capacity: " << v1.capacity() << ", data at [4]: " << v1[4] << std::endl;
    static_vector<int, 5> v2 {10,1,2,3,4};
    std::cout << "Size: " << v2.size() << ", Capacity: " << v2.capacity() << ", data at [4]: " << v2[4] << std::endl;
    static_vector<int, 5> v3(v2);
    std::cout << "Size: " << v3.size() << ", Capacity: " << v3.capacity() << ", data at [4]: " << v3[4] << std::endl;
    static_vector<int, 5> v4{5,4,3,2,1};
    std::cout << "Size: " << v4.size() << ", Capacity: " << v4.capacity() << ", data at [4]: " << v4[4] << std::endl;
    v4 = v2;
    std::cout << "Size: " << v4.size() << ", Capacity: " << v4.capacity() << ", data at [4]: " << v4[4] << std::endl;
    static_vector<int, 5> v5 = v2 + v4;
    std::cout << "Size: " << v5.size() << ", Capacity: " << v5.capacity() << ", data at [4]: " << v5[4] << std::endl;
    v5 = std::move(v2);
    std::cout << "Size: " << v5.size() << ", Capacity: " << v5.capacity() << ", data at [4]: " << v5[4] << std::endl;
    for (std::size_t i = 0; i < v1.capacity(); ++i) {
        std::cout << v1[i] << std::endl;
    }
    static_vector<int, 5> v6(std::move(v1));
    std::cout << "Size: " << v6.size() << ", Capacity: " << v6.capacity() << ", data at [4]: " << v6[4] << std::endl;
    for (std::size_t i = 0; i < v6.capacity(); ++i) {
        std::cout << v6[i] << std::endl;
    }
    return 0;
}