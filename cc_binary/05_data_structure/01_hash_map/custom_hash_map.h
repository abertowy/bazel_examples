#include <iostream>
#include <vector>
#include <list>

class HashMap {
    static const int SIZE = 10;
    std::vector<std::list<std::pair<int, int>>> table;

public:
    HashMap() : table(SIZE) {}

    void insert(int key, int value) {
        int idx = key % SIZE;
        for (auto& [k, v] : table[idx]) {
            if (k == key) {
                v = value;
                return;
            }
        }
        table[idx].emplace_back(key, value);
    }

    int get(int key) {
        int idx = key % SIZE;
        for (auto& [k, v] : table[idx]) {
            if (k == key) return v;
        }
        throw std::runtime_error("Key not found");
    }
};