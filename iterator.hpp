#ifndef __ITERATOR_H
#define __ITERATOR_H

namespace m34 {
namespace iterators {
template <class T> class Iterator {
    using value_type = T;
    using pointer_type = T *;
    using reference_type = T &;
protected:
    T *pointer;
public:
    Iterator(T *ptr) : pointer(ptr) {}
protected:
    Iterator &operator*() { return *pointer; }

    Iterator &operator++() {
        ++pointer;
        return *this;
    }

    Iterator &operator++(int) {
        auto tmp = *this;
        ++tmp;
        return tmp;
    }
};

template <class T> class BackwardIterator : protected Iterator<T> {
  public:
    BackwardIterator() { Iterator<T>(this->pointer); }

    BackwardIterator &operator--() {
        --this->pointer;
        return *this;
    }

    BackwardIterator operator--(int) {
        auto tmp = *this;
        --tmp;
        return tmp;
    }
};
} // namespace iterators
} // namespace m34

#endif
