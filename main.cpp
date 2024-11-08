#include "list.hpp"
#include <iostream>
#include "fake.cpp"

int main(void) {

    int a = 7;
    int b = 8;
    int c = 9;
    m34::Node<int> *root = m34::Node<int>::CreateNode(a);
    root->next = m34::Node<int>::CreateNode(b);
    root->next->next = m34::Node<int>::CreateNode(c);

    m34::iterators::Iterator<m34::Node<int>> beg = root->begin();
    auto it = *beg;

    std::cout << it.data;
    //std::cout << beg.pointer->data;

    fake v;

    v.f<int>(); /* m34::iterators::Iterator<T> * operator don't work with data structures    in which name of field is not 'date'

pls. Check fake.cpp */
    //std::cout << it << std::endl;
}
