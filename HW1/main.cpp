#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.h"

using namespace std;

int main() {
    int board[9][9],border=1,coordinates_of_empty_space[2];
    char moves[100],decission;
    cout << "Please enter the problem size" << "\n";
    while(border <3 || border > 10){
        cin >> border;
        if(border <3 || border > 10)cout << "Wrong size, please enter the problem size again" << "\n";
    }                                                              /*Getting value from the user*/
    cout << "Your initial random board is" << "\n";
    srand (time(NULL));
    coordinates_of_empty_space[0] = coordinates_of_empty_space[1] = border-1;   /*Initial coordinates of empty space*/
    moves[0] = 'F';
    init_default_board(board,border,coordinates_of_empty_space);
    init_moves(moves, board, border, coordinates_of_empty_space);
    print_2d_array(board,border);
    cout << "\n";
    while(make_decission(board,coordinates_of_empty_space,border,moves,decission)== false){         /*if user used "S" shuffle button, board will be reconstructed*/
        init_moves(moves, board, border, coordinates_of_empty_space);
        print_2d_array(board,border);
    };
    return 0;
}

