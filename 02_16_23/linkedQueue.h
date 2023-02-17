#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "queueADT.h"
#include <stdexcept>

template <class t>
struct queueNode
{
    t *info;
    queueNode<t> *link;
    ~queueNode()
    {
        delete info;
    }
};

template <class t>
class linkedQueue : public queueADT<t>
{
public:
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue();
    t front() const;
    t back() const;
    void enqueue(const t &queueElement);
    t dequeue();
    const linkedQueue<t> &operator=(const linkedQueue<t> &);
    linkedQueue();
    linkedQueue(const linkedQueue<t> &);
    ~linkedQueue();

private:
    queueNode<t> *queueFront;
    queueNode<t> *queueRear;
    void copyQueue(const linkedQueue<t> &);
};

#endif

template <class t>
inline bool linkedQueue<t>::isEmptyQueue() const
{
    return this->queueFront == nullptr;
}

template <class t>
inline bool linkedQueue<t>::isFullQueue() const
{
    return false;
}

template <class t>
inline linkedQueue<t>::linkedQueue()
{
    this->queueFront = nullptr;
    this->queueRear = nullptr;
}
