#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "queueADT.h"
#include <stdexcept>

template <class t>
class arrayQueue : public queueADT<t>
{
public:
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue();
    t front() const;
    t back() const;
    void enqueue(const t &queueElement);
    t dequeue();
    const arrayQueue<t> &operator=(const arrayQueue<t> &);
    arrayQueue(int size = DEFAULT_QUEUE_SIZE);
    arrayQueue(const arrayQueue<t> &);
    ~arrayQueue();

private:
    const static int DEFAULT_QUEUE_SIZE = 100;
    void copyQueue(const arrayQueue<t> &);
    int maxQueueSize;
    int queueRear;
    int queueFront;
    int count;
    t **list;
};

#endif

template <class t>
inline bool arrayQueue<t>::isEmptyQueue() const
{
    return this->count == 0;
}

template <class t>
inline bool arrayQueue<t>::isFullQueue() const
{
    return this->count == this->maxQueueSize;
}

template <class t>
inline arrayQueue<t>::arrayQueue(int size)
{
    this->maxQueueSize = size;
    this->list = new t *[maxQueueSize];
    count = 0;
    initializeQueue();
}
