#include <iostream>
#include <sstream>
#include <algorithm>

int main()
{
    std::string inLine;
    std::stringstream outLine;

    std::cin >> inLine;

    std::transform(inLine.begin(), inLine.end(), inLine.begin(),
        [](unsigned char c) { 
            return std::tolower(c); 
        });

    for (char letter: inLine)
    {
        if (inLine.find_last_of(letter) != inLine.find_first_of(letter))
        {
            outLine << ")";
        }
        else
        {
            outLine << "(";
        }
    }

    std::cout << outLine.str();
}