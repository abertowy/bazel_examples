#include <iostream>
#include <memory>

class MemoryArena {
    static constexpr size_t DEFAULT_BLOCK_SIZE = 4096;
    struct Block {
        std::byte* data;
        size_t size;
        size_t used;
        Block* next;

        Block(size_t s)
            : data(new std::byte[s])
            , size(s)
            , used(0)
            , next(nullptr) {}

        ~Block() { delete[] data; }
    };

    Block* current_block = nullptr;

public:
    void* allocate(size_t size, size_t alignment = alignof(std::max_align_t)) {
        size_t space_needed = size + alignment - 1;

        if (!current_block || current_block->used + space_needed > current_block->size) {
            auto new_block = new Block(std::max(space_needed, DEFAULT_BLOCK_SIZE));
            new_block->next = current_block;
            current_block = new_block;
        }

        std::byte* raw = current_block->data + current_block->used;
        void* aligned = std::align(
            alignment, size,
            reinterpret_cast<void*&>(raw),
            current_block->size - current_block->used
        );

        if (aligned) {
            current_block->used =
                (reinterpret_cast<std::byte*>(aligned) - current_block->data) + size;
            return aligned;
        }

        return nullptr;
    }

    void reset() {
        while (current_block) {
            Block* next = current_block->next;
            delete current_block;
            current_block = next;
        }
    }
};