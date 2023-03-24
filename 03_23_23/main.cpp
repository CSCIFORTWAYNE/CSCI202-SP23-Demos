#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "AVLTree.h"

int main()
{
    AVLTree<int> tree;
    for (int i = 0; i < 20; i++)
    {
        int x;
        x = rand() % 50 + 1;
        try
        {
            tree.insert(x);
        }
        catch (...)
        {
        }
        std::cout << tree << std::endl;
        std::cout << std::setw(50) << std::setfill('*') << "*" << std::endl;
    }
    return 0;
}