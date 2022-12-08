#include "utils.hpp"

int readInt()
{

    int input;
    bool valid = false;

    do
    {
        std::cin >> input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Veuillez saisir un chiffre valide : ";
        }
        else
        {
            valid = true;
        }
    } while (!valid);

    std::cout << std::endl;
    return input;
}

bool parsePositionInput(std::string input, Position& pos){
    int commaPos = input.find(",");
    if(commaPos == std::string::npos){
        // No comma found in input
        return false;
    }

    std::string lineStr = input.substr(0, commaPos);
    std::string columnStr = input.substr(commaPos + 1);

    try{
        pos.line = std::stoi(lineStr);
        pos.column = std::stoi(columnStr);
    } catch(std::invalid_argument&){
        // Invalid integer format
        return false;
    }

    return true;
}