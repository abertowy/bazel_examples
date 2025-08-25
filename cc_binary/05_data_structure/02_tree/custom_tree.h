template<
    typename Key,
    typename Value,
    size_t N = 64,
    typename Allocator = std::allocator<std::pair<Key, Value>>
>
class BPlusTree {
    struct Node {
        bool is_leaf;
        std::array<Key, N> keys;
        std::array<std::unique_ptr<Node>, N + 1> children;
        size_t size = 0;
        Node* next = nullptr;  // For leaf nodes

        Node(bool leaf = true) : is_leaf(leaf) {}
    };

    std::unique_ptr<Node> root;
    Allocator alloc;

public:
    void insert(const Key& key, const Value& value) {
        if (!root) {
            root = std::make_unique<Node>();
        }

        Node* current = root.get();
        while (!current->is_leaf) {
            size_t i = 0;
            while (i < current->size && key >= current->keys[i]) {
                ++i;
            }
            current = current->children[i].get();
        }

        // Insert into leaf node
        size_t pos = 0;
        while (pos < current->size && current->keys[pos] < key) {
            ++pos;
        }

        // Shift elements
        for (size_t i = current->size; i > pos; --i) {
            current->keys[i] = std::move(current->keys[i - 1]);
        }

        current->keys[pos] = key;
        ++current->size;

        // Split if necessary
        if (current->size == N) {
            split_node(current);
        }
    }

private:
    void split_node(Node* node) {
        // Implementation of node splitting
    }
};