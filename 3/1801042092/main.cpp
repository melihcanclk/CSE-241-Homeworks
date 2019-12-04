/*------------------GEBZE TECHNICAL UNIVERSITY---------------------*                                                     
*                    Name : Melihcan Çilek                         *                                 
*                    Student Number : 1801042092                   *
*                                                                  */     
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class NPuzzle {
	public:
	    void readFromFile(char argv[]);     /*Read From File*/
	    void writeToFile();                 /*Writes To*/
	    void print() const;                 /*Prints the board*/
	    void setSize(int size);             /*Sets size of board*/
	    bool isSolved()const;               /*Understands whether the game is end or not*/
	    bool move(char direction);          /*Move function*/
	    char moveRandom();                  /*Function for random moves*/
	    void printReport(int counter);      /*Function for print random*/
	    void reset(int & counter);          /*Function for reset board*/
	    void shuffle(int n);                /*Function for move board randomly n times*/
	    void initBoard();                   /*Function for initialize board*/
	    void intelligent();                 /*Function for move intelligently*/
	private:
    		char convertMoveIntToChar(int integ);       /*Convert 1,2,3,4 to U,D,L,R*/
  	  class Board {
	    public:
		void setSize(int size);
		void changeCoordinates(int x,int y);    /*Takes two parameter to change value of empty space coordinates*/
		int getSizeX(){return sizeOfBoard[0];}  /*Getter for X coordinate of board*/
		int getSizeY(){return sizeOfBoard[1];}  /*Getter for Y coordinate of board*/
		void readFromFile(char argv[]);         
		void writeToFile();
		void print() const;  /*Prints the board*/
		bool move(char direction);
		bool isSolved()const;
		bool isValid(const char direction);
		void reset(int & counter);
		void findCoordinates(int number);                               /*Finds x and y coordinates*/
		void findCoordinates(int number,int coordinates[2]);            /*Finds x and y coordinates and return them*/
		void findWhereNumberMustBe(int number,int coordinates[2]);      /*Finds where number must be at the board*/
		void intelligent();                                                             
	    private:
		int selectMin(int arr[4]);                                      /*Selects minimum number on that array*/
		void convertStringToInt(string str,int i,int j);                /*Converts str to integer*/
		int findNumberOfZeros();                                        /*How many 0's on the board*/
		int getSizeOfFile(char argv[]);                                 /*Gets x and y sizes of read text from file*/
		int sizeOfBoard[2];
		int arr[9][9];
		int coordinatesOfEmpty[2];
    };
    Board newBoard;
};


int main(int argc,char * argv[]) {
    NPuzzle newPuzzle;
    char prevMove, decission;
    srand(time(NULL));
    int counter=0 , size,i=0;
    const int MOVE_NUMBER = 200, SHUFFLE_TIMES = 5,MAX_MOVE = 2000000;
    if(argc == 1){
        cout << "Please enter size of your NPuzzle: ";
        cin >> size;
        newPuzzle.setSize(size);
        newPuzzle.reset(counter);
        newPuzzle.initBoard();
    }else{
        newPuzzle.readFromFile(argv[1]);
    }
    while (!newPuzzle.isSolved()) {
        newPuzzle.print();
        cout << "Please select one of the selection below:" << "\n";
        cout << "U,u->Moves up." << "\n";
        cout << "D,d->Moves down" << "\n";
        cout << "L,l->Moves left" << "\n";
        cout << "R,r->Moves right" << "\n";
        cout << "I,i->Moves intelligent" << "\n";
        cout << "V,v->Solve the problem from the current configuration\n"
                "using the new intelligent algorithm." << "\n";
        cout << "E,e->Asks a file name and saves the current board \n"
                "configuration as a loadable shape file.." << "\n";
        cout << "T,t->Prints a report about how many moves have been "
                "done and if the solution is found" << "\n";
        cout << "O,o->Asks a file name and loads the current board "
                "configuration from the shape file." << "\n";
        cout << "Q,q->Quit from the game" << "\n";
        cout << "Selection:";
        cin >> decission;
        if (decission == 'I' || decission == 'i') {
            newPuzzle.intelligent();
        } else if (decission == 'V' || decission == 'v') {
            while(!newPuzzle.isSolved() && counter<MAX_MOVE ){
                newPuzzle.intelligent();
                if(counter % MOVE_NUMBER== MOVE_NUMBER -1){
                    newPuzzle.shuffle(SHUFFLE_TIMES);
                }
                newPuzzle.print();
                cout << counter << "\n" ;
                counter++;
            }
            counter=0;
        } else if (decission == 'E' || decission == 'e') {
            newPuzzle.writeToFile();
        } else if (decission == 'T' || decission == 't') {
            newPuzzle.printReport(counter);
        } else if (decission == 'O' || decission == 'o') {
            newPuzzle.readFromFile(argv[1]);
        } else if (decission == 'Q' || decission == 'q') {
            return 0;
        } else if (decission == 'S' || decission == 's') {
            newPuzzle.shuffle(SHUFFLE_TIMES);
        } else {
            newPuzzle.move(decission);
        }
    }
}

void NPuzzle::shuffle(int n) {
    int i=0;
    const int EMPTY=-1;
    newBoard.findCoordinates(EMPTY);
    while (i < n) {
        moveRandom();
        i++;
    }
}
void NPuzzle::reset(int & counter){
    newBoard.reset(counter);
}
void NPuzzle::Board::reset(int & counter) {
    counter = 0;
    int index=1,i,j;
    for ( i = 0; i < sizeOfBoard[1]; i++) {
        for ( j = 0; j < sizeOfBoard[0]; j++) {
            arr[i][j] = index;
            index++;
        }

    }
    arr[i-1][j-1] = -1;
}

void NPuzzle::printReport(int counter) {
    cout << counter << " movement have been done" ;
    if(isSolved()){
        cout << " and solution is not found yet." ;
    }else{
        cout << " and solution is found" ;
    }
    cout << "\n";
}

void NPuzzle::setSize(int size) {
    newBoard.setSize(size);
}

void NPuzzle::Board::setSize(int size) {
    if(size >=3 && size <=9){
        sizeOfBoard[1] = sizeOfBoard[0] = size;
    }else if(size == 0){
        return;
    }
}

void NPuzzle::initBoard() {
    const int SHUFFLE_NUMBER= newBoard.getSizeX() * newBoard.getSizeX();
    shuffle(SHUFFLE_NUMBER);
}
void NPuzzle::Board::findCoordinates(int number,int coordinates[2]){
    for (int i = 0; i < sizeOfBoard[1]; i++) {
        for (int j = 0; j < sizeOfBoard[0 ]; j++) {
            if(arr[i][j] == number){
                coordinates[0] = j;
                coordinates[1] = i;
            }
        }
    }
}
void NPuzzle::Board::findCoordinates(int number){
    for (int i = 0; i < sizeOfBoard[1]; i++) {
        for (int j = 0; j < sizeOfBoard[0]; j++) {
            if(arr[i][j] == number){
                coordinatesOfEmpty[0] = j;
                coordinatesOfEmpty[1] = i;
            }
        }
    }
}

int NPuzzle::Board::findNumberOfZeros() {
    int counter=0;
    for (int i = 0; i < sizeOfBoard[1] ; i++){
        for (int  j = 0; j < sizeOfBoard[0] ; j++)
        {
            if(arr[i][j] == 0){
                counter++;
            }
        }

    }
    return counter;
}

void NPuzzle::Board::changeCoordinates(int x,int y) {
    coordinatesOfEmpty[0] = x;
    coordinatesOfEmpty[1] = y;
}

void NPuzzle::readFromFile(char argv[]) {
    newBoard.readFromFile(argv);
}

void NPuzzle::Board::readFromFile(char argv[]) {
    const int EMPTY = -1;
    ifstream infile(argv);
    if(!infile.is_open()){
        cout << "File couldn't be open." << "\n";
    }
    int x,y,i,k=0;
    getSizeOfFile(argv);
    string pString[(sizeOfBoard[0] * sizeOfBoard[1]) + 1];
    for (int i = 0; i < sizeOfBoard[1]; i++) {
        for (int j = 0; j < sizeOfBoard[0]; j++) {
            infile >> pString[k];
            convertStringToInt(pString[k], i, j);
            k++;
        }
    }

    findCoordinates(EMPTY);
}
void NPuzzle::writeToFile() {
    newBoard.writeToFile();
}


void NPuzzle::Board::writeToFile() {
    string name;
    cout << "Enter name of txt file:";
    cin >> name;
    name = name + ".txt";
    ofstream onfile(name);
    for (int i = 0; i < sizeOfBoard[1]; i++) {
        for (int j = 0; j < sizeOfBoard[0]; j++) {
            if(arr[i][j] == 0) {
                onfile << "bb";
            }else if(arr[i][j] / 10 == 0) {
                onfile << "0" << arr[i][j];
            }else if(arr[i][j] / 10 >= 1){
                onfile << arr[i][j];
            }
            if(j+1 != sizeOfBoard[0]){
                onfile << " ";
            }
        }
        if(i+1 != sizeOfBoard[1]){
            onfile << "\n";
        }
    }
}

int NPuzzle::Board::getSizeOfFile(char argv []){
    ifstream infile(argv);
    string line;
    if(!infile.is_open()){
        cout << "File couldn't be opened." << "\n";
    }
    int i=0,counterForX=0,counterForY=0;
    while(getline(infile,line)){
        for(auto x:line){
            if(x == ' '){counterForX++;}
            i++;
        }
        counterForY++;
    }
    sizeOfBoard[0] = (counterForX/counterForY) +1;
    sizeOfBoard[1] = counterForY;

}

bool NPuzzle::Board::isValid(const char direction ) {
    if((direction == 'L' || direction == 'l') && coordinatesOfEmpty[0]-1 >= 0 && arr[coordinatesOfEmpty[1]][coordinatesOfEmpty[0]-1] != 0){
        return true;
    }else if((direction == 'R' || direction == 'r') && coordinatesOfEmpty[0]+1 < sizeOfBoard[0] && arr[coordinatesOfEmpty[1]][coordinatesOfEmpty[0]+1] != 0){
        return true;
    }else if((direction == 'U' || direction == 'u') && coordinatesOfEmpty[1]-1 >= 0 && arr[coordinatesOfEmpty[1]-1][coordinatesOfEmpty[0]] != 0){
        return true;
    }else if((direction == 'D' || direction == 'd') && coordinatesOfEmpty[1]+1 < sizeOfBoard[1] && arr[coordinatesOfEmpty[1]+1][coordinatesOfEmpty[0]] != 0){
        return true;
    }else {
        return false;
    }
}
void NPuzzle::print() const {
    newBoard.print();
}

void NPuzzle::Board::print() const{
    for (int i = 0; i < sizeOfBoard[1]; i++){
        for (int j = 0; j < sizeOfBoard[0]; j++) {
            if(arr[i][j] == -1) {
                cout << "bb";
            }else if(arr[i][j] / 10 == 0) {
                cout << "0" << arr[i][j];
            }else if(arr[i][j] / 10 >= 1){
                cout << arr[i][j];
            }
            cout << " ";
        }
        cout << "\n";
    }
}
bool NPuzzle::move(char direction) {
    newBoard.move(direction);
}

bool NPuzzle::Board::move(char direction) {
    int temp,x,y;
    x=coordinatesOfEmpty[0];
    y=coordinatesOfEmpty[1];
    if(direction == 'L' || direction == 'l'){
        if(isValid('L')){
            temp = arr[y][x-1];
            arr[y][x-1] = arr[y][x];
            arr[y][x] = temp;
            changeCoordinates(x-1,y);
        }else{
            return false;
        }
    }else if(direction == 'R' || direction == 'r'){
        if(isValid('R')){
            temp = arr[y][x+1];
            arr[y][x+1] = arr[y][x];
            arr[y][x] = temp;
            changeCoordinates(x+1,y);
        }else{
            return false;
        }
    }else if(direction == 'U' || direction == 'u'){
        if(isValid('U')){
            temp = arr[y-1][x];
            arr[y-1][x] = arr[y][x];
            arr[y][x] = temp;
            changeCoordinates(x,y-1);
        }else{
            return false;
        }
    }else if(direction == 'D' || direction == 'd'){
        if(isValid('D')){
            temp = arr[y+1][x];
            arr[y+1][x] = arr[y][x];
            arr[y][x] = temp;
            changeCoordinates(x,y+1);
        }else{
            return false;
        }
    }
    return true;
}
char NPuzzle::convertMoveIntToChar(int moveTo) {
    if (moveTo == 0) {
        return 'U';
    }else if (moveTo == 1){
        return 'D';
    }else if (moveTo == 2){
        return 'L';
    }else if (moveTo == 3){
        return 'R';
    }
}
char NPuzzle::moveRandom() {
    int moveTo;
    moveTo = rand()%4;
    while(!newBoard.isValid(convertMoveIntToChar(moveTo))){
        moveTo = rand()%4;
    }
    move(convertMoveIntToChar(moveTo));
}

bool NPuzzle::isSolved() const {
    newBoard.isSolved();
}

bool NPuzzle::Board::isSolved()const {
    int index=1,counter=0;
    for (int i = 0; i < sizeOfBoard[1] ; i++) {
        for (int j = 0; j < sizeOfBoard[0]; j++) {
            if(arr[i][j] != 0) {
                if (arr[i][j] != index) {
                    counter++;
                }
                index++;
            }
        }

    }
    if(counter == 1){
        return true;
    }else{
        return false;
    }

}
void NPuzzle::Board::convertStringToInt(string str,int i,int j) {

    if(str.at(0) == '0' && str.at(1) == '0'){
        arr[i][j] = 0;
    }else if(str.at(0) == '0' && str.at(1) != '0'){
        arr[i][j] = str.at(1) - '0';
    }else if(str.at(0) != '0' && str.at(1) == '0'){
        arr[i][j] = (str.at(0) - '0') * 10;
    }else if(str.at(0) == 'b' && str.at(1) == 'b'){
        arr[i][j] = -1;
    }else if(str.at(0) != '0' && str.at(1) != '0'){
        arr[i][j] = (str.at(0) - '0') * 10 + str.at(1) - '0';
    }



}
void NPuzzle::Board::findWhereNumberMustBe(int number,int coordinates[2]){
    int counter=0;
    for (int i = 0; i < sizeOfBoard[1]; ++i) {
        for (int j = 0; j < sizeOfBoard[0] ; ++j) {
            if(arr[i][j] != 0){
                counter++;
                if(counter == number){
                    coordinates[0] = j;
                    coordinates[1] = i;
                }
            }
        }
    }
}
int NPuzzle::Board::selectMin(int arr[4]) {
    int min,i=0,bin[4],counter=0;

    min = arr[i];
    for (i = 0; i <4  ; ++i) {
        if(arr[i]<min){
            min = arr[i];
            counter++;
        }
    }
    for (int  i = 0; i < 4; i++) {
        if(arr[i] == min){
            bin[i] = -1;

        }else{
            bin[i] = 0;
        }
    }
    if(counter == 1){
        for (int j = 0; j < 4; ++j) {
            if(arr[j] == min){
                return j;
            }
        }
    }else{
        counter = rand() % 4;				/*buraya bak*/
        while(bin[counter] == 0){
            counter = rand() % 4;
        }
        return counter;
    }
}

void NPuzzle::intelligent() {
    newBoard.intelligent();
}

void NPuzzle::Board::intelligent() {
    int coordinates[2],coordinatesMustBe[2];
    char directions[4] = {'U','D','L','R'};
    int wp[4];
    for (int i = 0; i < 4; i++) {
        wp[i] = 1000;
    }
    for (int k = 0; k < 4; ++k) {
        if(move(directions[k])){
            wp[k] = 0;
            for (int i = 1; i < (sizeOfBoard[0] * sizeOfBoard[1]) - findNumberOfZeros(); ++i) {
                findCoordinates(i,coordinates);
                findWhereNumberMustBe(i,coordinatesMustBe);
                wp[k] += abs(coordinates[0] - coordinatesMustBe[0]) + abs(coordinates[1] - coordinatesMustBe[1]);
            }
            if(k%2 == 0){
                move(directions[k+1]);
            }else{
                move(directions[k-1]);
            }
        }
    }
    cout << "Intelligent choose " << directions[selectMin(wp)] << "\n";
    move(directions[selectMin(wp)]);
}
