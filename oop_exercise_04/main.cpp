#include <iostream>
#include "tvector.h"

int main()
{
    setlocale(LC_ALL, "Ru");
    TVector container;
    Trapeze rec1(0, 0, 3, 5, 7);
    Trapeze rec2(1, 2, 3, 4, 5);
    Trapeze rec3(4, 5, 6, 7, 3);
    Trapeze rec4(1, 3, 4, 7, 4);
   container.InsertLast(rec1);
    container.InsertLast(rec2);
    container.InsertLast(rec3);
    container.InsertLast(rec4);
    std::cout << container;
    std::cout << "Размер контейнера :" << container.Length() << std::endl;
    container.Remove(2);
    std::cout << "Вывод после удаления элемента.\n";
    
    std::cout << container;
    std::cout << "Размер контейнера :" << container.Length() << std::endl;
    return 0;
}
