#include <iostream>

int main() {

    std::srand(time(nullptr));

    std::cout << "Je pense à un nombre entre 0 et 1000, éssaye de le deviner !" << std::endl;
    


    int userNumber = -1; 
    int computerNumber = (std::rand() % 1000);

    int userTry = 0;

    do {
        std::cout << "Entre un nombre: ";
        std::cin >> userNumber;

        if(userNumber >= 0 && userNumber <= 1000) {
            if(userNumber > computerNumber) {
                std::cout << "Le nombre à deviner est plus petit !" << std::endl;
            } else if (userNumber < computerNumber) {
                std::cout << "Le nombre à deviner est plus grand !" << std::endl;
            } else {
                std::cout << "Bravo, le nombre à  deviner était bien " << userNumber << " !" << std::endl;
            }
            userTry++;
        } else {
            std::cout << "Ton nombre n'est pas compris entre 0 & 1000 !" << std::endl;
        }
    } while(userNumber != computerNumber);

    std::cout << "Tu a réussis en " << userTry << " essais !" << std::endl;

    return EXIT_SUCCESS;
}