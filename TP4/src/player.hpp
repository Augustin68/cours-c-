#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    public:
        Player();
        Player(const std::string name, const char symbol);
        ~Player();
        std::string getName() const;
        char getSymbol() const; 
    private:
        std::string name;
        char symbol;
};

inline std::string Player::getName() const {
    return this->name;
}

inline char Player::getSymbol() const {
    return this->symbol;
}

#endif // PLAYER_H