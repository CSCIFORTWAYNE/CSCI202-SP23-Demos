#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>

int main()
{
    std::regex commentRegex{"//[[:blank:]]*(.*)$"};
    // add a regex that detects the first line of a block comment or a block comment that is only on a single line
    std::ifstream in("test.cpp");
    std::vector<std::string> inlineComment;
    while (!in.eof())
    {
        std::string str;
        std::getline(in >> std::ws, str);
        /* std::smatch parts;
        if (std::regex_search(str, parts, commentRegex))
        {
            std::cout << " Found Comment '" /*text*/
        /* << parts[1] << "'" << std::endl;
inlineComment.push_back(parts[1]);
}*/
        const std::sregex_iterator end;
        for (std::sregex_iterator iter{std::cbegin(str), std::cend(str), commentRegex}; iter != end; ++iter)
        {
            std::cout << " Found comment " << iter->str() << std::endl;
        }
    }

    std::cout << "Found " << inlineComment.size() << " in-line comments." << std::endl;

    return 0;
}