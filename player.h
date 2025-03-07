#ifndef PLAYER_H
#define PLAYER_H

#include <stdexcept>

class player {
    private:
        char colour; // 'W' or 'B'
        int pieces=9;
        int flying=0;
        int pieces_placed=0;
    public:
        player(char colour);
        //constructor
        void take_piece();
        //decreases value of pieces by one
        void update_placed_pieces();
        //increases value of pieces_placed by on
        void set_flying();
        //sets flying to 1
        const int get_pieces();
        //accessor
        const int get_pieces_placed();
        //accessor
        const char get_colour();
        //accessor
        bool is_flying();
        //checks if player is in flying mode

};

#endif // PLAYER_H
