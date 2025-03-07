#ifndef NINE_MENS_MORRIS_H
#define NINE_MENS_MORRIS_H

#include "game_board.h"
#include "player.h"
#include "coordinates.h"
#include <iostream>

using namespace std;

class nine_mens_morris {
    public:
        game_board gameBoard;
        string gamePhase; //opening
        player *currentPlayer; // points to white
        player White; //'W'
        player Black; //'B'

        nine_mens_morris();
        //constructor
        const player get_current_player();
        //accessor to current player
        const string get_phase();
        //accessor to game phase
        void set_gamePhase();
        //changes game phase if all pieces are places
        void set_current_player(player* pl);
        //sets current player
        void start_game();
        //starts the game and evaluates it
        int remove_players_piece(coordinates coord);
        //returns: 0- success, 1- fail, no piece to remove, 2- fail, there is no enemy's piece to remove, 3- error
        void end_game();
        //ends game
        bool is_game_finished();
        //checks if game ended
        const char who_won();
        //returns a colour of the winner
        coordinates get_valid_coordinates();
        //function that takes coordinates from a user until they are valid, returns coordinates
        void make_a_move(player pl);
        //makes a move in movement phase
        void check_mill(player pl, coordinates to);
        //looks for a mill and manages all the steps involved
        void place(player pl);
        //move in opening phase
        void next_player(player* pl);
        //changes current player to the other one
        void flying_manager(player* pl);
        //checks if player is in flying mode
};

#endif // NINE_MENS_MORRIS_H


