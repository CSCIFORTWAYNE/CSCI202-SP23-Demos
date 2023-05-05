#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::regex dateRegex{"(\\d{4})(/|-)(0?[1-9]|1[0-2])\\2([1-2][0-9]|3[0-1]|0?[1-9])\\b"};
    while (true)
    {
        std::string str;
        std::cout << "Enter a date (year/month/day) (q=quit): ";
        if (!std::getline(std::cin >> std::ws, str) || str == "q")
        {
            break;
        }
        std::smatch parts;
        if (std::regex_match(str, parts, dateRegex))
        {
            int year = std::stoi(parts[1]);
            int month = std::stoi(parts[3]);
            int day = std::stoi(parts[4]);
            bool leap = false;
            if (year % 4 == 0)
                if (year % 100 == 0)
                    if (year % 400 == 0)
                        leap = true;
                    else
                        leap = false;
                else
                    leap = true;
            else
                leap = false;
            if (month == 2 && day > 28)
            {
                if ((leap && day > 29) || !leap)
                    std::cout << " Invalid date!" << std::endl;
                else if (leap)
                    std::cout << "Valid date: Year=" << year << ", month=" << month << ", day=" << day << std::endl;
            }
            else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
                std::cout << " Invalid date!" << std::endl;
            else
                std::cout << "Valid date: Year=" << year << ", month=" << month << ", day=" << day << std::endl;
        }
        else
        {
            std::cout << " Invalid date!" << std::endl;
        }
    }

    return 0;
}