#ifndef __LIST_H
#define __LIST_H

#include "iterator.hpp"

namespace m34 {

template <class T> class Node {
  public:
    T data;
    Node *next;
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
    Node(T data, Node *next) {
        this->data = data;
        this->next = next;
        next->next = nullptr;
    }

    void operator=(Node *other) {
        this->data = other->data;
        this->next = other->next;
    }

    static Node *CreateNode(T data) {
        Node<T> *node = new Node<T>(data);
        return node;
    }

    iterators::Iterator<Node<T>> begin() {
        auto tmp = this;

        return iterators::Iterator<Node<T>>(tmp);
    }

    iterators::Iterator<Node<T>> end() {
        auto tmp = this;

        while (tmp->next != nullptr)
            tmp = tmp->next;

        return iterators::Iterator<Node<T>>(tmp);
    }
};
} // namespace m34

#endif
