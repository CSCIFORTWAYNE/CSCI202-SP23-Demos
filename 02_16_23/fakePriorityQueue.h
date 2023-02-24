#include "linkedQueue.h"

template <class t>
class fakePriorityQueue : public linkedQueue<t>
{
public:
    void enqueue(const t &queueElement);
};

template <class t>
void fakePriorityQueue<t>::enqueue(const t &queueElement)
{
    queueNode<t> *newNode;
    newNode = new queueNode<t>;
    newNode->data = new t(queueElement);
    newNode->link = nullptr;
    if (this->isEmptyQueue())
    {
        this->queueFront = newNode;
        this->queueRear = newNode;
    }
    else
    {
        this->queueRear->link = newNode;
        this->queueRear = newNode;
    }
}
