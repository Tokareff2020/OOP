#include <iostream>
#include <memory>
#include "pentagon.h"
#include "mylist.cpp"
#include <algorithm>

void print_rect_and_area(std::shared_ptr<Pentagon> pent) {
    std::cout << *pent << "Area is equal " << abs(pent->Area()) << std::endl;
}

int main(void)
{
    setlocale(LC_ALL, "Russian");
    TLinkedList<Pentagon> list;
    std::shared_ptr<Pentagon> ptr = std::shared_ptr<Pentagon>(new Pentagon(1, 2, 3));
    list.InsertLast(ptr);
    ptr = std::shared_ptr<Pentagon>(new Pentagon(2, 3, 5));
    list.InsertLast(ptr);
    ptr = std::shared_ptr<Pentagon>(new Pentagon(1, 0, 6));
    list.Insert(ptr, 0);
    std::for_each(list.begin(), list.end(), print_rect_and_area);
    std::cout << std::endl;
    std::cout << *list[2] << std::endl;
    list.Remove(1);
    std::for_each(list.begin(), list.end(), print_rect_and_area);
    return 0;
}
