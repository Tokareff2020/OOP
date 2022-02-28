#include "TAllocationBlock.h"

TAllocationBlock::TAllocationBlock(size_t size, size_t count)
{
    _used_blocks = (Byte*)malloc(size * count);

    for (size_t i = 0; i < count; ++i) {
        void* ptr = (void*)malloc(sizeof(void*));
        ptr = _used_blocks + i * size;
        _free_blocks.push_back(ptr);
    }
}

void* TAllocationBlock::Allocate()
{
    if (!_free_blocks.empty()) {
        void* res = _free_blocks[_free_blocks.size() - 1];
        _free_blocks.erase(_free_blocks.size() - 1);
        return res;
    }
    else {
        throw std::bad_alloc();
    }
}

void TAllocationBlock::Deallocate(void* ptr)
{
    _free_blocks.push_back(ptr);
}

bool TAllocationBlock::Empty()
{
    return _free_blocks.empty();
}

size_t TAllocationBlock::Size()
{
    return _free_blocks.size();
}

TAllocationBlock::~TAllocationBlock()
{
    _free_blocks.clear();
    free(_used_blocks);

}
