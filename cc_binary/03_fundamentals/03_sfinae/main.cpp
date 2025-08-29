#include <type_traits>
#include <vector>

template<typename T, typename = void>
struct has_size_method : std::false_type {};

template<typename T>
struct has_size_method<T, std::void_t<decltype(std::declval<T>().size())>> : std::true_type {};

template<typename Container>
auto get_size(const Container& c)-> std::enable_if_t<has_size_method<Container>::value, size_t> {
    return c.size();
}

// Example usage
int main() {
    std::vector<int> v{1, 2, 3};
    auto size = get_size(v);  // Works
    // get_size(42);  // Compilation error
    return 0;
}