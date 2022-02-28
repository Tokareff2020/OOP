#include "tlinkedlist.h"
#include "tlinkedlist.cpp"


template class TLinkedList<Triangle>;

template std::ostream& operator<< <Triangle>(std::ostream&, TLinkedList<Triangle> const&);
