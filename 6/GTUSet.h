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
    
    bool isContain(T value)
    {
        auto current = GTUContainer<T>::head;
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
        return GTUIterator<T>(GTUContainer<T>::head.get()->next);
    }

    GTUIterator<T> end() override
    {
        return GTUIterator<T>(GTUContainer<T>::tail);
    }

    /*void reverse()
    {
        auto current = head;
        std::shared_ptr<Node<T>> next, prev;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }*/

    void insert(T value) override
    {
        auto current = GTUContainer<T>::head;
        while (current != nullptr && !isContain(value))
        {
            if (current->next == nullptr || current->next->value > value)
            {
                if (current->next == nullptr) //eğer ilk veya son node'a ekleme yapılacaksa
                {
                    auto node = create_node(value);
                    node->next = nullptr;
                    node->prev = current;
                    current->next = node;
                    current->end = false;
                    GTUContainer<T>::tail = node;
                }
                else //diğer case'ler

                {
                    auto temp_next = current->next;
                    auto node = create_node(value);
                    node->prev = current;
                    node->next = temp_next;
                    current->next = node;
                    node = temp_next->prev;
                    GTUContainer<T>::tail = node;
                }
            }
            current = current->next;
        }
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
        GTUContainer<T>::head->next = nullptr;
    }

    bool empty() override
    {
        if (GTUContainer<T>::head == GTUContainer<T>::tail)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size() override
    {
        auto current = GTUContainer<T>::head;
        int counter = 0;
        while (current->next != nullptr)
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