#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T, std::size_t N>
class static_vector
{
public:
    static_vector() : m_size(0) { std::cout << "DEFAULT CTR" << std::endl; }
    static_vector(std::initializer_list<T> initList) : m_size{initList.size()} {
        std::cout << "INIT LIST CTR" << std::endl;
        std::uninitialized_copy(initList.begin(), initList.end(), m_data);
    }
    static_vector(const static_vector& other) : m_size{other.size()} {
        std::cout << "Copy CTR" << std::endl;
        for (std::size_t i = 0; i < other.size(); ++i) {
            m_data[i] = other[i];
        }
    }
    static_vector& operator=(const static_vector& other) {
        std::cout << "Copy ASSIGNMENT" << std::endl;
        if (&other == this) {
            return *this;
        }
        clear();
        m_size = other.m_size;
        for (std::size_t i = 0; i < other.size(); ++i) {
            m_data[i] = other[i];
        }
        return *this;
    }
    static_vector(static_vector&& other) : m_size{other.size()}{
        std::cout << "Move CTR" << std::endl;
        std::move(std::begin(other.m_data), std::end(other.m_data), std::begin(m_data));
        // std::uninitialized_move(&other[0], &other[other.size()], m_data);
    }
    static_vector& operator=(static_vector&& other) {
        std::cout << "Move ASSIGNMENT" << std::endl;
        if (&other == this) {
            return *this;
        }
        clear();
        m_size = other.m_size;
        std::uninitialized_copy(
            std::make_move_iterator(std::begin(other.m_data)),
            std::make_move_iterator(std::end(other.m_data)),
            std::begin(m_data)
        );
        return *this;
    }
    ~static_vector() { std::cout << "DTR" << std::endl; clear(); }

    // operators
    T& operator[](std::size_t idx) { return m_data[idx]; }
    const T& operator[](std::size_t idx) const { return m_data[idx]; }
    static_vector operator+(const static_vector& other) {
        std::cout << "OPERATOR+" << std::endl;
        static_vector res;
        for (std::size_t i = 0; i < m_size; ++i) {
            res.m_data[i] = m_data[i] + other[i];
        }
        res.m_size = m_size;
        return res;
    }

    std::size_t capacity() const { return N; }
    std::size_t size() const {return m_size; }
    void push_back(const T& val) {
        if (m_size == N) {
            throw std::out_of_range("ARR CONTAINS MAX VALS");
        }
        m_data[m_size] = val;
        ++m_size;
    }

    void clear() {std::destroy(m_data, m_data + m_size);}

private:
    T m_data[N];
    std::size_t m_size;
};
