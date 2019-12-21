#ifndef GTUNODE_H
#define GTUNODE_H
#include <iostream>
#include <memory>
template <typename T>
struct Node
{
    T value;
    bool head = false;
    bool end = false;
    std::shared_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> prev;

    Node() : head(true),end(true), value(-1){};                           // head with -1 value
    Node(T value) : head(false),end(true), value(value), prev(nullptr){}; // node

    std::shared_ptr<Node<T>> add_next(T value)
    {
        next = std::make_shared<Node<T>>(value);
        next->next = nullptr;
        next->prev = nullptr;
        return next;
    }
};

#endif