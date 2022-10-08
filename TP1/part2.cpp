#include <iostream>
#include <string>

#define ADVANTAGE 50
#define WINNER 100

void printPlayerScore(int playerId, int score) {
    std::string scoreMsg = "";

    switch (score) {
        case ADVANTAGE:
            scoreMsg = "ADVANTAGE";
            break;
        case WINNER:
            scoreMsg = "WINNER";
            break;
        default:
            scoreMsg = std::to_string(score);
            break;
    }

    std::cout << "[SCORE] Joueur " << playerId << " : " << scoreMsg << std::endl;
}

void updateWinnerScore(int winnerId, int score[]) {
    int loserId = !winnerId;

    switch(score[winnerId]) {
        case 0:
        case 15: 
            score[winnerId] += 15;
            break;
        case 30: 
            score[winnerId] += 10;
            break;
        case ADVANTAGE:
            score[winnerId] = WINNER;
            break;
        case 40: 
            if(score[loserId] == ADVANTAGE)
                score[loserId] = 40;
            else if(score[loserId] == 40)
                score[winnerId] = ADVANTAGE;
            else
                score[winnerId] = WINNER;
            break;
        default:
            break;
    }
}

int main() {

    int score[] = {0, 0};
    int gameIdx = 1;

    std::cout << "> La partie de tenis commence !" << std::endl;
    printPlayerScore(1, score[0]);
    printPlayerScore(2, score[1]);

    do {
        std::cout << std::endl;
        std::cout << "===== ECHANGE " << gameIdx << "=====" << std::endl;
        std::cout << "Qui a gagné l'échange " << gameIdx << " ? \nEntrez 1 ou 2 pour le joueur 1 ou 2 :" << std::endl;

        int gameWinnerId;
        std::cin >> gameWinnerId;

        if(gameWinnerId < 1 && gameWinnerId > 2) {
            std::cout << "Numéro du joueur invalide.";
            continue;
        }

        updateWinnerScore(gameWinnerId - 1, score);
        
        std::cout << "Résultats: " << std::endl;
        printPlayerScore(1, score[0]);
        printPlayerScore(2, score[1]);
        gameIdx++;

    } while(score[0] != WINNER && score[1] != WINNER);

    return EXIT_SUCCESS;
}