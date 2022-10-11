#include <iostream>

int main() {
    int min = 0;
    int max = 1000;
    std::cout << "Pense à un nombre entre " << min << " et " << max << ". Je vais essayer de le deviner." << std::endl;

    bool isGuessGood = false;
    int answer = 0;
    int tries = 0;

    int guessMin = min;
    int guessMax = max;
    do {
        int guess = (guessMax - guessMin) / 2 + guessMin;
        std::cout << "Je pense que ton nombre est " << guess << "." << std::endl;
        int userAnswer = 0;
        do {
            std::cout << "Est-ce que ton nombre est:\n1: Plus grand\n2: Plus petit\n3: Le nombre " << guess << std::endl;
            std::cin >> userAnswer;
        } while (userAnswer != 1 && userAnswer != 2 && userAnswer != 3);
        if(userAnswer == 1) {
            guessMin = guess;
        } else if (userAnswer == 2) {
            guessMax = guess;
        } else if (userAnswer == 3) {
            isGuessGood = true;
            answer = guess;
        }
        tries++;
    } while(!isGuessGood);

    std::cout << "Ton nombre était donc " << answer << " !" << std::endl;
    std::cout << "J'ai trouvé en " << tries << " essais !" << std::endl;
    
    return EXIT_SUCCESS;
}