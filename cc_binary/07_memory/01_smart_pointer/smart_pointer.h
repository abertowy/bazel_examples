template<typename T>
class SmartPtr {
    struct ControlBlock {
        std::atomic<size_t> strong_count{1};
        std::atomic<size_t> weak_count{0};
        T* ptr;

        explicit ControlBlock(T* p) : ptr(p) {}
        ~ControlBlock() { delete ptr; }
    };

    ControlBlock* control = nullptr;

public:
    explicit SmartPtr(T* ptr = nullptr) : control(new ControlBlock(ptr)) {}

    SmartPtr(const SmartPtr& other) {
        control = other.control;
        if (control) {
            control->strong_count++;
        }
    }

    ~SmartPtr() {
        if (control) {
            if (--control->strong_count == 0) {
                delete control->ptr;
                if (control->weak_count == 0) {
                    delete control;
                }
            }
        }
    }

    T* operator->() const { return control->ptr; }
    T& operator*() const { return *control->ptr; }
};