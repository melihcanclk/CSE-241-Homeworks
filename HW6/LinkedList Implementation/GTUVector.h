#ifndef GTUVECTOR_H
#define GTUVECTOR_H
#include "GTUContainer.h"
#include "GTUIterator.h"
#include <iostream>
#include <memory>

template <class T>
class GTUVector : public GTUContainer<T>
{
private:
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
    void insert(GTUIterator<T> iter, T value) override
    {

        std::shared_ptr<Node<T> > node = create_node(value);
        node->prev = iter.ptr_;
        node->next = iter.ptr_.get()->next;
        iter.ptr_.get()->next->prev = node;
        iter.ptr_.get()->next = node;
        if (iter.ptr_ == GTUContainer<T>::head && iter.ptr_.get()->head == true)
        {
            GTUContainer<T>::head = GTUContainer<T>::head.get()->next;
        }
    }

    void erase(GTUIterator<T> iter) override
    {
        iter.ptr_.get()->next = iter.ptr_.get()->prev->next;
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
        return counter + 1;
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

    T operator[](int index)
    {
        try
        {
            std::shared_ptr<Node<T> > current = GTUContainer<T>::head;
            const int _size = size();
            if (index < 0 || index > _size)
                throw "Index problem";
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current.get()->value;
        }
        catch (const char *message)
        {
            std::cerr << message << std::endl;
        }
    }
    const T operator[](int index)const
    {
        try
        {
            std::shared_ptr<Node<T> > current = GTUContainer<T>::head;
            const int _size = size();
            if (index < 0 || index > _size)
                throw "Index problem";
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current.get()->value;
        }
        catch (const char *message)
        {
            std::cerr << message << std::endl;
        }
    }
};

#endif