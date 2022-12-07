#ifndef GAME_CONNECTFOUR_HPP
#define GAME_CONNECTFOUR_HPP

#include <iostream>

#include "../generic/grid/columnGamePlacement.hpp"
#include "../generic/game/gameStrategy.hpp"

class GameConnectFour : public GameStrategy, public ColumnGridPlacement {
    public:
        GameConnectFour();
        virtual ~GameConnectFour() = default;
        Position placeToken(const char symbol) const override;
        bool checkWin(const Position lastPlayPos) const override;
        bool canPlaceToken(const int col) const override;
};

#endif //GAME_CONNECTFOUR_HPP