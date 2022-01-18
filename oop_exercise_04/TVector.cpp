#include "TVector.h"
#include "Trapeze.h"
#include <iostream>



TVector::TVector() : length(0), count(0)
{
    arr = new Trapeze[1];
}

TVector::~TVector()
{
    delete[] arr;
}

int TVector::Length()
{
    return length;
}

bool TVector::Empty()
{
    if (count == 0) return true;
    else return false;
}

void TVector::Resize(int a)
{
    Trapeze *narr = new Trapeze[a];
    if (a > length) 
    {
        for (int i = 0; i != a; i++)
        {
            narr[i] = arr[i];
        }
        delete[] arr;
        arr = narr;
        length = a;
    }
    else if (a == length)
    {
        return;
    }
    else
    {
        for (int i = 0; i != a; i++)
            narr[i] = arr[i];
        delete[] arr;
        arr = narr;
        length = a;
    }
}



void TVector::Remove(int pos)
{
    if (count == 0)
    {
        std::cout << "Container is empty" << std::endl;
        return;
    }
    Trapeze* narr = new Trapeze[length - 1];
    int a = 0;

    for (int i = 0; i != length; i++)
    {
        if ((i != pos) && a == 0)
            narr[i] = arr[i];
        else if (i == pos)
            a++;
        else 
            narr[i - a] = arr[i];
    }
    count--;
    length--;
    delete[] arr;
    arr = narr;

}


Trapeze& TVector::operator[](int i)
{
    if (i >= 0 && i < this->length)
        return this->arr[i];
    else exit;
}


const Trapeze TVector::Last()
{
    Trapeze* narr = new Trapeze[length];
    for (int i = 0; i < count - 1; i++)
    {
        narr[i] = arr[i];
    }
    Trapeze tmp = arr[count - 1];
    count--;
    length--;
    delete[] arr;
    arr = narr;
    return tmp;
}

void TVector::InsertLast(Trapeze& newrec)
{
    if (count == length)
    {
        length++;
        count++;
        Trapeze* narr = new Trapeze[length];
        for (int i = 0; i < length - 1; i++)
            narr[i] = arr[i];
        narr[length - 1] = newrec;
     
        delete[] arr;
        arr = narr;
    }
    else if (count < length)
    {
        arr[count] = newrec;
        count++;
    }
}


void TVector::Clear()
{
    
   delete[] arr;
    length = 0;
    count = 0;
}

std::ostream& operator<<(std::ostream& out, TVector& cont)
{
    for (int i = 0; i < cont.count; i++)
    {
        out << "Трапеция #" << i + 1 << cont[i];
    }
    return out;
}
