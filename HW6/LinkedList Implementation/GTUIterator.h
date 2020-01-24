#ifndef GTUITERATOR_H
#define GTUITERATOR_H
#include "GTUNode.h"
#include "GTUSet.h"
#include <iostream>
#include <memory>

using namespace STLGTUNode;

template <class T>
class GTUIterator
{
public:
    GTUIterator() {}
    GTUIterator(std::shared_ptr<Node<T>> ptr);

    GTUIterator operator++() //prefix ++ operator overload
    {
        try
        {
            if (ptr_.get()->next == nullptr)
            {
                throw "Out of bound";
            }
            ptr_ = ptr_.get()->next;
            return *this;
        }
        catch (const char *massage)
        {
            std::cerr << massage;
        }
    }
    GTUIterator operator++(int junk) //postfix ++ operator overload
    {
        try
        {
            GTUIterator<T>* x = new GTUIterator(ptr_);
            if (ptr_.get()->next == nullptr)
            {
                throw "Out of bound";
            }
            ptr_ = ptr_.get()->next;
            return *x;
        }
        catch (const char *massage)
        {
            std::cerr << massage;
        }
    }
    GTUIterator operator--() //prefix -- operator overload
    {
        try
        {
            if (ptr_.get()->prev == nullptr)
            {
                throw "Out of bound";
            }
            ptr_ = ptr_.get()->prev;
            return *this;
        }
        catch (const char *massage)
        {
            std::cerr << massage;
        }
    }
    GTUIterator operator--(int junk) //postfix -- operator overload
    {
        try
        {
            GTUIterator<T> *x = new GTUIterator(ptr_);
            if (ptr_.get()->prev == nullptr)
            {
                throw "Out of bound";
            }
            ptr_ = ptr_.get()->prev;
            return *x;
        }
        catch (const char *massage)
        {
            std::cerr << massage;
        }
    }
    bool operator!=(std::nullptr_t nullp)
    {
        return ptr_.get()->next != nullp;
    }
    
    T operator*() { return ptr_.get()->value; }
    T *operator->() { return *(ptr_.get()->value); }
    bool operator==(const GTUIterator &other) { return ptr_ == other.ptr_; }
    bool operator!=(const GTUIterator &other) { return ptr_ != other.ptr_; }
    std::shared_ptr<Node<T>> ptr_;
};

template <class T>
GTUIterator<T>::GTUIterator(std::shared_ptr<Node<T>> ptr) : ptr_(ptr) {}

#endif