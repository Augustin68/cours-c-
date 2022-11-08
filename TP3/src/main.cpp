#include <iostream>
#include <string>
#include <vector>


#include "player.hpp"
#include "game.hpp"

void displayVector(std::vector<int> vec){
    std::cout << "==========" << std::endl;
    for(int i = 0; i<(int)vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    }
    std::cout << "==========" << std::endl;
}

void displayVector2D(std::vector<std::vector<int>> vec) {
    std::cout << "==========" << std::endl;
    for(int i = 0; i < (int)vec.size(); i++) {
        for(int j = 0; j < (int)vec[i].size(); j++) {
            std::cout << vec[i][j] << " |";
        }
        std::cout << std::endl;
    }
    std::cout << "==========" << std::endl;
}

int main() {
    std::cout << "Coucou tick tack" << std::endl;

    // The 2 last arguments is unused for the moment !
    Game* game = new Game();
    game->startParty();
    
    delete game;

    // std::vector<int> v1;

    // v1.push_back(5);
    // v1.push_back(4);
    // v1.push_back(3);
    // v1.push_back(2);
    // v1.push_back(1);

    // displayVector(v1);

    // displayVector(v1);

    // std::vector<std::vector<int>> v2;

    // v2 = std::vector<std::vector<int>>(4, std::vector<int>(5, 0));
    
    // // for(int i = 0; i < 4; i++) {
    // //     for(int j = 0; j < 5; j++) {
    // //         v2[i][j] = i*j;
    // //     }
    // // }

    // displayVector2D(v2);

    // std::vector<std::vector<int>> vect
    // {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9, 10, 11}
    // };
    // displayVector2D(vect);

    
    return 0;
}