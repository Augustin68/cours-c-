#ifndef GAME_CONNECTFOUR_HPP
#define GAME_CONNECTFOUR_HPP

#include <iostream>

#include "../generic/grid/columnGamePlacement.hpp"
#include "../generic/game/gameStrategy.hpp"

class GameConnectFour : public GameStrategy, public ColumnGridPlacement {
    public:
        GameConnectFour();
        virtual ~GameConnectFour() = default;
        Position placeToken(char symbol) const override;
        bool checkWin(Position lastPlayPos) const override;
        bool canPlaceToken(int col) const override;
};

#endif //GAME_CONNECTFOUR_HPP