#include <iostream>
#include <string>

class Document {
    std::string content;

public:
    Document(const std::string& text) : content(text) {}

    const std::string& getContent() const { return content; }
    std::string& getContent() { return content; }
};

int main() {
    Document doc("Sample text");
    std::cout << "Const: " << static_cast<const Document&>(doc).getContent() << std::endl;
    doc.getContent() = "New text";
    std::cout << "Non-Const: " << doc.getContent() << std::endl;
    return 0;
}