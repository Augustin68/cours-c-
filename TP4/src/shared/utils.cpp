#include <iostream>

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
            std::cin.ignore(256, '\n');
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