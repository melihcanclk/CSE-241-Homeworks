#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H
#include "GTUIterator.h"
#include <memory>

template <class T>
class GTUContainer
{
public:
    GTUContainer() //constructor of that GTUContainer
    {
        head = std::make_shared<Node<T>>();
        tail = std::make_shared<Node<T>>();
        head.get()->next = tail;
        head.get()->prev = nullptr;
        tail.get()->next = nullptr;
        tail.get()->prev = head;
    }
    virtual bool empty() = 0;
    virtual int size() = 0;
    virtual int max_size() = 0;
    virtual void insert(GTUIterator<T> iter,T inserted) = 0;
    virtual void erase(GTUIterator<T> iter) = 0;
    virtual void clear() = 0;
    virtual GTUIterator<T> begin() = 0;
    virtual GTUIterator<T> end() = 0;

    protected:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
};

#endif
