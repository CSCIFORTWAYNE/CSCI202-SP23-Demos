#ifndef LAPTOP_H
#define LAPTOP_H
#include <string>
#include <map>
#include <stdexcept>

enum OSType
{
    WIN,
    MAC,
    LIN
};
const std::map<OSType, std::string> OSStr = {{WIN, "Windows"}, {MAC, "Mac OS"}, {LIN, "Linux"}};
const std::map<std::string, OSType> StrOS = {{"WINDOWS", WIN}, {"MAC OS", MAC}, {"LINUX", LIN}};
class laptop
{
public:
    laptop(std::string manufacturer, std::string model, std::string serialNum, int year); //throws out_of_range
    void changeOS(OSType);
private:
    std::string manufacturer;
    std::string model;
    std::string serialNum;
    OSType os;
    int year;
};

#endif