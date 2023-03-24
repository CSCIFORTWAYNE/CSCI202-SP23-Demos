#ifndef AVLTREE_H
#define AVLTREE_H
#include "binarySearchTree.h"
#include "linkedQueue.h"
#include <sstream>

template <class T>
class AVLTree : public binarySearchTree<T>
{
public:
    void insert(const T &insertItem);
    void deleteNode(const T &deleteItem); // complete for lecture activity
    template <class Type>
    friend std::ostream &operator<<(std::ostream &out, const AVLTree<Type> &tree);

private:
    std::string printTree() const;
    void rotateToLeft(binaryNode<T> *&root);
    void rotateToRight(binaryNode<T> *&root);
    void balanceFromLeft(binaryNode<T> *&root);
    void balanceFromRight(binaryNode<T> *&root);
    void insertIntoAVL(binaryNode<T> *&root, binaryNode<T> *newNode, bool &isTaller);
};

template <class T>
inline void AVLTree<T>::insert(const T &insertItem)
{
    bool isTaller = false;
    binaryNode<T> *newNode;
    newNode = new binaryNode<T>;
    newNode->data = new T(insertItem);
    newNode->bfactor = 0;
    newNode->lTree = nullptr;
    newNode->rTree = nullptr;

    insertIntoAVL(this->root, newNode, isTaller);
}

template <class T>
inline std::string AVLTree<T>::printTree() const
{
    std::ostringstream out;
    struct nodeDepth
    {
        binaryNode<T> *n;
        int lvl;
        // node_depth(node<T>* n_, int lvl_) : n(n_), lvl(lvl_) {}
    };
    int depth = this->treeheight();
    int last_lvl = 0;
    int offset = (1 << depth) - 1;
    linkedQueue<nodeDepth> nodes;
    nodeDepth rootDepth;
    rootDepth.n = this->root;
    rootDepth.lvl = last_lvl;
    nodes.enqueue(rootDepth);
    while (!nodes.isEmptyQueue())
    {
        nodeDepth current = nodes.front();
        if (last_lvl != current.lvl)
        {
            out << std::endl;
            last_lvl = current.lvl;
            offset = (1 << (depth - current.lvl)) - 1;
        }
        if (current.n != nullptr)
        {
            out << std::setw(offset) << " ";
            out << std::setw(3) << *current.n->data;
            out << std::setw(offset) << " ";
            nodeDepth left;
            nodeDepth right;
            left.n = current.n->lTree;
            right.n = current.n->rTree;
            left.lvl = last_lvl + 1;
            right.lvl = last_lvl + 1;
            nodes.enqueue(left);
            nodes.enqueue(right);
        }
        else
        {
            out << std::setw(offset) << " "
                << "   ";
            out << std::setw(offset) << " ";
        }
        nodes.dequeue();
    }
    out << std::endl;

    return out.str();
}

template <class T>
inline void AVLTree<T>::rotateToLeft(binaryNode<T> *&root)
{
    binaryNode<T> *p;
    if (root == nullptr)
        throw std::out_of_range("Cannot rotate empty node.");
    else if (root->rTree == nullptr)
        throw std::out_of_range("Cannot rotate empty node.");
    else
    {
        p = root->rTree;        // p is new root node made from right subtree root
        root->rTree = p->lTree; // take the right tree from the old root and move the new root left tree to it
        p->lTree = root;        // take the left tree of the new root and set it to the old root
        root = p;               // change the root to the new root
    }
}

template <class T>
inline void AVLTree<T>::rotateToRight(binaryNode<T> *&root)
{
    binaryNode<T> *p; // new root
    if (root == nullptr)
        throw std::out_of_range("Cannot rotate empty node.");
    else if (root->lTree == nullptr)
        throw std::out_of_range("Cannot rotate empty node.");
    else
    {
        p = root->lTree;
        root->lTree = p->rTree;
        p->rTree = root;
        root = p;
    }
}

template <class T>
inline void AVLTree<T>::balanceFromLeft(binaryNode<T> *&root)
{
    binaryNode<T> *p;
    binaryNode<T> *w;
    p = root->lTree;
    switch (p->bfactor)
    {
    case -1:
        root->bfactor = 1;
        p->bfactor = 0;
        rotateToRight(root);
        break;
    case 0:
        throw std::runtime_error("Left subtree is balanced.");
    case 1:
        w = p->rTree;
        switch (w->bfactor)
        {
        case -1:
            root->bfactor = 1;
            p->bfactor = 0;
            break;
        case 0:
            root->bfactor = 0;
            p->bfactor = 0;
            break;
        case 1:
            root->bfactor = 0;
            p->bfactor = -1;
        }
        w->bfactor = 0;
        rotateToLeft(p);
        root->lTree = p;
        rotateToRight(root);
    }
}

template <class T>
inline void AVLTree<T>::balanceFromRight(binaryNode<T> *&root)
{
    binaryNode<T> *p;
    binaryNode<T> *w;
    p = root->rTree;
    switch (p->bfactor)
    {
    case 1:
        root->bfactor = 0;
        p->bfactor = 0;
        rotateToLeft(root);
        break;
    case 0:
        throw std::runtime_error("Right subtree is balanced.");
    case -1:
        w = p->lTree;
        switch (w->bfactor)
        {
        case -1:
            root->bfactor = 0;
            p->bfactor = 1;
            break;
        case 0:
            root->bfactor = 0;
            p->bfactor = 0;
            break;
        case 1:
            root->bfactor = -1;
            p->bfactor = 0;
        }
        w->bfactor = 0;
        rotateToRight(p);
        root->rTree = p;
        rotateToLeft(root);
    }
}

template <class T>
inline void AVLTree<T>::insertIntoAVL(binaryNode<T> *&root, binaryNode<T> *newNode, bool &isTaller)
{
    if (root == nullptr)
    {
        root = newNode;
        isTaller = true;
    }
    else if (*root->data == *newNode->data)
        throw std::invalid_argument("No duplicates allowed.");
    else if (*newNode->data < *root->data)
    {
        insertIntoAVL(root->lTree, newNode, isTaller);
        if (isTaller)
        {
            switch (root->bfactor)
            {
            case -1:
                balanceFromLeft(root);
                isTaller = false;
                break;
            case 0:
                root->bfactor = -1;
                isTaller = true;
                break;
            case 1:
                root->bfactor = 0;
                isTaller = false;
            }
        }
    }
    else
    {
        insertIntoAVL(root->rTree, newNode, isTaller);
        if (isTaller)
        {
            switch (root->bfactor)
            {
            case -1:
                root->bfactor = 0;
                isTaller = false;
                break;
            case 0:
                root->bfactor = 1;
                isTaller = true;
                break;
            case 1:
                balanceFromRight(root);
                isTaller = false;
            }
        }
    }
}

template <class Type>
inline std::ostream &operator<<(std::ostream &out, const AVLTree<Type> &tree)
{
    out << tree.printTree();
    return out;
}

#endif
