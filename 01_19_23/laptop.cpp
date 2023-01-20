#include "laptop.h"

laptop::laptop(std::string manufacturer, std::string model, std::string serialNum, int year)
{
    this->manufacturer = manufacturer;
    this->model = model;
    this->serialNum = serialNum;
    if (year < 1985)
        throw std::out_of_range("The year has to be after 1985");
    else
        this->year = year;
}

void laptop::changeOS(OSType os)
{
    this->os = os;
}