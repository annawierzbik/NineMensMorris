
#include "player.h"
#include <iostream>

using namespace std;

player::player(char colour) : colour(colour) {
    if (colour != 'W' && colour != 'B') {
        throw std::invalid_argument("Invalid colour. Must be 'W' or 'B'.");
    }
}

void player::take_piece() {
    pieces=pieces-1;
}

void player::update_placed_pieces(){
    pieces_placed=pieces_placed+1;
}


void player::set_flying() {
    flying=1;
}

const int player::get_pieces() {
    return pieces;
}

const int player::get_pieces_placed() {
    return pieces_placed;
}

const char player::get_colour() {
    return colour;
}

bool player::is_flying() {
    return (flying == 1);
}
