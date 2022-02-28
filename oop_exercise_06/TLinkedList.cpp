#include "TLinkedList.h"

template<typename T>
TLinkedList<T>::TLinkedList() {
    begin_ = std::shared_ptr<TLinkedListItem>(new TLinkedListItem);
    begin_->next = nullptr;
    size = 0;
    end_ = begin_;
}

template<typename T>
TLinkedList<T>::TLinkedList(const TLinkedList<T>& tlinkedlist) {
    std::shared_ptr<TLinkedListItem> item = tlinkedlist.begin_;

    while (item->next != nullptr) {
        std::shared_ptr<TLinkedListItem> item1(new TLinkedListItem);
        item1->next = nullptr;
        end_->data = item->data;
        end_->next = item1;
        end_ = item1;
        item = item->next;
    }
    size = tlinkedlist.size;
}

template<typename T>
size_t TLinkedList<T>::Length() {
    return size;
}

template<typename T>
bool TLinkedList<T>::Empty() {
    return (size == 0);
}

template <typename T>
T TLinkedList<T>::Top() {
    return *(begin_->data);
}

template <typename T>
void TLinkedList<T>::Push(const std::shared_ptr<T> t) {
    std::shared_ptr<TLinkedListItem> item(new TLinkedListItem);

    item->next = nullptr;
    end_->data = t;
    end_->next = item;
    end_ = item;
    size++;
}

template<typename T>
void TLinkedList<T>::Pop() {
    if (size == 0) {
        std::cout << "Unable to perform pop! The list is empty!" << std::endl;
        return;
    }
    std::shared_ptr<TLinkedListItem> item = this->begin_;
    begin_ = begin_->next;
    size--;
}

template <typename T>
std::istream& operator>> (std::istream& is, TLinkedList<T>& object) {
    std::shared_ptr<T> t;
    is >> *t;
    object.Push(t);
    return is;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const TLinkedList<T>& object) {

    std::shared_ptr<typename TLinkedList<T>::TLinkedListItem> item = object.begin_;

    while (item->next != nullptr) {
        os << item->data->Area() << " ";
        item = item->next;
    }
    return os;
}

template<typename T>
void TLinkedList<T>::Clear() {
    while (begin_->next != nullptr) {
        std::shared_ptr<TLinkedListItem> item = this->begin_;
        begin_ = begin_->next;
    }
    size = 0;
    begin_->next = nullptr;
    end_ = begin_;
}

template<typename T>
TLinkedList<T>::~TLinkedList() {
    while (begin_->next != nullptr) {
        std::shared_ptr<TLinkedListItem> item = this->begin_;
        begin_ = begin_->next;
    }
    size = 0;
}

template <class T>
TIterator<typename TLinkedList<T>::TLinkedListItem, T> TLinkedList<T>::begin() {
    return TIterator<typename TLinkedList<T>::TLinkedListItem, T>(begin_);
}

template <class T>
TIterator<typename TLinkedList<T>::TLinkedListItem, T> TLinkedList<T>::end() {
    return TIterator<typename TLinkedList<T>::TLinkedListItem, T>(end_);
}

template <class T> TAllocationBlock
TLinkedList<T>::tlinkedlistItemAllocator(sizeof(TLinkedListItem), 100);

template<class T>
void* TLinkedList<T>::operator new(size_t size)
{
    return tlinkedlistItemAllocator.Allocate();
}

template<class T>
void TLinkedList<T>::operator delete(void* p)
{
    tlinkedlistItemAllocator.Deallocate(p);
}
