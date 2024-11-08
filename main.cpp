#include "list.hpp"

int main(void) {

    int a = 7;
    int b = 8;
    int c = 9;
    m34::Node<int> *root = m34::Node<int>::CreateNode(a);
    root->next = m34::Node<int>::CreateNode(b);
    root->next->next = m34::Node<int>::CreateNode(c);

    m34::iterators::Iterator<m34::Node<int>> beg = root->end();
}
