#include <iostream>
#include <utility>
#include <cassert>

template <class T>
void default_delete(T *p) {
    delete p;
}

// template <class T>
// void default_array_delete(T *p) {
//     delete [] p;
// }

template <class T>
class shared_ptr {
    using delete_fn = void (*) (T*);

    T* ptr;
    int *cnt;
    delete_fn del;

public:
    shared_ptr() noexcept : ptr(nullptr), cnt(nullptr), del(default_delete<T>) {
        std::cout << "Default CTR" << std::endl;
    }

    explicit shared_ptr(T* p) noexcept : ptr(p), cnt(new int(1)), del(default_delete<T>) {
        std::cout << "Explicit CTR (pointer)" << std::endl;
    }

    shared_ptr(T* p, delete_fn d) noexcept : ptr(p), cnt(new int(1)), del(d) {
        std::cout << "CTR (pointer, deleter)" << std::endl;
    }

    shared_ptr(const shared_ptr &other) noexcept : shared_ptr(other.ptr, other.del) {
        cnt = other.cnt;
        ++*cnt;
        std::cout << "COPY CTR" << std::endl;
    }

    shared_ptr(shared_ptr &&other) : ptr(std::move(other.ptr)), cnt(std::move(other.cnt)), del(std::move(other.del)) {
        std::cout << "MOVE CTR" << std::endl;
        other.ptr = nullptr;
        other.cnt = nullptr;
    }

    shared_ptr& operator = (const shared_ptr& other) {
        std::cout << "Copy ASSIGNMENT" << std::endl;
        if (this != &other) {
            reset();
            ptr = other.ptr;
            cnt = other.cnt;
            del = other.del;
            ++*cnt;
        }
        return *this;
    }

    shared_ptr& operator = (shared_ptr&& other) {
        std::cout << "Move ASSIGNMENT" << std::endl;
        shared_ptr::swap(other);
        return *this;
    }

    void swap(shared_ptr &other) {
        std::cout << "SWAP" << std::endl;
        std::swap(ptr, other.ptr);
        std::swap(cnt, other.cnt);
        std::swap(del, other.del);
    }

    ~shared_ptr() {
        std::cout << "DTR" << std::endl;
        if (cnt != nullptr) {
            std::cout << "dtr cnt:" << *cnt << std::endl;
        }
        if (cnt != nullptr && --*cnt == 0) {
            std::cout << " destroyed " << *ptr << std::endl;
            del(ptr);
            delete cnt;
        }
    }

    T* operator -> () const noexcept {
        return ptr;
    }

    T& operator * () const noexcept {
        return *ptr;
    }

    T* get() const noexcept {
        return ptr;
    }

    explicit operator bool() const noexcept {
        return ptr != nullptr;
    }

    bool unique() const noexcept {
        return use_count() == 1;
    }

    int use_count() const noexcept {
        return cnt != nullptr ? *cnt : 0;
    }

    void reset() {
        this->~shared_ptr();
        ptr = nullptr;
        cnt = nullptr;
    } // equivalent to: shared_ptr().swap(*this);

    void reset(T* p) {
        reset();
        cnt = new int(1);
        ptr = p;
    }

    void reset(T* p, delete_fn d) {
        reset();
        cnt = new int(1);
        ptr = p;
        del = d;
    }
};

template <class T, class... Args>
shared_ptr<T> make_shared(Args&& ...args) {
    return shared_ptr<T>( new T( std::forward<Args>(args)... ) );
}
