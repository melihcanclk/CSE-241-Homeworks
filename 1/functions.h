
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int random_number(int total_number_parameter);
int move_counter(char *moves);
void init_default_board(int board_parameter[9][9],
                        int border_parameter,
                        int coordinates_of_empty_space_parameter[2]);
bool move_up(int board_parameter[9][9],
             int coordinates_of_empty_space_parameter[2]);
bool move_down( int board_parameter[9][9],
                int coordinates_of_empty_space_parameter[2],
                int border);
bool move_right(int board_parameter[9][9],
                int *coordinates_of_empty_space_parameter,
                int border_parameter);
bool move_left(int board_parameter[9][9],
               int coordinates_of_empty_space_parameter[2]);
void init_moves(char *moves,
                int board_parameter[9][9],
                int border_parameter,
                int coordinates_of_empty_space_parameter[2]);
void print_2d_array(int board_parameter[9][9],
                    int border_parameter);
char intelligent(char *moves);
bool make_decission(int board_parameter[9][9],
                    int coordinates_of_empty_space_parameter[2],
                    int border_parameter,
                    char moves[100],
                    char decission_parameter);



#endif //FUNCTIONS_H
