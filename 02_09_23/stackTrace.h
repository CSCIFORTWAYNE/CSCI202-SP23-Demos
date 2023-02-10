#ifndef STACKT_H
#define STACKT_H
#include "linkedStack.h"
#include <string>

class stackTrace
{
public:
    stackTrace(std::string);
    void push(std::string);
    std::string what();
    std::string printTrace();

private:
    linkedStack<std::string> trace;
    std::string msg;
};

#endif