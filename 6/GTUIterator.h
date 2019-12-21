#ifndef GTUITERATOR_H
#define GTUITERATOR_H
#include "GTUNode.h"
#include <iostream>
#include <memory>

template <class T>
class GTUIterator
{
public:
    GTUIterator() {}
    GTUIterator(std::shared_ptr<Node<T>> ptr);
    GTUIterator(T *ptr) : ptr_(ptr)
    {
    }

    GTUIterator operator++() //prefix ++ operator overload
    {
        ptr_ = ptr_.get()->next;
        return *this;
    }
    GTUIterator operator++(int junk) //postfix ++ operator overload
    {
        auto x = new GTUIterator(ptr_);
        ptr_ = ptr_.get()->next;
        return *x;
    }
    GTUIterator operator--() //prefix -- operator overload
    {
        ptr_ = ptr_.get()->prev;
        return *this;
    }
    GTUIterator operator--(int junk) //postfix -- operator overload
    {
        auto x = new GTUIterator(ptr_);
        ptr_ = ptr_.get()->prev;
        return *x;
    }
    auto operator*() { return ptr_.get(); }
    std::shared_ptr<T> *operator->() { return ptr_; }
    bool operator==(const GTUIterator &other) { return ptr_ == other.ptr_; }
    bool operator!=(const GTUIterator &other) { return ptr_ != other.ptr_; }
    std::shared_ptr<Node<T>> ptr_;
    
};

template <class T>
GTUIterator<T>::GTUIterator(std::shared_ptr<Node<T>> ptr) : ptr_(ptr) {}

#endif