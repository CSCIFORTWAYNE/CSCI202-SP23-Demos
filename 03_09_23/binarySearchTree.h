#ifndef SEARCH_H
#define SEARCH_H
#include "binaryTree.h"
#include <stdexcept>

template <class T>
class binarySearchTree : public binaryTree<T>
{
public:
    bool search(const T &searchItem) const;
    void insert(const T &insertItem);
    void deleteNode(const T &deleteNode);
    std::string printItem(T &searchItem) const;

private:
    void deleteFromTree(binaryNode<T> *&p);
    bool search(const T &searchItem, binaryNode<T> *p) const;
    void insert(binaryNode<T> *&insertItem, binaryNode<T> *&p);
    std::ostringstream printItem(T &searchItem, binaryNode<T> *p);
};

#endif

template <class T>
bool binarySearchTree<T>::search(const T &searchItem) const
{
    return search(searchItem, root);
}

template <class T>
std::string binarySearchTree<T>::printItem(T &searchItem) const
{
    if (search(searchItem))
        return print(searchItem, this->root).str();

    return "The item does not exist in the tree.";
}

template <class T>
bool binarySearchTree<T>::search(const T &searchItem, binaryNode<T> *p) const
{
    if (p == nullptr)
        return false;
    else if (*p->data == serachItem)
        return true;
    else if (*p->data > searchItem)
        return search(searchItem, p->lTree);
    else
        return search(searchItem, p->rTree);
}

template <class T>
std::ostringstream binarySearchTree<T>::printItem(T &searchItem, binaryNode<T> *p)
{
    std::ostringstream out;
    if (p == nullptr)
    {
        out << "The item does not exist in the tree.";
    }
    else if (*p->data == searchItem)
        out << *p->data << std::endl;
    else if (*p->data > searchItem)
        return printItem(searchItem, p->lTree);
    else
        return printItem(searchItem, p->rTree);

    return out;
}
