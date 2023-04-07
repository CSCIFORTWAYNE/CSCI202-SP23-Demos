#include "graph.h"
#include <fstream>
#include <iostream>

int main()
{
    graphType g;
    std::ofstream out("g.txt");
    g.createGraph("graph2.txt");
    out << g.printGraph() << std::endl;
    std::cout << g.depthFirstTraversal() << std::endl;
    std::cout << g.breadthFirstTraversal() << std::endl;
    std::cout << g.dftAtVertex(31) << std::endl;

    return 0;
}