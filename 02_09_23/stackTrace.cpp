#include "stackTrace.h"

stackTrace::stackTrace(std::string msg)
{
    this->msg = msg;
}

void stackTrace::push(std::string t)
{
    trace.push(t);
}

std::string stackTrace::what()
{
    return msg;
}

std::string stackTrace::printTrace()
{
    std::string out;
    linkedStack<std::string> temp;
    while (!trace.isEmptyStack())
    {
        std::string t = trace.pop();
        out += t + "\n";
        temp.push(t);
    }
    while (!temp.isEmptyStack())
    {
        trace.push(temp.pop());
    }
    return out;
}
