#ifndef GAME_CONTEXT_HPP
#define GAME_CONTEXT_HPP

#include <iostream>
#include <memory>

#include "gameStrategy.hpp"

class GameContext
{
public:
    GameContext(std::unique_ptr<GameStrategy> &&strategy = {}) : strategy_(std::move(strategy))
    { }
    ~GameContext() { };
    void set_strategy(std::unique_ptr<GameStrategy> &&strategy)
    {
        strategy_ = std::move(strategy);
    }
    Position placeToken(const char token) const {
        if (strategy_) {
            return strategy_->placeToken(token);
        } else {
            std::cout << "Context: Strategy isn't set\n";
        }
        return Position();
    }
    bool checkWin(const Position lastPlayedPosition) const {
        if (strategy_) {
            return strategy_->checkWin(lastPlayedPosition);
        } else {
            std::cout << "Context: Strategy isn't set\n";
        }
        return false;
    }
    bool isMaxRoundReached(const int roundCount) const {
        if (strategy_) {
            return strategy_->isMaxRoundReached(roundCount);
        } else {
            std::cout << "Context: Strategy isn't set\n";
        }
        return false;
    }
private:
    std::unique_ptr<GameStrategy> strategy_;

};

#endif // GAME_CONTEXT_HPP