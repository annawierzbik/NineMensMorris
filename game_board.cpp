#include "game_board.h"
#include <iostream>

using namespace std;

game_board::game_board() :
    board{{
        {'X', '-', '-', 'X', '-', '-', 'X'},
        {'|', 'X', '-', 'X', '-', 'X', '|'},
        {'|', '|', 'X', 'X', 'X', '|', '|'},
        {'X', 'X', 'X', ' ', 'X', 'X', 'X'},
        {'|', '|', 'X', 'X', 'X', '|', '|'},
        {'|', 'X', '-', 'X', '-', 'X', '|'},
        {'X', '-', '-', 'X', '-', '-', 'X'}
    }} {
}

void game_board::display() {
    cout<<"  0 1 2 3 4 5 6"<<endl;
    for(int i=0; i<7; i++){
        cout<<i<<" ";
        for(int j=0; j<7; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

int game_board::placePiece(coordinates coord, player pl) {
    if(is_place_empty(coord)){
        board[coord.get_row()][coord.get_col()] = pl.get_colour();
        return 0;
    }
    else{
       return 1;
    }
    return 2;
}

bool game_board::movePiece(player pl,coordinates from, coordinates to) {
    if(validMove(pl,from,to)==0){
        removePiece(from);
        placePiece(to, pl);
        return true;
    }
    else{
        return false;
    }
}

int game_board::removePiece(coordinates coord) {
    if(is_place_empty(coord)){
        return 1;
    }
    else{
        board[coord.get_row()][coord.get_col()] = 'X';
        return 0;
    }
    return 2;
}

const char game_board::getPiece(coordinates coord) {
    char piece;
    piece = board[coord.get_row()][coord.get_col()];
    return piece;
}

bool game_board::isMillFormed(coordinates coord, player pl) {
    char piece = pl.get_colour();
    int x = coord.get_row();
    int y = coord.get_col();
    int cRight=0;
    int cLeft=0;
    int cUp=0;
    int cDown=0;
    while(y>=0 && y<7){
        if(board[x][y]==piece){
            cRight++;
            y++;
        }
        else if(board[x][y]=='-'){
            y++;
        }
        else{
            break;
        }
    }
    x = coord.get_row();
    y = coord.get_col();
    while(y>=0 && y<7){
        if(board[x][y]==piece){
            cLeft++;
            y--;
        }
        else if(board[x][y]=='-'){
            y--;
        }
        else{
            break;
        }
    }
    x = coord.get_row();
    y = coord.get_col();
    while(x>=0 && x<7){
        if(board[x][y]==piece){
            cDown++;
            x++;
        }
        else if(board[x][y]=='|'){
            x++;
        }
        else{
            break;
        }
    }
    x = coord.get_row();
    y = coord.get_col();
    while(x>=0 && x<7){
        if(board[x][y]==piece){
            cUp++;
            x--;
        }
        else if(board[x][y]=='|'){
            x--;
        }
        else{
            break;
        }
    }
    int horizontal = cRight + cLeft -1 ;
    int vertical = cUp + cDown -1 ;
    if(horizontal>=3 || vertical >= 3){
        return true;
    }
    else{
        return false;
    }
}

int game_board::validMove(player pl, coordinates from, coordinates to) {
    if(getPiece(from) != pl.get_colour()){
        return 1;
    }
    else if(!is_place_empty(to)){
        return 2;
    }
    else if(!pl.is_flying()) 
    {
        int x= from.get_row();
        int y = from.get_col();
        if(from.get_row()==to.get_row()){
            if(y<to.get_col()){
                y++;
                while(board[x][y]== '-'){
                    y++;
                }
            }
            if(y>to.get_col()){
                y--;
                while(board[x][y]== '-'){
                    y--;
                }
            }
            if(board[x][y]== 'X' && x==to.get_row() && y==to.get_col()){
                return 0;
            }
        }
        if(from.get_col()==to.get_col()){
            if(x<to.get_row()){
                x++;
                while(board[x][y]== '|'){
                    x++;
                }
            }
            if(x>to.get_row()){
                x--;
                while(board[x][y]== '|'){
                    x--;
                }
            }
            if(board[x][y]== 'X' && x==to.get_row() && y==to.get_col()){
                return 0;
            }
        }
        else{
            return 3;
        }
    }
    else if(pl.is_flying()){
        return 0;
    }
    return 4;
}

bool game_board::is_place_empty(coordinates coord) {
    if(getPiece(coord) =='X'){
        return true;
    }
    return false;
}
