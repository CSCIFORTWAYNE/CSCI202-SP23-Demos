#include "searchSort.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void printResult(int index, int searchTerm, int comp);
int compareInt(int &, int &);

int main()
{
    srand(time(0));
    std::ifstream in("input.txt");
    int list[1000000] = {0};
    for (int i = 0; i < 1000000; i++)
    {
        in >> list[i];
    }
    int searchTerm = 5995168; // rand() % 10000000 + 1;
    int index = seqSearch(list, 1000000, searchTerm);
    if (index != -1)
        printResult(index, searchTerm, index);
    else
        printResult(index, searchTerm, 1000000);

    int list2[15] = {0,
                     1,
                     2,
                     4,
                     4,
                     5,
                     14,
                     14,
                     16,
                     18,
                     20,
                     21,
                     21,
                     24,
                     29};
    int comp = 0;

    index = binarySearch(list2, 15, 17, comp, 0, 15);
    printResult(index, 17, comp);

    // bubbleSort(list, 1000000);
    // selectionSort(list, 1000000);
    // insertionSort(list, 1000000);
    // std::cout << list[999999] << std::endl;
    // mergeSort(list, 0, 999999);
    quickSort(list, 0, 999999, compareInt);
    std::cout << list[999999] << std::endl;
    comp = 0;
    index = binarySearch(list, 1000000, searchTerm, comp, 0, 1000000);
    printResult(index, searchTerm, comp);
    return 0;
}
void printResult(int index, int searchTerm, int comp)
{
    if (index == -1)
    {
        std::cout << searchTerm << " is not in the list." << std::endl;
    }
    else
    {
        std::cout << searchTerm << " is found at " << index << std::endl;
    }
    std::cout << comp << " comparisons performed." << std::endl;
}

int compareInt(int &x, int &y)
{
    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    else
        return 0;
}
