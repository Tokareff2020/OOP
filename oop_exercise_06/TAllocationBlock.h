#pragma once
#include <iostream>
#include <cstdlib>
#include "TVector.h"

typedef unsigned char Byte;

class TAllocationBlock
{
public:
    TAllocationBlock(size_t size, size_t count);
    void* Allocate();
    void Deallocate(void* ptr);
    bool Empty();
    size_t Size();

    virtual ~TAllocationBlock();

private:
    Byte* _used_blocks;
    TVector<void*> _free_blocks;
};

