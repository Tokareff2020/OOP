#include "TVector.h"

template<class T>
TVector<T>::TVector()
{
    _begin = new T[1];
    _size = 0;
    _cap = 1;
}

template<class T>
TVector<T>::TVector(const TVector& v)
{
    _begin = new T[1];
    _size = 0;
    _cap = 1;

    if (this != &v)
        _copy(v);
}

template<class T>
TVector<T>::TVector(size_t n, const T& val)
{
    _begin = new T[n + 1];

    for (size_t i = 0; i < n; i++)
        _begin[i] = val;

    _size = n;
    _cap = n + 1;
}

template<class T>
TVector<T>::~TVector()
{
    delete[] _begin;
}

template<class T>
void TVector<T>::push_back(const T& val)
{
    if (_size == _cap)
    {
        size_t oldSize = _size;

        resize(_size * 2);

        _size = oldSize;
    }

    _begin[_size++] = val;
}

template<class T>
void TVector<T>::erase(size_t index)
{
    for (size_t i = index; i < _size - 1; i++)
        _begin[i] = _begin[i + 1];

    _size--;
}

template<class T>
void TVector<T>::resize(size_t n, const T& val)
{
    const size_t copySize = n < _size ? n : _size;
    T* _buffer = new T[n + 1];

    for (size_t i = 0; i < copySize; i++)
        _buffer[i] = _begin[i];

    for (size_t i = copySize; i < n; i++)
        _buffer[i] = val;

    delete[] _begin;

    _begin = _buffer;
    _size = n;
    _cap = n + 1;
}

template<class T>
void TVector<T>::clear()
{
    delete[] _begin;

    _begin = new T[1];
    _size = 0;
    _cap = 1;
}

template<class T>
size_t TVector<T>::size() const
{
    return _size;
}

template<class T>
bool TVector<T>::empty() const
{
    return _size == 0;
}

template<class T>
T& TVector<T>::operator[](size_t i)
{
    return _begin[i];
}

template<class T>
TVector<T>& TVector<T>::operator=(const TVector& v)
{
    if (this != &v)
        _copy(v);

    return *this;
}

template<class T>
void TVector<T>::_copy(const TVector& v)
{
    const size_t n = v.size();

    delete[] _begin;

    _begin = new T[n + 1];

    for (size_t i = 0; i < n; i++)
        _begin[i] = v._begin[i];

    _size = n;
    _cap = n + 1;
}

template class TVector<void*>;
