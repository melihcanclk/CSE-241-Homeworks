#ifndef GTUSET_H
#define GTUSET_H
#include "GTUContainer.h"
#include "GTUIterator.h"
#include <iostream>
#include <memory>

template <class T>
class GTUSet : public GTUContainer<T>
{
private:
    bool isContain(T value)                     //control if GTUSet contains T value 
    {
        std::shared_ptr<Node<T> > current = GTUContainer<T>::head;
        while (current != nullptr)
        {
            if (current->value == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    std::shared_ptr<Node<T>> create_node(T value)
    {
        return std::make_shared<Node<T>>(value);
    }

public:
    GTUIterator<T> begin() override
    {
        return GTUIterator<T>(GTUContainer<T>::head);
    }

    GTUIterator<T> end() override
    {
        return GTUIterator<T>(GTUContainer<T>::tail);
    }

    void insert(T value)
    {
        std::shared_ptr<Node<T> > current = GTUContainer<T>::head;
        while (current != nullptr && !isContain(value))
        {
            if (current->next == GTUContainer<T>::tail || current->next->value > value)
            {
                std::shared_ptr<Node<T> > temp_next = current->next;
                std::shared_ptr<Node<T> > node = create_node(value);
                node->prev = current;
                node->next = temp_next;
                current->next->prev = node;
                current->next = node;
            }
            current = current->next;
        }
    }
    void insert(GTUIterator<T> iter, T value) override
    {
        std::shared_ptr<Node<T> > node = create_node(value);
        iter.ptr_.get()->next->prev = node;
        iter.ptr_.get()->next = node;
        node->prev = iter.ptr_;
        node->next = iter.ptr_.get()->next;
        iter = iter.ptr_.get()->next;
    }

    void erase(GTUIterator<T> iter) override
    {
        GTUIterator<T> temp1 = --iter;
        iter++;

        if (iter.ptr_.get()->next == nullptr)
        {
            temp1.ptr_.get()->next = nullptr;
        }
        else
        {
            temp1.ptr_.get()->next = iter.ptr_.get()->next;
        }
    }
    void clear() override
    {
        GTUContainer<T>::head.get()->next->prev = nullptr;
        GTUContainer<T>::head.get()->next = nullptr;
        GTUContainer<T>::tail.get()->prev->next = nullptr;
        GTUContainer<T>::tail.get()->next = nullptr;
        GTUContainer<T>::head.get()->next = GTUContainer<T>::tail;
        GTUContainer<T>::head.get()->prev = nullptr;
        GTUContainer<T>::tail.get()->next = nullptr;
        GTUContainer<T>::tail.get()->prev = GTUContainer<T>::head;
    }

    bool empty() override
    {
        return GTUContainer<T>::head->next == GTUContainer<T>::tail;
    }

    int size() override
    {
        std::shared_ptr<Node<T> > current = GTUContainer<T>::head;
        int counter = 0;
        while (current->next != GTUContainer<T>::tail)
        {
            ++counter;
            current = current->next;
        }
        return counter;
    }

    int max_size() override
    {
        int x = 1;
        while (size() > x)
        {
            x *= 2;
        }
        return x;
    }
};

#endif