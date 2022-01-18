#ifndef TVECTOR_H
#define TVECTOR_H
#include "Trapeze.h"
#include <iostream>


class TVector
{
private:
    int length;
    int count;
    Trapeze* arr;
public:
    TVector();
    ~TVector();
    TVector(const TVector& other);
    void InsertLast(Trapeze& newrec);
    const Trapeze Last();
    int Length();
    bool Empty();
    void Resize(int nindex);
    void Remove(int pos);
    void Clear();

    Trapeze& operator[] (int i);
    friend std::ostream& operator<<(std::ostream& out, TVector& cont);
};

#endif // TVECTOR_H
