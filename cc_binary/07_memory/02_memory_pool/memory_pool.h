#include <iostream>
#include <vector>
#include <memory>

class MemoryPool {
    std::vector<void*> freeBlocks;
    size_t blockSize;

public:
    MemoryPool(size_t blockSize, size_t initialCount) : blockSize(blockSize) {
        for (size_t i = 0; i < initialCount; ++i) {
            freeBlocks.push_back(std::malloc(blockSize));
        }
    }

    ~MemoryPool() {
        for (void* block : freeBlocks) {
            std::free(block);
        }
    }

    void* allocate() {
        if (freeBlocks.empty()) {
            return std::malloc(blockSize);
        } else {
            void* block = freeBlocks.back();
            freeBlocks.pop_back();
            return block;
        }
    }

    void deallocate(void* block) {
        freeBlocks.push_back(block);
    }
};