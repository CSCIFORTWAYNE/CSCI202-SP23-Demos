#include "laptop.h"

laptop::laptop(std::string manufacturer, std::string model, std::string serialNum, int year)
{
    this->manufacturer = manufacturer;
    this->model = model;
    this->serialNum = serialNum;
    try
    {
        setYear(year);
    }
    catch (stackTrace e)
    {
        std::string t = "laptop.cpp 14 laptop::laptop(";
        t += manufacturer + ", ";
        t += model + ", ";
        t += serialNum + ", ";
        t += std::to_string(year) + ")";
        e.push(t);
        throw e;
    }
    this->os = NONE;
}

void laptop::changeOS(OSType os)
{
    this->os = os;
}

bool laptop::operator==(const laptop &ol)
{
    return this->serialNum == ol.serialNum;
}

bool laptop::operator!=(const laptop &ol)
{
    return this->serialNum != ol.serialNum;
}

void laptop::setYear(int year)
{
    if (year < 1985)
    {
        stackTrace e("The year has to be after 1985");
        e.push("laptop.cpp 34 laptop::setYear(" + std::to_string(year) + ")");
        throw e;
    }
    else
        this->year = year;
}

std::ostream &operator<<(std::ostream &o, const laptop &l)
{
    o << "Manufacturer: " << l.manufacturer << std::endl;
    o << "Model: " << l.model << std::endl;
    o << "Operating System: " << OSStr.at(l.os) << std::endl;
    o << "Year: " << l.year << std::endl;
    o << "Serial Number: " << l.serialNum << std::endl;
    return o;
}
