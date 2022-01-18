#include "list.cpp"

using namespace std;




 

int main()
{
    setlocale(LC_ALL, "Russian");
    pentagon fig1;
    fig1.input();
    fig1.output();
    list list;
    list.insert_last(std::shared_ptr <pentagon> (new pentagon));

    list.insert_last(std::shared_ptr <pentagon>(new pentagon(1, 2, 5)));
    list.insert_last(std::shared_ptr <pentagon>(new pentagon(1, 3, 6)));
    list.output();
}
