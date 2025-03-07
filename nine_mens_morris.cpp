#include "nine_mens_morris.h"
#include <iostream>

using namespace std;

nine_mens_morris::nine_mens_morris() : gameBoard(), gamePhase("opening"), White('W'), Black('B') {
    currentPlayer = &White;
}


const player nine_mens_morris::get_current_player() {
    return *currentPlayer;
}

const string nine_mens_morris::get_phase() {
    return gamePhase;
}

void nine_mens_morris::set_gamePhase() {

    if(White.get_pieces_placed()==9 && Black.get_pieces_placed()==9){
            gamePhase = "moving";
    }
}

void nine_mens_morris::set_current_player(player* pl) {
    currentPlayer = pl;
}

coordinates nine_mens_morris::get_valid_coordinates(){
    while(true){
        int r, c;
        cout<<"Enter row and column: "<<endl;
        cin>>r>>c;
        try{
            coordinates coord(r,c);
            return coord;
        }catch(const std::invalid_argument& e){
            cout<<"Error: "<<e.what()<<endl;
            cout<<"Try inserting coordinates again! "<<endl;
        }
    }
}

void nine_mens_morris::start_game() {
    cout << "Starting Nine Men's Morris Game!" << endl;
    cout << "Initial board state:" << endl;
    gameBoard.display();

    while (gamePhase=="opening") {

        cout << "Current Player: " << currentPlayer->get_colour() << endl;

        flying_manager(currentPlayer);

        place(*currentPlayer);

        gameBoard.display();

        set_gamePhase();

        next_player(currentPlayer);

        cout<<"Pieces placed for white: "<<White.get_pieces_placed()<<endl;
        cout<<"Pieces placed for black: "<<Black.get_pieces_placed()<<endl;
    }

    cout<<"End of placing pieces! Let's start movement phase!"<<endl;

    while(!is_game_finished()){

        cout<<"Current player: "<<currentPlayer->get_colour()<<endl;

        gameBoard.display();

        flying_manager(currentPlayer);

        make_a_move(*currentPlayer);

        next_player(currentPlayer);

    }
    end_game();
}

int nine_mens_morris::remove_players_piece(coordinates coord) {

    if(gameBoard.is_place_empty(coord)){
        return 1;
    }
    else if(gameBoard.getPiece(coord)==currentPlayer->get_colour()){
        return 2;
    }
    else{
        if(currentPlayer->get_colour()=='W'){
            gameBoard.removePiece(coord);
            Black.take_piece();
            return 0;
        }
        else{
            gameBoard.removePiece(coord);
            White.take_piece();
            return 0;
        }
    }
    return 3;
}

void nine_mens_morris::end_game() {
    cout<<"Ending game"<<endl;
    cout<<"Player "<<who_won()<<" won!"<<endl;
}

bool nine_mens_morris::is_game_finished() {
    if(White.get_pieces()<3 || Black.get_pieces()<3){
        return true;
    }
    else{
        return false;
    }
}

const char nine_mens_morris::who_won() {
    if(White.get_pieces()<3){
        return 'B';
    }
    else{
        return 'W';
    }
}

void nine_mens_morris::make_a_move(player pl){

        cout<<"Which piece would you like to move?"<<endl;
        coordinates from=get_valid_coordinates();
        cout<<"Were do you want to move?"<<endl;
        coordinates to=get_valid_coordinates();
        while(!gameBoard.movePiece(*currentPlayer, from, to)){
            cout<<"Error: "<<endl;
            if(gameBoard.validMove(*currentPlayer, from, to)==1){
                cout<<"You can't move a piece, that is not yours! ";
                cout<<gameBoard.getPiece(from)<<endl;
            }
            else if(gameBoard.validMove(*currentPlayer, from, to)==2){
                cout<<"You can't move to that place! ";
            }
            else if(gameBoard.validMove(*currentPlayer, from, to)==3){
                cout<<"You should move up, down, right or left ";
            }
            else if(gameBoard.validMove(*currentPlayer, from, to)==4){
                cout<<"Unexpected error occurred ";
            }
            cout<<"Try inserting coordinates again!"<<endl;
            cout<<"Which piece would you like to move?"<<endl;
            from=get_valid_coordinates();
            cout<<"Were do you want to move?"<<endl;
            to=get_valid_coordinates();
        }
        check_mill(*currentPlayer, to);
}
void nine_mens_morris::check_mill(player pl, coordinates to){

    if(gameBoard.isMillFormed(to, *currentPlayer)){
            cout<<"Congratulations! You have a mill! Insert coordinates of the enemy piece you would like to remove: "<<endl;
            coordinates coord=get_valid_coordinates();
            while(remove_players_piece(coord)!=0){
                cout<<"Error: "<<endl;
                if(remove_players_piece(coord)==1){
                    cout<<"There is no piece to remove ";
                }
                else if(remove_players_piece(coord)==2){
                    cout<<"You can't remove your piece ";
                }
                cout<<"Try inserting coordinates again!"<<endl;
                coord=get_valid_coordinates();
            }
        }
}

void nine_mens_morris::place(player pl){

    cout<<"Where do you want your piece to be placed? "<<endl;
    coordinates coord = get_valid_coordinates();

    while(gameBoard.placePiece(coord, *currentPlayer)!=0){
         cout<<"Invalid move! ";
         if(gameBoard.placePiece(coord, *currentPlayer)==1){
            cout<<"You can't place a piece there! "<<endl;
         }
         else if(gameBoard.placePiece(coord, *currentPlayer)==2){
            cout<<"Unexpected error occurred! "<<endl;
         }
         cout<<"Try inserting coordinates again!"<<endl;
         coord=get_valid_coordinates();
       }

    currentPlayer->update_placed_pieces();

    check_mill(*currentPlayer, coord);
}

void nine_mens_morris::next_player(player* pl){

     if(pl->get_colour()=='W'){
        set_current_player(&Black);
       }
       else{
        set_current_player(&White);
       }
}

void nine_mens_morris::flying_manager(player* pl){

    if(pl->get_pieces()==3){
            currentPlayer->set_flying();
            cout<<"You are in the flying mode"<<endl;
        }

}

