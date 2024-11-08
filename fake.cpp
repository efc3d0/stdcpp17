#include "iterator.hpp"
#include <iostream>

struct fake
{
  int *date;
  template<class T>
  void f()
  {
    m34::iterators::Iterator<T> g(date);

    *g;

    std::cout << *g.pointer;
  }
} ;   
