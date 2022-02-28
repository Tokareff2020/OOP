#pragma once
#include "triangle.h"
#include "titerator.h"
#include "TAllocationBlock.h"

template <class T>
class TLinkedList {
private:
    struct TLinkedListItem {
        std::shared_ptr<T> data;
        std::shared_ptr<TLinkedListItem> next;
    };
    size_t size;
    std::shared_ptr<TLinkedListItem> begin_;
    std::shared_ptr<TLinkedListItem> end_;
    static TAllocationBlock tlinkedlistItemAllocator;

public:
    TLinkedList();
    TLinkedList(const TLinkedList<T>& tlinkedlist);
    size_t Length();
    bool Empty();
    T Top();
    void Push(const std::shared_ptr<T> t);
    void Pop();
    void Clear();
    template<typename Y>
    friend std::istream& operator>>(std::istream& is, TLinkedList<Y>& object);
    template<typename Y>
    friend std::ostream& operator<<(std::ostream& os, const TLinkedList<Y>& object);

    TIterator<TLinkedListItem, T> begin();
    TIterator<TLinkedListItem, T> end();

    void* operator new (size_t size);
    void operator delete(void* p);

    virtual ~TLinkedList();
};

