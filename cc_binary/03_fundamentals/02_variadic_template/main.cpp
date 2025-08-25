#include <iostream>
#include <utility>
#include <typeinfo>

template<typename F, typename... Args>
auto function_logger(F&& f, Args&&... args) {
    // Log argument types
    (std::cout << ... << (std::string(typeid(Args).name()) + " "));
    std::cout << "\n";

    // Perfect forward the call
    return std::forward<F>(f)(std::forward<Args>(args)...);
}

// Example usage
int add(int a, int b) { return a + b; }
auto main() -> int {
    auto result = function_logger(add, 5, 3);
    std::cout << "Result: " << result << "\n";
    return 0;
}