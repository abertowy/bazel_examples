#include "linked_list.h"

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.print();
    list.remove();
    list.print();
    return 0;
}