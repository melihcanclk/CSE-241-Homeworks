#include <iostream>
#include <fstream>
#include "AbstractClass.h"
using namespace std;
using namespace Puzzle;

bool isValid(AbstractClass ** pAbstractClass,int size){                          //global function
    int j=0;
    for(int i=0;i< size -1;i++){
        /*if(!( pAbstractClass[i]->isSolved() )){
            return false;
        }*/
        int diff = AbstractClass::findDiff(pAbstractClass[i],pAbstractClass[i+1]);
        if( diff != 1  && diff != -1){
            return false;
        }
    }
    return true;
}


AbstractClass::AbstractClass(){
    //AbstractClass::numberOfBoards++;
}
void AbstractClass::setSize(int coordinates[2]){
    this->size[0] = coordinates[0];
    this->size[1] = coordinates[1];
}

void AbstractClass::print(){   
    for (int i = 0; i < size[1]; i++){
        for (int j = 0; j < size[0]; j++) {
            int index = (*this)(j,i);
            if(size[0] * size[1] <= 100){
                if(index == -1) {
                    cout << "bb";
                }else if(index / 10 == 0) {
                    cout << "0" << index;
                }else if(index/ 10 >= 1){
                    cout << index;
                }
            }else if (size[0] * size[1] > 100 && size[0] * size[1] <= 1000){
                if(index == -1) {
                    cout << "bb ";
                }else if(index / 10 == 0) {
                    cout << "00" << index;
                }else if(index / 100 == 0) {
                    cout << "0" << index;
                }else if(index/ 100 >= 1){
                    cout << index;
                }
            }
            cout << " ";
        }
        cout << "\n";
    }
}
void AbstractClass::readFromFile(char *argv){
    int coordinates[2],k=0;
        ifstream infile(argv);
        if(!infile.is_open()){
            cout << "File couldn't be open." << "\n";
        }
        string pString;
        calculateXandY(argv,coordinates);
        
}

void AbstractClass::writeToFile() {
    string name;
    cout << "Enter name of txt file:";
    cin >> name;
    name = name + ".txt";
    ofstream onfile(name);
    for (int i = 0; i < size[1]; i++) {
        for (int j = 0; j < size[0]; j++) {
            if((*this)(i,j) == -1) {
                onfile << "bb";
            }else if((*this)(i,j) / 10 == 0) {
                onfile << "0" << (*this)(i,j);
            }else if((*this)(i,j) / 10 >= 1){
                onfile << (*this)(i,j);
            }
            if(j+1 != size[0]){
                onfile << " ";
            }
        }
        if(i+1 != size[1]){
            onfile << "\n";
        }
    }
}
/*int AbstractClass::getNumberOfBoards(){
    return numberOfBoards;
}*/
char AbstractClass::getLastMove(){
    return lastMove;
}

char AbstractClass::convertMoveIntToChar(int moveTo) {
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
void AbstractClass::calculateXandY(string argv,int coordinates[2]){
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
    coordinates[0] = (counterForX / counterForY) +1;
    coordinates[1] = counterForY;
}


bool AbstractClass::move(char direction) {
    int temp,x,y;
    int coordinates[2];
    const int EMPTY = -1;
    findCoordinates(EMPTY,coordinates);
    x=coordinates[0];
    y=coordinates[1];
    if(direction == 'L' || direction == 'l'){
        if(isValid('L')){
            temp = (*this)(x-1,y);
            (*this)(x-1,y) = (*this)(x,y);
            (*this)(x,y) = temp;

        }else{
            return false;
        }
    }else if(direction == 'R' || direction == 'r'){
        if(isValid('R')){
            temp = (*this)(x+1,y);
            (*this)(x+1,y) = (*this)(x,y);
            (*this)(x,y) = temp;
        }else{
            return false;
        }
    }else if(direction == 'U' || direction == 'u'){
        if(isValid('U')){
            temp = (*this)(x,y-1);
            (*this)(x,y-1) = (*this)(x,y);
            (*this)(x,y)= temp;
        }else{
            return false;
        }
    }else if(direction == 'D' || direction == 'd'){
        if(isValid('D')){
            temp =(*this)(x,y+1);
            (*this)(x,y+1) = (*this)(x,y);
            (*this)(x,y) = temp;
        }else{
            return false;
        }
    }
    //lastMove = direction;
    //numberOfMoves++;
    return true;
}

bool AbstractClass::isValid(const char direction){
    int coordinates[2];
    const int EMPTY = -1;
    findCoordinates(EMPTY,coordinates);
    if((direction == 'L' || direction == 'l') && coordinates[0]-1 >= 0 &&  (*this)(coordinates[0] -1,coordinates[1] ) != 0){
        return true;
    }else if((direction == 'R' || direction == 'r') && coordinates[0]+1 < size[0] && (*this)(coordinates[0] +1,coordinates[1]) != 0){
        return true;
    }else if((direction == 'U' || direction == 'u') && coordinates[1]-1 >= 0 && (*this)(coordinates[0],coordinates[1]-1 ) != 0){
        return true;
    }else if((direction == 'D' || direction == 'd') && coordinates[1]+1 < size[1] && (*this)(coordinates[0] ,coordinates[1]+1) != 0){
        return true;
    }else {
        return false;
    }
}

void AbstractClass::findCoordinates(int number,int coordinates[2])const {
    for (int i = 0; i < this->size[1]; i++) {
        for (int j = 0; j < this->size[0]; j++) {
            if((*this)(j,i) == number){
                coordinates[0] = j;
                coordinates[1] = i;
            }
        }
    }
}

int AbstractClass::findDiff(AbstractClass *left, AbstractClass *right) {
    int EMPTY = -1,coordinatesleft[2],coordinatesright[2];
    left->findCoordinates(EMPTY,coordinatesleft);
    right->findCoordinates(EMPTY,coordinatesright);
    return (coordinatesleft[0] - coordinatesright[0]) + (coordinatesleft[1] - coordinatesright[1]);
}

void AbstractClass::reset(){
    int index=1,i=0, j = 0;
    for (i = 0; i < size[1] ; i++) {
        for (j = 0; j < size[0]; j++) {
            if((*this)(i,j) != 0) {
                (*this)(i,j) = index;
                index++;
            }
        }

    }
}


char AbstractClass::moveRandom(){
    int moveTo;
    moveTo = rand()%4;
    while(!this->isValid(convertMoveIntToChar(moveTo))){
        moveTo = rand()%4;
    }
    move(convertMoveIntToChar(moveTo));
    return convertMoveIntToChar(moveTo);
}

bool AbstractClass::operator==(const AbstractClass & right){
    for(int i = 0; i < size[1] ;i++){
        for (int j = 0; j < size[0]; j++)
        {
            if((*this)(j,i) != right(j,i)){
                return false;
            }
        }
        
    }
    return true;
}

bool AbstractClass::isSolved()  {
    int index=1;
    for(int i = 0; i < size[1]; ++i){
        for(int j = 0; j < size[0]; ++j){
            int a = (*this)(j,i);
            if(index == (*this)(j,i)){}
            else{
                if(i!= size[1]-1 || j != size[0] -1){
                    return false;
                }
            }
            index++;
        }
    }
    return true;
}
