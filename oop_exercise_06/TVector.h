#pragma once
#include <cstring>


template<class T>
class TVector
{
public:
    TVector();
    TVector(const TVector& v);
    TVector(size_t n, const T& val = T());

    void push_back(const T& val);
    void erase(size_t index);
    void resize(size_t n, const T& val = T());
    void clear();
    size_t size() const;
    bool empty() const;

    T& operator[](size_t i);
    TVector& operator=(const TVector& v);

    ~TVector();

private:
    T* _begin;
    size_t _size;
    size_t _cap;
    void _copy(const TVector& v);
};


