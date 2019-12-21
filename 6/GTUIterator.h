#ifndef GTUITERATOR_H
#define GTUITERATOR_H
#include "GTUNode.h"
#include "GTUSet.h"
#include <iostream>
#include <memory>

template <class T>
class GTUIterator
{
public:
    GTUIterator() {}
    GTUIterator(std::shared_ptr<Node<T>> ptr);

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
    bool operator!=(std::nullptr_t nullp)
    {
        if (ptr_.get()->next == nullptr)            //eğer next null pointer ise
        {
            if (ptr_.get()->value == -1 && ptr_.get()->end == true)//eğer temporary bir node oluşturuldu ise
            {
                ptr_ = ptr_->prev;
                return false;
            }
            else                                    //eğer temporary bir node oluşturulmadı ise
            {
                ptr_.get()->next = std::make_shared<Node<T>>();
                ptr_.get()->next->next = nullp;
                ptr_.get()->next->prev = ptr_;
                ptr_.get()->end = false;
            }
        }
        return ptr_ != nullp;
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