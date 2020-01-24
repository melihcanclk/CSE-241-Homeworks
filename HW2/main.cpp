#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

void convertIntToString(string & word, int (&board)[9][9], int xBorder,int yBorder);
bool isAllEqual(int wp[4]);
char reverse(char input);
char moveRandom(int arr[][9],int xBorder,int yBorder,int number);
void findWhereIMustBe(int (*arr)[9], int xBorder, int yBorder,int number,int &xMustBe,int &yMustBe);
void resetBoard(int arr[],int size);
bool move_left(int (*board)[9], int *coordinates_of_empty_space);
bool move_right(int (*board)[9], int *coordinates_of_empty_space);
bool move_down(int (*board)[9], int *coordinates_of_empty_space);
bool move_up(int (*board)[9], int *coordinates_of_empty_space);
bool make_decission(int arr[][9],int coordinates_of_empty_box[],int xBorder,int yBorder,char decission);
int selectMin(int arr[]);
char intelligent(int (*arr)[9], int *coordinates_of_empty_box, int xBorder,int yBorder);
bool isMovable(int coordinates_of_empty_box[],char decission,int xBorder,int yBorder);
void print_2d_array(int arr[][9], int border);

void fill_2d_arr(int arr[][9],int border);
int isSolvableForEven(int puzzle[][9],int border);
int isSolvableForOdd(int puzzle[][9],int border);
int getInvCount(int arr[][9],int border);
int find_number(int arr[][9],int xBorder,int yBorder,int number);
void convertArray2DTo1D(const int arr[][9],int converted1DArray[],int border);
int find_number(int arr[][9],int xBorder,int yBorder ,int number,int &x,int &y);
int choose_one_number(int total_number);
void fill_numbers(int * numbers, int total_number);
void firstHomeworkPart();
void convertStringToInt(string word,int row,int (&board)[9][9],int j);
int removeDuplWord(string str,int (&board)[9][9],int row);
void secondHomeworkPart(char *argv);




int main(int argc,char * argv[]) {

    secondHomeworkPart(argv[1]);
    return 0;
}

void firstHomeworkPart() {

    int board[9][9],border,coordinates_of_empty_box[2],result;
    char decission='i',prevMove;

    cout << "Please Enter Size Of N-Puzzle Board:";
    cin >> border;
    fill_2d_arr(board,border);
    print_2d_array(board,border);
    result = find_number(board,border,border,0);
    if(result % border == 0 )coordinates_of_empty_box[0] = border-1 ;            /*x koordinatı*/
    else{coordinates_of_empty_box[0] = (result % border)-1;}
    coordinates_of_empty_box[1] = (result / border) ;             /*y koordinatı*/
    while(true){
        cout << "Please select which direction you want to go:" << "\n";
        cout << "U,u->Moves up." << "\n";
        cout << "D,d->Moves down" << "\n";
        cout << "L,l->Moves left" << "\n";
        cout << "R,r->Moves right" << "\n";
        cout << "I,i->Moves intelligent" << "\n";
        cout << "S,s->Shuffle board and create new board with same size" << "\n";
        cout << "Q,q->Quit to main menu" << "\n";
        cout << "Selection:";
        cin >> decission;
        cout << "\n";
        if(decission == 'I' || decission == 'i' ){
            decission = intelligent(board,coordinates_of_empty_box,border,border);
            if(reverse(prevMove) == decission){
                decission = moveRandom(board,border,border,0);
            }
        }else if(decission == 'S' || decission == 's'){
            fill_2d_arr(board,border);
        }else if(decission == 'Q' || decission == 'q'){
            return;
        }
        make_decission(board, coordinates_of_empty_box, border, border,decission);
        print_2d_array(board,border);
        prevMove = decission;
    }
}


void secondHomeworkPart(char * filename) {

    srand (time(NULL));
    int lineNumber=0,i=0,board[9][9],coordinateOfbb[2],numberAtOneLine,counter=0;
    const int MAX_TRY = 2000000;
    char decission,prevMove;
    string line[9];
    ifstream infile;
    infile.open(filename);
    if(!infile){
        cout << "File couldn't be read" << "\n";
        firstHomeworkPart();
    }
    while (getline(infile, line[lineNumber])) {
        cout << line[lineNumber] << "\n";
        lineNumber++;
    }
    while (i < lineNumber) {
        numberAtOneLine = removeDuplWord(line[i], board, i);
        i++;
    }
    find_number(board, numberAtOneLine + 1, lineNumber, -1, coordinateOfbb[0], coordinateOfbb[1]);
    while(1) {
        cout << "Please select one of the selection below:" << "\n";
        cout << "U,u->Moves up." << "\n";
        cout << "D,d->Moves down" << "\n";
        cout << "L,l->Moves left" << "\n";
        cout << "R,r->Moves right"<< "\n";
        cout << "I,i->Moves intelligent" << "\n";
        cout << "V,v->Solve the problem from the current configuration\n"
                "using the new intelligent algorithm." << "\n";
        cout << "E,e->Asks a file name and saves the current board \n"
                "configuration as a loadable shape file.." << "\n";
        cout << "T,t->Prints a report about how many moves have been "
                "done and if the solution is found" << "\n";
        cout << "Y,y->Asks a file name and loads the current board "
                "configuration from the shape file." << "\n";
        cout << "Q,q->Quit from the game" << "\n";
        cout << "Selection:";
        cin >> decission;
        if (decission == 'I' || decission == 'i') {
            decission = intelligent(board, coordinateOfbb, numberAtOneLine, lineNumber - 1);
            if (reverse(prevMove) == decission) {
                decission = moveRandom(board, numberAtOneLine, lineNumber, -1);
            }
            make_decission(board, coordinateOfbb, numberAtOneLine + 1, lineNumber, decission);
            for (int j = 0; j < lineNumber; ++j) {
                convertIntToString(line[j], board, numberAtOneLine + 1, j);
                cout << line[j] << "\n";
            }

        } else if (decission == 'V' || decission == 'v') {
            while (counter < MAX_TRY) {
                decission = intelligent(board, coordinateOfbb, numberAtOneLine, lineNumber - 1);
                if (reverse(prevMove) == decission) {
                    decission = moveRandom(board, numberAtOneLine+1, lineNumber, -1);
                }
                make_decission(board, coordinateOfbb, numberAtOneLine +1, lineNumber, decission);
                for (int j = 0; j < lineNumber; ++j) {
                    convertIntToString(line[j], board, numberAtOneLine + 1, j);
                    cout << line[j] << "\n";
                }
                cout << "-------------------------------------" << "\n";
                prevMove = decission;
                if (decission == 'Q') {
                    cout << "Solution is found. Move Count = " << counter << "\n";
                    counter=0;
                    break;
                }
                counter++;
                cout << "Intelligence choose : "<< decission << "\n";
            }
            if(counter == MAX_TRY)cout << "Solution is not found. It might work if re-open"
                                          "file. Move Count = " << counter << "\n";
            else if(counter > MAX_TRY)cout << "Solution is not found. Please reopen file" << "\n";
        }else if(decission == 'E' || decission == 'e'){
            cout << "Please enter name of .txt file that you want to save with .txt extension:";
            cin >> filename;
            cout << "\n" ;
            ofstream outfile;
            outfile.open (filename);
            if(!outfile){
                cout << "File couldn't be written" << "\n";
            }
            for (int j = 0; j < lineNumber; ++j) {
                outfile << line[j];
                outfile << "\n";
            }
        }else if(decission == 'T' || decission == 't' ){
            if(counter != 1) {
                cout << "Solution is not found yet. Move count = " << counter << "\n";
            }else{
                cout << "Solution is already found." << "\n";
            }
            counter--;
        }else if(decission == 'Y' || decission == 'y'){
            cout << "Please enter name of the text file that you want to load:";
            cin >> filename;
            cout << "\n";
            secondHomeworkPart(filename);
        }else if(decission == 'Q' || decission == 'q'){
            return;
        }
        else {
            make_decission(board, coordinateOfbb, numberAtOneLine + 1, lineNumber, decission);
            for (int j = 0; j < lineNumber; ++j) {
                convertIntToString(line[j], board, numberAtOneLine + 1, j);
                cout << line[j] << "\n";
            }
            prevMove = decission;
        }
        counter++;
    }
    return;
}



void resetBoard(int arr[] , int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = -1;
    }
}


void fill_numbers(int *numbers, int total_number) {     /*random numara seçmek için kullanılacak arrayi 0'dan
                                                          kenar sayısının karesinden 1 eksik kadar dolduruyorum*/
    for (int i = 0; i < total_number; ++i) {
        numbers[i] = i;
    }
}

int choose_one_number(int total_number) {
    int random_number = rand() % total_number;
    return random_number;
}

int find_number(int (*arr)[9], int xBorder,int yBorder, int number, int &x, int &y) {                             /*boşluğun nerede olduğunu bulur*/
    for (int i = 0; i < yBorder; ++i) {
        for (int j = 0; j < xBorder; ++j) {
            if (arr[i][j] == number){
                y=i;
                x=j;
                return number;
            }
        }
    }

}

void convertArray2DTo1D(const int (*arr)[9], int *converted1DArray, int border) {
    int index =0;
    for (int i = 0; i < border ; ++i) {
        for (int j = 0; j < border; ++j) {
            converted1DArray[index] = arr[i][j];
            index++;
        }
    }
}

int find_number(int (*arr)[9], int xBorder,int yBorder, int number) {                             /*boşluğun nerede olduğunu bulur*/
    int counter=1;
    for (int i = 0; i < yBorder; ++i) {
        for (int j = 0; j < xBorder; ++j) {
            if (arr[i][j] == number){
                return counter;
            }
            counter++;
        }
    }

}

int getInvCount(int (*arr)[9], int border) {
    int oneDimConvertedArray[81];
    convertArray2DTo1D(arr,oneDimConvertedArray,border);
    int inv_count = 0;
    for (int i = 0; i < border * border - 1; i++)
        for (int j = i+1; j < border * border ; j++)
            if (oneDimConvertedArray[j] && oneDimConvertedArray[i] &&  oneDimConvertedArray[i] > oneDimConvertedArray[j])
                inv_count++;
    return inv_count;

}

int isSolvableForOdd(int (*puzzle)[9], int border) {
    // Count inversions in given puzzle
    int invCount = getInvCount(puzzle,border);

    // return true if inversion count is even.
    return (invCount%2 == 0);
}

int isSolvableForEven(int (*puzzle)[9], int border) {
    int result = find_number(puzzle,border,border,0),y;
    y = (result / border) ;
    getInvCount(puzzle, border);

    if((((border - y ) %2 == 0) && getInvCount(puzzle,border)%2 == 1) || (((border - y) %2 == 1) && getInvCount(puzzle,border)%2 == 0) ){
        return 1;
    }
    return 0;
}

void fill_2d_arr(int (*arr)[9], int border) {
    const int MAX_NUMBERS = border * border;
    int numbers[MAX_NUMBERS],square,chosen_number,temp,index,flag=1;       /*random numara seçmek için kullanılacak array*/
    fill_numbers(numbers,border * border);
    square=border* border;
    while(flag) {/*çözülebilir bir board bulana kadar arıyor*/
        index = 0;
        for (int i = 0; i < border; ++i) {
            for (int j = 0; j < border; ++j) {
                chosen_number = choose_one_number(square - index);/*bir numara seçilir*/
                temp = numbers[chosen_number];                                  /*seçilen numara geçici bir değişkene atanır*/
                numbers[chosen_number] = numbers[square - index -
                                                 1];               /*numara array'inin en sonundaki sayı seçilen numarayla değiştirilir*/
                numbers[square - index -
                        1] = temp;                                /*geçici değişkene atanan sayı numara arayinin sonuna atanır*/
                //delete(&numbers[flag]);/*how to delete last element of a dynamic array
                arr[j][i] = numbers[square - index -
                                    1];                           /*seçilen sayı iki boyutlu dinamik array'e atanır*/
                index++;                                                        /*index bir arttırılarak sayıların olduğu array'deki son numara
                                                                                    bir daha eklenmemiş olur*/
            }
        }
        if(border %2 == 1) {
            flag = !isSolvableForOdd(arr, border);
        }else{
            flag = !isSolvableForEven(arr, border);
        }
    }
}

void print_2d_array(int (*arr)[9], int border) {

    for(int i = 0;i< border;++i ){
        for (int j = 0; j < border ; ++j) {
            if(arr[i][j] != 0)cout << arr[i][j];
            else{cout << " ";}
            if(arr[i][j]/10 == 0)cout << "   ";
            else{cout << "  ";}
        }
        cout << "\n";
    }
}


bool isMovable(int *coordinates_of_empty_box, char decission, int xBorder,int yBorder) {
    int x = coordinates_of_empty_box[0],y = coordinates_of_empty_box[1];
    /*if(x>yBorder && y>xBorder){cout << "congratz!!"; return true;}*/
    if(((decission == 'L' || decission == 'l') && x>0) || ((decission == 'U' || decission == 'u') &&  y > 0) ||
    ((decission == 'D' || decission == 'd') && y < yBorder-1) ||  ((decission == 'R' || decission == 'r') && x<xBorder-1)){
        return true;
    }
    return false;
}

bool move_left(int (*board)[9], int *coordinates_of_empty_space) {
    int y = coordinates_of_empty_space[0],x = coordinates_of_empty_space[1],temp;
    if(board[x][y-1] != 0) {
        temp = board[x][y - 1];
        board[x][y - 1] = board[x][y];
        board[x][y] = temp;
        coordinates_of_empty_space[0] = coordinates_of_empty_space[0] - 1;  /*revised coordinates of empty space*/
        return true;
    }
    return false;
}

bool move_right(int (*board)[9], int *coordinates_of_empty_space) {
    int y = coordinates_of_empty_space[0],x = coordinates_of_empty_space[1],temp;
     if(board[x][y + 1] != 0) {
         temp = board[x][y + 1];
         board[x][y + 1] = board[x][y];
         board[x][y] = temp;
         coordinates_of_empty_space[0] = coordinates_of_empty_space[0] + 1; /*revised coordinates of empty space*/
         return true;
     }

}

bool move_down(int (*board)[9], int *coordinates_of_empty_space) {
    int y = coordinates_of_empty_space[0],x = coordinates_of_empty_space[1],temp;
    if(board[x+1][y] != 0) {
        temp = board[x + 1][y];
        board[x + 1][y] = board[x][y];
        board[x][y] = temp;
        coordinates_of_empty_space[1] = coordinates_of_empty_space[1] + 1; /*revised coordinates of empty space*/
        return true;
    }
}

bool move_up(int (*board)[9], int *coordinates_of_empty_space) {
    int y = coordinates_of_empty_space[0],x = coordinates_of_empty_space[1],temp;
    if(board[x - 1][y] != 0) {
        temp = board[x - 1][y];
        board[x - 1][y] = board[x][y];
        board[x][y] = temp;
        coordinates_of_empty_space[1] = coordinates_of_empty_space[1] - 1; /*revised coordinates of empty space*/
        return true;
    }
}

bool make_decission(int (*arr)[9], int *coordinates_of_empty_box, int xBorder,int yBorder, char decission) {

    if ((decission == 'U' || decission == 'u') && arr[coordinates_of_empty_box[1]-1][coordinates_of_empty_box[0]] != 0) {
        if(isMovable(coordinates_of_empty_box,decission,xBorder,yBorder)) {
            move_up(arr,coordinates_of_empty_box);
            return true;
        }
    }else if ((decission == 'D' || decission == 'd') && arr[coordinates_of_empty_box[1]+1][coordinates_of_empty_box[0]] != 0) {
        if (isMovable(coordinates_of_empty_box,decission,xBorder,yBorder)) {
            move_down(arr,coordinates_of_empty_box);
            return true;
        }
    }else if ((decission == 'R' || decission == 'r' ) && arr[coordinates_of_empty_box[1]][coordinates_of_empty_box[0] +1] != 0) {
        if (isMovable(coordinates_of_empty_box,decission,xBorder,yBorder)) {
            move_right(arr,coordinates_of_empty_box);
            return true;
        }
    }else if ((decission == 'L' || decission == 'l') && arr[coordinates_of_empty_box[1]][coordinates_of_empty_box[0] - 1] != 0) {
        if (isMovable(coordinates_of_empty_box,decission,xBorder,yBorder)) {
            move_left(arr,coordinates_of_empty_box);
            return true;
        }
    }else{
        return false;
    }
}

int selectMin(int *arr) {
    int min,i=0;
    while(arr[i] == -1 && i<4){
        i++;
    }
    min = arr[i];
    for (i = 0; i <4  ; ++i) {
        if(arr[i]<min && arr[i] != -1){
            min = arr[i];
        }
    }

    for (int j = 0; j < 4; ++j) {
        if(arr[j] == min){
            return j;
        }
    }
}

void convertStringToInt(string word, int row, int (&board)[9][9], int j) {
    if(word.at(0) == '0' && word.at(1) == '0'){
        board[row][j] = 0;
    }else if(word.at(0) == '0' && word.at(1) != '0'){
        board[row][j] = word.at(1) - '0';
    }else if(word.at(0) != '0' && word.at(1) == '0'){
        board[row][j] = (word.at(0) - '0') * 10;
    }else if(word.at(0) == 'b' && word.at(1) == 'b'){
        board[row][j] = -1;
    }else if(word.at(0) != '0' && word.at(1) != '0'){
        board[row][j] = (word.at(0) - '0') * 10 + word.at(1) - '0';
    }
}

int removeDuplWord(string str, int (&board)[9][9] , int row) {
    string word = "";
    int j=0;
    for (auto x : str){
        if (x == ' ')
        {
            convertStringToInt(word,row,board,j);
            j++;
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    convertStringToInt(word,row,board,j);           /*Line okurken sonuncu sayının sonunda boşluk olmadığından
 //*                                                          fonksiyondan çıkarken son kalan kelimeyi de çeviriyorum*/
    return j;
}

char intelligent(int (*arr)[9], int *coordinates_of_empty_box, int xBorder, int yBorder) {
    int indexOfMotion,x,y,xMustBe,yMustBe;
    char directions[4] = {'U','D','L','R'};
    int wp[4];
    resetBoard(wp, 4);
    for (int k = 0; k < 4; ++k) {

        if(isMovable(coordinates_of_empty_box,directions[k],xBorder,yBorder+1)) {
            if(make_decission(arr, coordinates_of_empty_box, xBorder+1,yBorder+1, directions[k])) {
                for (int i = 1; i < (xBorder+1) * (yBorder+1); ++i) {
                    find_number(arr, xBorder + 1, yBorder + 1, i, x, y);
                    findWhereIMustBe(arr, xBorder + 1, yBorder + 1, i, xMustBe, yMustBe);
                    wp[k] += abs(x - xMustBe) + abs(y - yMustBe);
                }
                make_decission(arr, coordinates_of_empty_box, xBorder + 1, yBorder + 1, reverse(directions[k]));
            }
        }
    }

    for (int j = 0; j < 4; ++j) {
        if(wp[j]>=0 && wp[j]<3){
            return 'Q';
        }
    }
    if(isAllEqual(wp)){
        return moveRandom(arr,xBorder,yBorder,-1);
    }else {
        indexOfMotion = selectMin(wp);
        return directions[indexOfMotion];
    }

}

void findWhereIMustBe(int (*arr)[9], int xBorder, int yBorder, int number, int &xMustBe, int &yMustBe) {
    int counter=0;
    for (int i = 0; i < yBorder; ++i) {
        for (int j = 0; j < xBorder; ++j) {
            if(arr[i][j] != 0){
                counter++;
                if(counter == number){
                    xMustBe = j;
                    yMustBe = i;
                }
            }
        }
    }
}

char moveRandom(int (*arr)[9], int xBorder, int yBorder,int number) {
    char directions[4] = {'U','D','L','R'};
    int coordOfBb[2];
    find_number(arr,xBorder,yBorder,number,coordOfBb[0],coordOfBb[1]);
    int random = rand() %4;
    while(!isMovable(coordOfBb,directions[random],xBorder+1,yBorder+1)){
        random = rand() %4;
    };
    return directions[random];
}

char reverse(char input) {
    if(input == 'U'){
        return 'D';
    }else if(input == 'D'){
        return 'U';
    }else if(input == 'R'){
        return 'L';
    }else if(input == 'L'){
        return 'R';
    }
}

bool isAllEqual(int *wp) {
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 4; ++j) {
            if(wp[i] != wp[j]){
                if(wp[j] != -1 && wp[i] != -1){
                    return false;
                }
            }
        }
    }
    return true;
}

void convertIntToString(string & word, int (&board)[9][9] ,int xBorder, int i) {
    int counter=0;
    for (int j = 0; j < xBorder; ++j) {
        if(board[i][j] == 0){
            word.at(counter++) = '0';
            word.at(counter++) = '0';
        }else if(board[i][j] == -1){
            word.at(counter++) = 'b';
            word.at(counter++) = 'b';
        }else if(board[i][j] / 10 == 0){
            word.at(counter++) = '0';
            word.at(counter++) = board[i][j] + '0';
        }else if(board[i][j] /10 >= 1){
            word.at(counter++) = board[i][j]/10 + '0';
            word.at(counter++) = board[i][j]%10 + '0';
        }
        if(j != xBorder-1) {
            word.at(counter++) = ' ';
        }
    }
}











