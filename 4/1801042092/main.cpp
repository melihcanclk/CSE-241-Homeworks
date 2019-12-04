/*------------------GEBZE TECHNICAL UNIVERSITY---------------------*
*                    Name : Melihcan Çilek                         *
*                    Student Number : 1801042092                   *
*------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class NPuzzle {
public:
    void readFromFile(char argv[]);     /*Read From File*/
    void writeToFile();                 /*Writes To*/
    void print() const;                 /*Prints the board*/
    bool isSolved(int temp)const;               /*Understands whether the game is end or not*/
    bool move(char direction);          /*Move function*/
    char moveRandom();                  /*Function for random moves*/
    void printReport(int counter);      /*Function for print random*/
    void init();          /*Function for reset board*/
    void reset();
    void solvePuzzle();
    void shuffle(int n);                /*Function for move board randomly n times*/
    friend ostream & operator <<(ostream & outputStream, const NPuzzle & newPuzzle);
    friend istream & operator >>(istream & inputStream,  NPuzzle &newPuzzle);
private:
    char convertMoveIntToChar(int moveTo);       /*Convert 1,2,3,4 to U,D,L,R*/
    char reverse(char input);
    class Board {
    public:
        Board();
        void readFromFile(char argv[]);
        void writeToFile();
        char& getLastMove(){return (char &)lastMove;}
        int& getNumberOfMoves(){return (int &)numberOfMoves;}
        bool move(char direction);
        bool isValid(char direction);
        void init(int size);
        void reset();
        void print() const;
        void findCoordinates(int number,int coordinates[2]);                               /*Finds x and y coordinates*/

        const int &operator ()(int x,int y) const;
        int & operator()(int x,int y);
        bool operator==(const NPuzzle::Board & otherBoard) const;
        static int numberOfBoards;
    private:
        int convertStringToInt(string str);                /*Converts str to integer*/
        vector<vector <int>> vctr;
        char lastMove;
        int numberOfMoves;
    };
    vector <Board> comb;
    Board finalBoard;
    bool isInVector(const NPuzzle::Board& board);

    char findLastMove(NPuzzle::Board secondBoard);
};
int NPuzzle::Board::numberOfBoards = 1;

int main(int argc,char * argv[]) {
    //argc = 2;
    NPuzzle newPuzzle;
    char decission = 'S';
    srand(time(nullptr));
    int counter=0;
    const int RANDOM_MOVES = 5;
    if(argc == 1){
        newPuzzle.init();
    }else{
        newPuzzle.readFromFile(argv[1]);
    }
    while (decission != 'Q' && decission != 'q') {
        cout << newPuzzle;              /*Printing */
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
         if (decission == 'V' || decission == 'v') {
           newPuzzle.solvePuzzle();
        } else if (decission == 'E' || decission == 'e') {
            newPuzzle.writeToFile();
        } else if (decission == 'T' || decission == 't') {
            newPuzzle.printReport(counter);
        } else if (decission == 'O' || decission == 'o') {
            newPuzzle.readFromFile(argv[1]);
        } else if (decission == 'Q' || decission == 'q') {
            return 0;
        } else if (decission == 'S' || decission == 's') {
            newPuzzle.shuffle(RANDOM_MOVES);
        } else {
            newPuzzle.move(decission);
        }
    }

}
NPuzzle::Board::Board() {
    NPuzzle::Board::numberOfBoards = 1;
    this->lastMove = 'S';
    this->numberOfMoves = 0;
}


void NPuzzle::shuffle(int n) {
    int i=0,coordinates[2];
    const int EMPTY=-1;
    comb.at(0).findCoordinates(EMPTY,coordinates);
    while (i < n) {
        moveRandom();
        i++;
    }
}
void NPuzzle::init(){
    int size=0;
    while(size<3 || size >9){
        cout << "Please enter size of your NPuzzle: ";
        cin >> size;
        cout << endl;
    }
    comb.push_back(NPuzzle::Board());
    comb.at(0).init(size);
    int randNumb = rand() % (size * size);
    cout << randNumb << endl;
    this->shuffle(10);
    finalBoard.init(size);
}
void NPuzzle::Board::init(int size) {   /*1'den sizeofboard'a kadar initliyor.*/
    int index=1,i = 0, j = 0;
    for ( i = 0; i < size; i++) {
        vector<int> temp;
        for ( j = 0; j < size; j++) {
            temp.push_back(index);
            index++;
        }
        vctr.push_back(temp);
    }
    (*this)(j-1,i-1) = -1;
}

void NPuzzle::printReport(int counter) {
    cout << counter << " movement have been done" ;
    if(isSolved(1)){
        cout << " and solution is not found yet." ;
    }else{
        cout << " and solution is found" ;
    }
    cout << "\n";
}

void NPuzzle::Board::findCoordinates(int number,int coordinates[2]){
    for (int i = 0; i < vctr.size(); i++) {
        for (int j = 0; j < vctr[0].size(); j++) {
            if((*this)(i,j) == number){
                coordinates[0] = j;
                coordinates[1] = i;
            }
        }
    }
}


void NPuzzle::readFromFile(char argv[]) {
    comb.push_back(NPuzzle::Board());
    comb.at(0).readFromFile(argv);
    finalBoard.readFromFile(argv);
    finalBoard.reset();
}

void NPuzzle::Board::readFromFile(char argv[]) {
    const int EMPTY = -1;
    int coordinates[2];
    ifstream infile(argv);
    if(!infile.is_open()){
        cout << "File couldn't be open." << "\n";
    }
    int k=0;
    ifstream forCount(argv);
    string line;
    if(!forCount.is_open()){
        cout << "File couldn't be opened." << "\n";
    }
    int i=0,counterForX=0,counterForY=0;
    while(getline(forCount,line)){
        for(auto x:line){
            if(x == ' '){counterForX++;}
            i++;
        }
        counterForY++;
    }

    string pString;
    for (int i = 0; i < counterForY; i++) {
        vector<int> temp;
        for (int j = 0; j < (counterForX/counterForY) +1; j++) {
            infile >> pString;
            temp.push_back(convertStringToInt(pString));
            k++;
        }
        vctr.push_back(temp);
    }
    findCoordinates(EMPTY,coordinates);
}
void NPuzzle::writeToFile() {
    comb.at(0).writeToFile();
}

void NPuzzle::Board::writeToFile() {
    string name;
    int x = vctr[0].size(),y = vctr.size();
    cout << "Enter name of txt file:";
    cin >> name;
    name = name + ".txt";
    ofstream onfile(name);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if((*this)(i,j) == -1) {
                onfile << "bb";
            }else if((*this)(i,j) / 10 == 0) {
                onfile << "0" << (*this)(i,j);
            }else if((*this)(i,j) / 10 >= 1){
                onfile << (*this)(i,j);
            }
            if(j+1 != x){
                onfile << " ";
            }
        }
        if(i+1 != y){
            onfile << "\n";
        }
    }
}

bool NPuzzle::Board::isValid(const char direction ) {
    int coordinates[2];
    const int EMPTY = -1;
    findCoordinates(EMPTY,coordinates);
    if((direction == 'L' || direction == 'l') && coordinates[0]-1 >= 0 && vctr[coordinates[1]][coordinates[0] - 1] != 0){
        return true;
    }else if((direction == 'R' || direction == 'r') && coordinates[0]+1 < vctr[0].size() && vctr[coordinates[1]][coordinates[0] + 1] != 0){
        return true;
    }else if((direction == 'U' || direction == 'u') && coordinates[1]-1 >= 0 && vctr[coordinates[1] - 1][coordinates[0]] != 0){
        return true;
    }else if((direction == 'D' || direction == 'd') && coordinates[1]+1 < vctr.size() && vctr[coordinates[1] + 1][coordinates[0]] != 0){
        return true;
    }else {
        return false;
    }
}
void NPuzzle::print() const {
    comb.at(0).print();
}

void NPuzzle::Board::print() const{
    int x = vctr[0].size(),y = vctr.size();
    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++) {
            if((*this)(i,j) == -1) {
                cout << "bb";
            }else if((*this)(i,j) / 10 == 0) {
                cout << "0" << (*this)(i,j);
            }else if((*this)(i,j) / 10 >= 1){
                cout << (*this)(i,j);
            }
            cout << " ";
        }
        cout << "\n";
    }
}

bool NPuzzle::move(char direction) {
    comb.at(NPuzzle::Board::numberOfBoards-1).move(direction);
}

bool NPuzzle::Board::move(char direction) {
    int temp,x,y;
    int coordinates[2];
    const int EMPTY = -1;
    findCoordinates(EMPTY,coordinates);
    x=coordinates[0];
    y=coordinates[1];
    if(direction == 'L' || direction == 'l'){
        if(isValid('L')){
            temp = (*this)(y,x-1);
            (*this)(y,x-1) = (*this)(y,x);
            (*this)(y,x) = temp;

        }else{
            return false;
        }
    }else if(direction == 'R' || direction == 'r'){
        if(isValid('R')){
            temp = (*this)(y,x+1);
            (*this)(y,x+1) = (*this)(y,x);
            (*this)(y,x) = temp;
        }else{
            return false;
        }
    }else if(direction == 'U' || direction == 'u'){
        if(isValid('U')){
            temp = (*this)(y-1,x);
            (*this)(y-1,x) = (*this)(y,x);
            (*this)(y,x)= temp;
        }else{
            return false;
        }
    }else if(direction == 'D' || direction == 'd'){
        if(isValid('D')){
            temp =(*this)(y+1,x);
            (*this)(y+1,x) = (*this)(y,x);
            (*this)(y,x) = temp;
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
    while(!comb.at(0).isValid(convertMoveIntToChar(moveTo))){
        moveTo = rand()%4;
    }
    move(convertMoveIntToChar(moveTo));
}

char NPuzzle::reverse(char input) {
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

void NPuzzle::solvePuzzle(){
    char directions[4] = {'R','L','U','D'};
    vector <char> moves;
    int index=comb.at(0).getNumberOfMoves(),temp=0;

    while(!isSolved(temp)){
        if(index!=0){
            temp =+ NPuzzle::Board::numberOfBoards;
        }
        for (int k=0;k<4;k++) {
            if(directions[k] != reverse(comb.at(index).getLastMove()) && comb.at(index).isValid(directions[k]) ){
                comb.push_back(comb.at(index));
                comb.at(NPuzzle::Board::numberOfBoards).move(directions[k]);
                 if(!isInVector(comb.at(NPuzzle::Board::numberOfBoards))) {
                    comb.at(NPuzzle::Board::numberOfBoards).getLastMove() = directions[k];
                    comb.at(NPuzzle::Board::numberOfBoards).getNumberOfMoves() = index + 1;
                     NPuzzle::Board::numberOfBoards++;
                }else{
                     comb.pop_back();
                 }
            }
        }
        index++;
    }
    Board tempBoard = finalBoard;
    char lastMove;
    int counter = 0;
    while(lastMove != 'S') {
        lastMove = findLastMove(tempBoard);
        moves.push_back(lastMove);
        tempBoard.move(reverse(lastMove));
        counter++;
    }
    counter--;
    while(counter != -1){
        comb.at(0).move(moves[counter]);
        comb.at(0).print();
        cout << "-------------------------" << endl;
        counter--;
    }
    NPuzzle::Board::numberOfBoards = 1;
    comb.resize(1);
}

bool NPuzzle::isSolved(int temp) const {
    for (int i = temp; i < NPuzzle::Board::numberOfBoards; ++i) {
        if(comb.at(i) == finalBoard){
            return true;
        }
    }
    return false;
}

char NPuzzle::findLastMove(NPuzzle::Board goalBoard) {
    for (int i = 0; i < NPuzzle::Board::numberOfBoards; ++i) {
        if(comb.at(i) == goalBoard){
            return comb.at(i).getLastMove();
        }
    }
}


int NPuzzle::Board::convertStringToInt(string str) {

    if(str.at(0) == '0' && str.at(1) == '0'){
        return 0;
    }else if(str.at(0) == '0' && str.at(1) != '0'){
        return str.at(1) - '0';
    }else if(str.at(0) != '0' && str.at(1) == '0'){
        return (str.at(0) - '0') * 10;
    }else if(str.at(0) == 'b' && str.at(1) == 'b'){
        return -1;
    }else if(str.at(0) != '0' && str.at(1) != '0'){
        return (str.at(0) - '0') * 10 + str.at(1) - '0';
    }
}
int &NPuzzle::Board::operator()(int x,int y) {              /*lvalue*/
    if(x>=0 && x<vctr.size() && y>=0 && y<vctr.size()){
        return vctr[x][y];
    }else{
        cout << "This coordinate is not valid." << endl;
    }
}

const int &NPuzzle::Board::operator()(int x,int y) const{ /*rvalue*/
    if(x>=0 && x< vctr[0].size() && y>=0 && y< vctr.size()){
      return vctr[x][y];
    }else{
        cout << "This coordinate is not valid." << endl;
    }
}
bool NPuzzle::Board::operator==(const NPuzzle::Board & otherBoard) const{
    int x = vctr[0].size(),y = vctr.size();
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            if(this->vctr[i][j] != otherBoard.vctr[i][j]){
                return false;
            }
        }
    }
    return true;
}

ostream & operator <<(ostream & outputStream, const NPuzzle & newPuzzle) {

    newPuzzle.print();
    return outputStream;
}


istream & operator >>(istream & inputStream, NPuzzle & newPuzzle) {

    newPuzzle.writeToFile();
    return inputStream;
}

void NPuzzle::reset() {
    finalBoard.reset();
}

bool NPuzzle::isInVector(const NPuzzle::Board& newBoard) {
    for (int i = 0; i < NPuzzle::Board::numberOfBoards; ++i) {
        if(newBoard == comb.at(i)){
            return true;
        }
    }
    return false;
}

void NPuzzle::Board::reset() {
    int index=1,i=0, j = 0,x,y;
    x=vctr[0].size();
    y=vctr.size();
    for (i = 0; i < y ; i++) {
        for (j = 0; j < x; j++) {
            if(vctr[i][j] != 0) {
                vctr[i][j] = index;
                index++;
            }
        }

    }
    vctr[i-1][j-1] = -1;
}



