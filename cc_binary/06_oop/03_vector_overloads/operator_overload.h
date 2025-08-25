#include <iostream>
#include <vector>

class Vector {
    std::vector<int> elements;
public:
    Vector(const std::vector<int>& elems) : elements(elems) {}

    Vector operator+(const Vector& other) const {
        if (elements.size() != other.elements.size()) {
            throw std::runtime_error("Vector sizes do not match");
        }
        std::vector<int> result;
        for (size_t i = 0; i < elements.size(); ++i) {
            result.push_back(elements[i] + other.elements[i]);
        }
        return Vector(result);
    }

    void print() const {
        for (int e : elements) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
};