#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size) {
    this->board_size = board_size;

    this->board.resize(board_size);
    for (int i = 0; i < board_size; ++i) {
        this->board[i].resize(board_size);
    }
}

void KnightsTour::print() {
    for (int i = 0; i < this->board_size; i++) {
        for (int j = 0; j < this->board_size; j++)
            cout << setw(4) << this->board[i][j] << " ";
        cout << endl;
    }
    cout << endl << endl;
}

// Function: get_moves()
//        Desc: Get the row and column indices of all valid
//                    knight moves reachable from position row, col.
//                    An invalid move would be one that sends the
//                    knight off the edge of the board or
//                    to a position that has already been visited.
//
//        int row                 - Current row position of knight.
//        int col                 - Current column position of knight.
//        int row_moves[] - Array to store row indices
//                                            of all valid new moves reachable from
//                                            the current position row, col.
//        int col_moves[] - Array to store column indices
//                                            of all valid new moves reachable from
//                                            the current position row, col.
//        int num_moves -     Number of valid moves found. Corresponds
//                                            to the sizes of row_moves and col_moves.

void KnightsTour::get_moves(int row, int col,int row_moves[], int col_moves[], int& num_moves) {
    for(int i = 0; i < 8; i++){
        row_moves[i] = row+row_moves[i];
        col_moves[i] = col+col_moves[i];
        bool valid = false; //Valid only if all conditions are true
        if(row_moves[i] >= 0 && row_moves[i] <=4){
            if(col_moves[i] >= 0 && col_moves[i] <= 4){
                if(board[row_moves[i]][col_moves[i]] == 0){
                    num_moves++; //I didn't even use this variable whoops
                    valid = true;
                }
            }
        }
        if(!valid){ //This was easier than trying to mess with array resizing
            row_moves[i] = -1;
            col_moves[i] = -1;
        }
    }
}


// Function: move() --> Recursive
//         int row                - Current row position of knight.
//         int col                - Current column position of knight.
//         int& m                 - Current move id in tour.
//                                            Stored in board at position
//                                            row, col.
//         int& num_tours - Total number of tours found.

void KnightsTour::move(int row, int col, int& m, int& num_tours) {
    m++;
    board[row][col] = m;
    int num_moves = 0;
    int row_moves[8] = {-1,1,2,2,1,-1,-2,-2}; //These are the indices to check
    int col_moves[8] = {2,2,1,-1,-2,-2,-1,1}; //    valid moves clockwise
    if(m == board_size*board_size){
        num_tours++;
        print();
        m--;
        board[row][col] = 0;
    }
    else{
        get_moves(row,col,row_moves,col_moves,num_moves); //Check for valid moves
        int check = m; //Check if the recursive call to move() was invalid
                        //if m is equal to check after the for loop, then the recursive
                        //call to move had no valid moves
        bool valid = false; //Check if none of the moves are valid
        for(int i=0; i<8;i++){
            if(row_moves[i] != -1){
                valid = true; //at least one of the moves is valid
                move(row_moves[i],col_moves[i],m,num_tours);
            }
        }
        if(!valid || m==check){ //No valid moves
            board[row][col] = 0; //reset this board space
            m--;
        }
    }
}

int KnightsTour::generate(int row, int col) {
    int m = 0;
    int num_tours = 0;
    move(row, col, m, num_tours);

    return num_tours;
}
