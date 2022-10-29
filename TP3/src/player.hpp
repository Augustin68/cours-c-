#include <string>

class Player {
    public:
        Player();
        ~Player();
        std::string getName() const;
        std::string getSymbol() const;
    private:
        std::string name;
        char symbol;
};