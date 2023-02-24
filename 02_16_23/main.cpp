#include "arrayQueue.h"
#include "linkedQueue.h"
#include "fakePriorityQueue.h"
#include <iostream>
#include <iomanip>

int main()
{
    arrayQueue<int> aq;
    fakePriorityQueue<int> lq;
    for (int i = 0; i < 100; i++)
    {
        aq.enqueue(i);
        lq.enqueue(i);
    }
    if (aq.isFullQueue())
        std::cout << "AQ is full." << std::endl;

    for (int i = 0; i < 100; i++)
    {
        std::cout << std::setw(5) << aq.dequeue() << std::setw(5) << lq.dequeue() << std::endl;
    }
    if (lq.isEmptyQueue())
    {
        std::cout << "LQ is empty" << std::endl;
    }
    if (aq.isEmptyQueue())
    {
        std::cout << "AQ is empty" << std::endl;
    }

    arrayQueue<char> achq;
    linkedQueue<char> lchq;

    achq.enqueue('A');
    lchq.enqueue('B');
    char x = achq.dequeue();
    char y = lchq.dequeue();
    return 0;
}