#include <atomic>
#include <memory>

template<typename T>
class LockFreeQueue {
    struct Node {
        std::shared_ptr<T> data;
        std::atomic<Node*> next;
        Node() : next(nullptr) {}
    };

    std::atomic<Node*> head;
    std::atomic<Node*> tail;

public:
    LockFreeQueue() {
        Node* dummy = new Node();
        head.store(dummy);
        tail.store(dummy);
    }

    void push(T value) {
        auto data = std::make_shared<T>(std::move(value));
        Node* node = new Node();
        node->data = data;

        while (true) {
            Node* last = tail.load();
            Node* next = last->next.load();

            if (last == tail.load()) {
                if (next == nullptr) {
                    if (last->next.compare_exchange_weak(next, node)) {
                        tail.compare_exchange_weak(last, node);
                        return;
                    }
                } else {
                    tail.compare_exchange_weak(last, next);
                }
            }
        }
    }
};