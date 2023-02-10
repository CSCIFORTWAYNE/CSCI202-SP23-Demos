#include "arrayStack.h"
#include "linkedStack.h"
#include "laptop.h"
#include <iostream>
#include <cstdlib>

int main()
{
    arrayStack<int> as(10);
    linkedStack<int> ls(10);

    int x = rand() % 16;
    as.push(x);
    ls.push(x);

    x = rand() % 16;
    as.push(x);
    ls.push(x);

    arrayStack<int> as1(as);

    std::cout << as.pop() << std::endl;
    std::cout << ls.pop() << std::endl;

    try
    {
        laptop l("Dell", "Something", "abcd1234", 1972);
    }
    catch (stackTrace e)
    {
        e.push("main.cpp 27");
        std::cout << e.printTrace() << std::endl;
    }

    return 0;
}