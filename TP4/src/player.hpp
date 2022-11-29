#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    public:
        Player();
        Player(std::string name, char symbol);
        ~Player();
        inline std::string getName() const;
        inline char getSymbol() const; 
    private:
        std::string name;
        char symbol;
};

#endif // PLAYER_H