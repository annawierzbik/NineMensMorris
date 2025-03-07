#include "coordinates.h"
#include <iostream>
#include <stdexcept>

using namespace std;

coordinates::coordinates(int r, int c){
   if (!is_coordinate_valid(r) || !is_coordinate_valid(c)) {
        throw std::invalid_argument("Invalid coordinates");
    }
    row = r;
    col = c;
}
const int coordinates::get_row() {
    return row;
}

const int coordinates::get_col() {
    return col;
}

void coordinates::set_row(int n){
    row = n;
}

void coordinates::set_col(int n){
    col = n;
}
bool coordinates::is_coordinate_valid(int x) {
    if(x>6 || x<0){
        return false;
    }
    return true;
}

