#include "triangle.h"
#include "tlinkedlist.h"

void help() {
    std::cout << "Select an action" << std::endl;
    std::cout << "1) Print the top element" << std::endl;
    std::cout << "2) Remove an item from the list" << std::endl;
    std::cout << "3) Print items from the list" << std::endl;
    std::cout << "4) Clear the list" << std::endl;
    std::cout << "5) Add an item to the list" << std::endl;
    std::cout << "6) Print the list length" << std::endl;
    std::cout << "7) Is the list empty?" << std::endl;
    std::cout << "8) End the program" << std::endl;
}
void Test()
{
    TAllocationBlock allocator(sizeof(int), 10);

    int* b1 = nullptr;
    int* b2 = nullptr;
    int* b3 = nullptr;
    int* b4 = nullptr;
    int* b5 = nullptr;

    b1 = (int*)allocator.Allocate();
    *b1 = 1;
    std::cout << "b1 pointer value:" << *b1 << std::endl;
    b2 = (int*)allocator.Allocate();
    *b2 = 2;
    std::cout << "b2 pointer value:" << *b2 << std::endl;
    b3 = (int*)allocator.Allocate();
    *b3 = 3;
    std::cout << "b3 pointer value:" << *b3 << std::endl;

    allocator.Deallocate(b1);
    allocator.Deallocate(b3);

    b4 = (int*)allocator.Allocate();
    *b4 = 4;
    std::cout << "b4 pointer value:" << *b4 << std::endl;
    b5 = (int*)allocator.Allocate();
    *b5 = 5;
    std::cout << "b5 pointer value:" << *b5 << std::endl;
    std::cout << "b1 pointer value:" << *b1 << std::endl;
    std::cout << "b2 pointer value:" << *b2 << std::endl;
    std::cout << "b3 pointer value:" << *b3 << std::endl;

    allocator.Deallocate(b2);
    allocator.Deallocate(b4);
    allocator.Deallocate(b5);
}

int main() {
    Test();
    return 0;
}
