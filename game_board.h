#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "coordinates.h"
#include "player.h"

#include <array>
#include <cstddef>

using namespace std;

class game_board {

    public:
        static const size_t rows = 7;
        static const size_t cols = 7;
        game_board();
        //constructor
        void display();
        //displays a board
        int placePiece(coordinates coord, player pl);
        // Places a piece on a board, returns: 0- success, 1- fail, place is not empty, 2- error occured
        bool movePiece(player pl, coordinates from, coordinates to);
        //moves a piece on a board
        int removePiece(coordinates coord);
        // Removes piece from a board ,returns: 0- success, 1- fail, place is empty, 2- error
        const char getPiece(coordinates coord);
        //accessor
        bool isMillFormed(coordinates coord, player pl);
        //looks for a mill
        int validMove(player pl, coordinates from, coordinates to);
        //Checks if move is valid, returns: 0- success, 1- fail, this piece doesnt belong to the player, 2- fail, cant move to that place,
        // 3- invalid move for not flying player
        //4- error
        bool is_place_empty(coordinates coord);
        //Checks if place is empty ( value 'X' )

    private:
    array<array<char, cols>, rows> board;
};

#endif // GAME_BOARD_H

