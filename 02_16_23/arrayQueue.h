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
inline t arrayQueue<t>::front() const
{
    if (this->isEmptyQueue())
        throw std::out_of_range("Cannot view item in an empty queue.");

    return *(list[queueFront]);
}
template <class t>
inline t arrayQueue<t>::back() const
{
    if (this->isEmptyQueue())
        throw std::out_of_range("Cannot view item in an empty queue.");

    return *(list[queueRear]);
}
template <class t>
void arrayQueue<t>::enqueue(const t &queueElement)
{

    if (this->isFullQueue())
    {
        throw std::overflow_error("Cannot add to a full queue.");
    }
    if (++this->queueRear >= this->maxQueueSize)
        this->queueRear = 0;
    list[queueRear] = new t(queueElement);
    count++;
}
template <class t>
inline t arrayQueue<t>::dequeue()
{
    if (this->isEmptyQueue())
        throw std::out_of_range("Cannot delete from an empty queue.");
    t ret(*(list[this->queueFront]));
    delete list[this->queueFront++];
    if (this->queueFront >= this->maxQueueSize)
        this->queueFront = 0;
    this->count--;
    return ret;
}
template <class t>
void arrayQueue<t>::initializeQueue()
{
    if (!this->isEmptyQueue())
    {
        int i = this->queueFront;
        bool end = false;
        while (!end)
        {
            if (i == this->queueRear)
                end = true;
            delete list[i++];
            if (i >= this->maxQueueSize)
                i = 0;
        }
    }
    this->queueFront = 0;
    this->queueRear = this->maxQueueSize - 1;
    this->count = 0;
}

template <class t>
inline arrayQueue<t>::arrayQueue(int size)
{
    this->maxQueueSize = size;
    this->list = new t *[maxQueueSize];
    this->count = 0;
    this->initializeQueue();
}

template <class t>
arrayQueue<t>::~arrayQueue()
{
    initializeQueue();
    delete[] list;
}

template <class t>
void arrayQueue<t>::copyQueue(const arrayQueue<t> &otherQueue)
{
    if (!this->isEmptyQueue())
    {
        this->initializeQueue();
    }
    delete[] this->list;
    this->maxQueueSize = otherQueue.maxQueueSize;
    this->count = otherQueue.count;
    this->list = new t *[this->maxQueueSize];
    this->queueFront = otherQueue.queueFront;
    this->queueRear = otherQueue.queueRear;
    bool end = false;
    for (int i = front; !end; i++)
    {
        if (i >= this->maxQueueSize)
            i = 0;

        this->list[i] = new t(*(otherQueue.list[i]));
        if (i == this->queueRear)
            end = true;
    }
}

template <class t>
inline arrayQueue<t>::arrayQueue(const arrayQueue<t> &otherQueue)
{
    copyQueue(otherQueue);
}

template <class t>
const arrayQueue<t> &arrayQueue<t>::operator=(const arrayQueue<t> &otherQueue)
{
    if (this != &otherQueue)
        copyQueue(otherQueue);
    return *this;
}
#endif