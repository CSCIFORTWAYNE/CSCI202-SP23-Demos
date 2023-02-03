#include <iostream>
#include <iomanip>
#include <climits>
#include <cctype>
#include <algorithm>
#include "laptop.h"

void resetStream();

int main()
{
    laptop **computers;
    int numLaptops = 0;
    std::string manufacturer, model, serialNum, os;
    int year;
    char install = 'n';
    std::cout << "How many laptops? ";
    std::cin >> numLaptops;
    while (!std::cin || numLaptops < 1)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "You entered an invalid value.\nHow many laptops? ";
        std::cin >> numLaptops;
    }
    computers = new laptop *[numLaptops];
    for (int i = 0; i < numLaptops; i++)
    {
        std::cout << "Enter the laptop manufacturer: ";
        getline(std::cin >> std::ws, manufacturer);
        std::cout << "Enter the laptop model: ";
        getline(std::cin >> std::ws, model);
        std::cout << "Enter the laptop year: ";
        std::cin >> year;
        while (!std::cin || year < 1985)
        {
            if (!std::cin)
            {
                resetStream();
            }
            std::cout << "The year should be a number after 1985." << std::endl;
            std::cout << "Enter the laptop year: ";
            std::cin >> year;
        }
        std::cout << "Enter the laptop serial number: ";
        getline(std::cin >> std::ws, serialNum);
        computers[i] = new laptop(manufacturer, model, serialNum, year);
        std::cout << *computers[i];

        std::cout << "Would you like to install an operating system? ";
        std::cin >> install;
        install = tolower(install);
        while (install != 'y' && install != 'n')
        {
            std::cout << "I don't understand. Please enter y or n." << std::endl;
            std::cout << "Would you like to install an operating system? ";
            std::cin >> install;
            install = tolower(install);
        }
        if (install == 'y')
        {
            std::cout << "What operating system would you like to install? ";
            getline(std::cin >> std::ws, os);
            std::transform(os.begin(), os.end(), os.begin(), ::toupper);
            while (!StrOS.count(os))
            {
                std::cout << "That is an invalid operating System.  The available operating systems are: ";
                for (std::map<OSType, std::string>::const_iterator it = OSStr.begin();
                     it != OSStr.end(); ++it)
                {
                    std::cout << it->second << std::endl;
                }
                std::cout << "What operating system would you like to install? ";
                getline(std::cin >> std::ws, os);
                std::transform(os.begin(), os.end(), os.begin(), ::toupper);
            }
            computers[i]->changeOS(StrOS.at(os));
        }
    }

    for (int i = 0; i < numLaptops; i++)
    {
        std::cout << *computers[i];
        std::cout << std::setw(42) << std::setfill('*') << "*" << std::endl;
    }
    for (int i = 0; i < numLaptops; i++)
    {
        delete computers[i];
    }
    delete [] computers;
    // laptop l("Dell", "Latitude", "12345", 2017);
    // std::cout << l;
    // std::cout << std::setw(42) << std::setfill('*') << "*" << std::endl;
    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}
