#ifndef SEARCH_H
#define SEARCH_H
#include <iostream>
#include "unorderedLinkedList.h"

/*********SEARCH ALGORITHMS**********/
template <class elemType>
int seqSearch(const elemType list[], int length, const elemType &item)
{
    int loc;
    bool found = false;
    for (loc = 0; loc < length && !found; loc++)
    {
        if (list[loc] == item)
        {
            found = true;
        }
    }
    if (found)
    {
        return loc;
    }
    else
    {
        return -1;
    }
}
template <class elemType>
int binarySearch(const elemType list[], int length, const elemType &item, int &comp, int first, int last)
{
    if (last < first)
        return -1;
    int mid;
    // bool found = false;
    // comp = 0;
    mid = (first + last) / 2;
    if (list[mid] == item)
    {
        comp++;
        return mid;
    }
    else if (list[mid] > item)
    {
        comp++;
        return binarySearch(list, length, item, comp, first, mid - 1);
    }
    else if (list[mid] < item)
    {
        comp++;
        return binarySearch(list, length, item, comp, mid + 1, last);
    }
    return -1;
}

/*********SORT ALGORITHMS**********/
template <class elemType>
void bubbleSort(elemType list[], int length)
{
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration; index++)
        {
            if (list[index] > list[index + 1])
            {
                elemType temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }
}

template <class elemType>
int findLargest(elemType list[], int length)
{
    int largest = 0;
    for (int i = 1; i < length; i++)
    {
        if (list[i] > list[largest])
        {
            largest = i;
        }
    }
    return largest;
}

template <class elemType>
void swap(elemType list[], int first, int second)
{
    elemType temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

template <class elemType>
void selectionSort(elemType list[], int length)
{
    int largest;
    for (int i = 0; i < length; i++)
    {
        largest = findLargest(list, length - i);
        swap(list, length - i, largest);
    }
}

template <class elemType>
void insertionSort(elemType list[], int length)
{
    for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
    {
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            elemType temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;
            do
            {
                list[location] = list[location - 1];
                location--;
            } while (location > 0 && list[location - 1] > temp);
            list[location] = temp;
        }
    }
}

template <class elemType>
int partition(elemType list[], int low, int high, int (*func)(elemType &, elemType &))
{
    elemType pivot = list[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        elemType item = list[j];
        if (func(item, pivot) < 0)
        {
            i++;
            swap(list, i, j);
        }
    }
    i++;
    swap(list, i, high);
    return i;
}

template <class elemType>
void quickSort(elemType list[], int low, int high, int (*func)(elemType &, elemType &))
{
    if (low < high)
    {
        int pi = partition(list, low, high, func);
        quickSort(list, low, pi - 1, func);
        quickSort(list, pi + 1, high, func);
    }
}

template <class elemType>
void merge(elemType array[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    elemType *leftArray = new elemType[leftSize];
    elemType *rightArray = new elemType[rightSize];
    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        rightArray[i] = array[mid + 1 + i];
    }
    int leftIndex = 0, rightIndex = 0, mergeIndex = left;
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftArray[leftIndex] <= rightArray[rightIndex])
        {
            array[mergeIndex] = leftArray[leftIndex];
            leftIndex++;
        }
        else
        {
            array[mergeIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }
    while (leftIndex < leftSize)
    {
        array[mergeIndex++] = leftArray[leftIndex++];
    }
    while (rightIndex < rightSize)
    {
        array[mergeIndex++] = rightArray[rightIndex++];
    }
    delete[] leftArray;
    delete[] rightArray;
}

template <class elemType>
void mergeSort(elemType array[], int begin, int end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

#endif