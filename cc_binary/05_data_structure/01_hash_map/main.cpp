#include "custom_hash_map.h"

int main() {
    HashMap map;
    map.insert(1, 100);
    map.insert(11, 200);
    std::cout << map.get(1) << " " << map.get(11) << std::endl;
    return 0;
}