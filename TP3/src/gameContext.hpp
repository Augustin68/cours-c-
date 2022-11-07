#ifndef GAME_CONTEXT_HPP
#define GAME_CONTEXT_HPP

#include <iostream>
#include <memory>

#include "gameStrategy.hpp"

class GameContext
{
private:
    std::unique_ptr<GameStrategy> strategy_;

public:
    explicit GameContext(std::unique_ptr<GameStrategy> &&strategy = {}) : strategy_(std::move(strategy))
    { }
    void set_strategy(std::unique_ptr<GameStrategy> &&strategy)
    {
        strategy_ = std::move(strategy);
    }
    void placeToken() const
    {
        if (strategy_) {
            strategy_->placeToken();
        } else {
            std::cout << "Context: Strategy isn't set\n";
        }
    }
};

#endif // GAME_CONTEXT_HPP