#include "GTUContainer.h"
#include "GTUIterator.h"
#include <iostream>
#include <fstream>
#include <memory>

template <class T>
class GTUSet : public GTUContainer<T>
{
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;

    bool isContain(T value)
    {
        auto current = head;
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

public:
    GTUSet()
    { //constructor of that GTUSet
        head = std::make_shared<Node<T>>();
        tail = head;
    }

    GTUIterator<T> begin() override
    {
        return GTUIterator<T>(head.get()->next);
    }

    GTUIterator<T> end() override
    {
        auto current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        return GTUIterator<T>(current);
    }

    void add_node(T value)
    {

        tail->add_next(value);
        tail->prev = tail;
        tail = tail->next;
    }

    void print()
    {
        std::cout << std::string(100, '-') << '\n';
        auto current = head->next;
        while (current != nullptr)
        {
            std::cout << current->value << '\t';
            current = current->next;
        }
        std::cout << '\n'
                  << std::string(100, '-') << '\n';
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
        auto current = head;
        while (current != nullptr && !isContain(value))
        {
            if (current->next == nullptr || current->next->value > value)
            {
                if (current->next == nullptr) //eğer ilk veya son node'a ekleme yapılacaksa
                {
                    auto node = create_node(value);
                    node->prev = current;
                    current->next = node;
                }
                else //diğer case'ler

                {
                    auto temp_next = current->next;
                    auto node = create_node(value);
                    node->prev = current;
                    node->next = temp_next;
                    current->next = node;
                    node = temp_next->prev;
                }
            }
            current = current->next;
        }
    }
    bool empty() override
    {
        if (head == tail)
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
        auto current = head;
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

    void insert_before(T before_value, T value)
    {
        auto current = head;
        std::shared_ptr<Node<T>> prev;
        while (current != nullptr)
        {
            if (current->value == before_value)
            {
                auto node = create_node(value);
                node->next = current;
                prev->next = node;
            }
            prev = current;
            current = current->next;
        }
    }

    std::shared_ptr<Node<T>> create_node(T value)
    {
        return std::make_shared<Node<T>>(value);
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Node<T> other) //print content of Node<T>
{
    std::cout << other.value;
    return os;
}