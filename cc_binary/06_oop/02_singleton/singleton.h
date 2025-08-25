#include <memory>

// Thread-safe singleton

template<typename T>
class SingleThreadedLocking {
protected:
    void lock() {}
    void unlock() {}
};

template<typename T>
class MultiThreadedLocking {
    std::mutex mutex;
protected:
    void lock() { mutex.lock(); }
    void unlock() { mutex.unlock(); }
};

template<
    typename T,
    template<typename> class LockingPolicy = MultiThreadedLocking
>
class Singleton : private LockingPolicy<T> {
    static std::unique_ptr<T> instance;

public:
    static T& getInstance() {
        this->lock();
        if (!instance) {
            instance = std::make_unique<T>();
        }
        this->unlock();
        return *instance;
    }

protected:
    Singleton() = default;
    ~Singleton() = default;
};

template<typename T, template<typename> class L>
std::unique_ptr<T> Singleton<T, L>::instance;