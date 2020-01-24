#include <iostream>
#include <cstdlib>
#include "functions.h"
using namespace std;

char intelligent(char *moves){
    int i;
    for (i = 0; moves[i] != 'F' ; ++i)
        ;
    if(moves[i-1] == 'U'){
        return 'D';
    }else if(moves[i-1] == 'D'){
        return 'U';
    }else if(moves[i-1] == 'L'){
        return 'R';
    }else if(moves[i-1] == 'R'){
        return 'L';
    }
}

bool make_decission(int (*board)[9], int *coordinates_of_empty_space, int border, char *moves, char decission) {
    int count,number_of_moves=0;
    bool res=true;
    count = move_counter(moves);
    while(count != 0) {
        cout << "Your move: ";
        cin >> decission;
        cout << "\n";
        if (decission == 'I') {
            decission = intelligent(moves);
            cout << "Intelligent move chooses " << decission << "\n";
        } if (decission == 'U' || decission == 'u') {
            res = move_up(board, coordinates_of_empty_space);
        } if (decission == 'D' || decission == 'd') {
            res = move_down(board, coordinates_of_empty_space, border);
        } if (decission == 'R' || decission == 'r') {
            res = move_right(board, coordinates_of_empty_space, border);
        } if (decission == 'L' || decission == 'l') {
            res = move_left(board, coordinates_of_empty_space);
        } if (decission == 'S' || decission == 's') {
            return false;                                               /*quiting from the function by returning false
                                                                        then reconstruct a new board outside of the
                                                                        function*/
        } if(decission == 'Q' || decission == 'q'){
            return true;
        }

        if (!res) {                                                  /*If user cant move that direction, write a command on the terminal*/
            cout << "You can't move that way" << "\n";
        } else{
            if ((decission == 'L' && moves[count - 1] == 'R') ||
                (decission == 'R' && moves[count - 1] == 'L')) {
                moves[count] = '\000';                                  /*Null char*/
                moves[count - 1] = 'F';
                count--;

            } else if ((decission == 'U' && moves[count - 1] == 'D') ||
                       (decission == 'D' && moves[count - 1] == 'U')) {
                moves[count] = '\000';                                  /*Null char*/
                moves[count - 1] = 'F';
                count--;
            }else{
                moves[count] = decission;
                moves[count+1] = 'F';
                count++;
            }
        }
        number_of_moves++;
        print_2d_array(board,border);
    }
    cout << "Problem Solved!!!" << "\n"
         << "Total Number Of Moves = " << number_of_moves;
    return true;
}

void print_2d_array(int (*board)[9], int border) {

    for(int i = 0;i< border;++i ){
        for (int j = 0; j < border ; ++j) {
            if(board[i][j] != 0)cout << board[i][j];
            else{cout << " ";}
            if(board[i][j]/10 == 0)cout << "   ";
            else{cout << "  ";}
        }
        cout << "\n";
    }
}

void init_moves(char *moves, int (*board)[9], int border, int *coordinates_of_empty_space) {
    char possibl[4] = {'U','D','L','R'},decission;
    int i,rand;
    bool res;
    rand = random_number(border * border * border);                      /*How much time does it have to be mixed*/
    for (i = 0; i < rand ; ++i) {
        decission = possibl[random_number(4)];
        if(i==0) {
            if (decission == 'U') {
                res = move_up(board, coordinates_of_empty_space);
            } else if (decission == 'D') {
                res = move_down(board, coordinates_of_empty_space, border);
            } else if (decission == 'R') {
                res = move_right(board, coordinates_of_empty_space, border);
            } else if (decission == 'L') {
                res = move_left(board, coordinates_of_empty_space);
            }else{
                res = false;
            }
        }else{
            if (decission == 'U' && moves[i-1] != 'D') {
                res = move_up(board, coordinates_of_empty_space);
            } else if (decission == 'D' && moves[i-1] != 'U') {
                res = move_down(board, coordinates_of_empty_space, border);
            } else if (decission == 'R' && moves[i-1] != 'L') {
                res = move_right(board, coordinates_of_empty_space, border);
            } else if (decission == 'L' && moves[i-1] != 'R') {
                res = move_left(board, coordinates_of_empty_space);
            }else{
                res = false;
            }
        }

        if(!res){                       /*If user cant move that direction, write a command on the terminal*/
            i--;
        }else{
            moves[i] = decission;
            moves[i+1] = 'F';
        }
    }
}

bool move_left(int (*board)[9], int *coordinates_of_empty_space) {
    int y = coordinates_of_empty_space[0],x = coordinates_of_empty_space[1];
    if (y > 0) {
        board[x][y] = board[x][y - 1];
        board[x][y - 1] = 0;
        coordinates_of_empty_space[0] = coordinates_of_empty_space[0] - 1;  /*revised coordinates of empty space*/

        return true;
    }
    return false;
}

bool move_right(int (*board)[9], int *coordinates_of_empty_space, int border) {
    int y = coordinates_of_empty_space[0],x = coordinates_of_empty_space[1];
    if (y < border - 1) {
        board[x][y] = board[x][y + 1];
        board[x][y + 1] = 0;
        coordinates_of_empty_space[0] = coordinates_of_empty_space[0] + 1; /*revised coordinates of empty space*/
        return true;
    }
    return false;
}

bool move_down(int (*board)[9], int *coordinates_of_empty_space, int border) {
    int y = coordinates_of_empty_space[0],x = coordinates_of_empty_space[1];
    if (x < border - 1) {
        board[x][y] = board[x + 1][y];             /*değiştirmek istediğimiz numara*/
        board[x + 1][y] = 0;
        coordinates_of_empty_space[1] = coordinates_of_empty_space[1] + 1; /*revised coordinates of empty space*/
        return true;
    }
    return false;
}

bool move_up(int (*board)[9], int *coordinates_of_empty_space) {
    int y = coordinates_of_empty_space[0],x = coordinates_of_empty_space[1];
    if (x > 0) {
        board[x][y] = board[x - 1][y];             /*değiştirmek istediğimiz numara*/
        board[x - 1][y] = 0;
        coordinates_of_empty_space[1] = coordinates_of_empty_space[1] - 1; /*revised coordinates of empty space*/
        return true;
    }
    return false;
}

void init_default_board(int (*board)[9], int border, int *coordinates_of_empty_space) {
    int counter = 1;
    for (int i = 0; i < border; ++i) {
        for (int j = 0; j < border; ++j) {
            if(counter != border * border)board[i][j] = counter;
            else{board[border-1][border-1] = 0;}
            counter++;
        }
    }
    coordinates_of_empty_space[0] = border-1;
    coordinates_of_empty_space[1] = border-1;
}

int move_counter(char moves[100]) {                     /*how much time does empty space moved*/
    int i=0;
    while(moves[i] != 'F'){
        i++;
    }
    return i;
}

int random_number(int total_number) {                   /*function for pick a random number from given number*/
    int random_number = rand() % total_number;
    return random_number;
}