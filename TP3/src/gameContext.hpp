#ifndef GAME_CONTEXT_HPP
#define GAME_CONTEXT_HPP

#include <iostream>
#include <memory>

#include "gameStrategy.hpp"

class GameContext
{
    /**
     * @var Strategy The Context maintains a reference to one of the Strategy
     * objects. The Context does not know the concrete class of a strategy. It
     * should work with all strategies via the Strategy interface.
     */
private:
    std::unique_ptr<GameStrategy> strategy_;
    /**
     * Usually, the Context accepts a strategy through the constructor, but also
     * provides a setter to change it at runtime.
     */
public:
    explicit GameContext(std::unique_ptr<GameStrategy> &&strategy = {}) : strategy_(std::move(strategy))
    {
    }
    /**
     * Usually, the Context allows replacing a Strategy object at runtime.
     */
    void set_strategy(std::unique_ptr<GameStrategy> &&strategy)
    {
        strategy_ = std::move(strategy);
    }
    /**
     * The Context delegates some work to the Strategy object instead of
     * implementing +multiple versions of the algorithm on its own.
     */
    void doSomeBusinessLogic() const
    {
        if (strategy_) {
            std::cout << "Context: Placing token (not sure how it'll do it)\n";
            strategy_->placeToken();
            // std::string result = strategy_->placeToken();
            // std::cout << result << "\n";
        } else {
            std::cout << "Context: Strategy isn't set\n";
        }
    }
};

#endif // GAME_CONTEXT_HPP