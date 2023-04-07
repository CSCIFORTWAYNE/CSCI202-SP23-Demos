#ifndef GRAPH_H
#define GRAPH_H
#include "unorderedLinkedList.h"
#include "linkedQueue.h"
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

class graphType
{
public:
    bool isEmpty() const;
    void createGraph(std::string);
    void clearGraph();
    std::string printGraph() const;
    graphType(int size = 0);
    ~graphType();
    std::string depthFirstTraversal();
    std::string dftAtVertex(int vertex);
    std::string breadthFirstTraversal();

protected:
    int maxSize;
    int gSize;
    unorderedLinkedList<int> *graph;

private:
    void dft(int v, bool visited[], std::string &output);
};

#endif