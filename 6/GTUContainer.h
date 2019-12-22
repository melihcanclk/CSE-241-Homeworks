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
    virtual void insert(T inserted) = 0;
    virtual void erase(GTUIterator<T> iter) = 0;
    virtual void clear() = 0;
    virtual GTUIterator<T> begin() = 0;
    virtual GTUIterator<T> end() = 0;

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
    protected:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
};
template <typename T>
std::ostream &operator<<(std::ostream &os, Node<T> other) //friend function for print content of Node<T>
{
    if(other.value == -1 && other.end == true){         //if node doesn't show last node
    }else{
        std::cout << other.value;
    }
    return os;
}
#endif
