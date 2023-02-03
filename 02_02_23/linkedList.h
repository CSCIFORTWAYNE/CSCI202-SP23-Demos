#ifndef LINKED_H
#define LINKED_H

#include <iostream>
#include <stdexcept>

template <class type>
struct nodeType
{
    type * data;
    nodeType<type> *link;
    ~nodeType()
    {
        delete data;
    }
};

template <class type>
class linkedListType
{
public:
    linkedListType();
    linkedListType(const linkedListType<type> &otherList);
    const linkedListType<type> &operator=(const linkedListType<type> &);

protected:
    nodeType<type> * head;
    nodeType<type> * tail;
    int count;
private:
    void copyList(const linkedListType<type>& otherList);
};

template <class type>
linkedListType<type>::linkedListType()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

#endif