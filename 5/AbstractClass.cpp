#include <iostream>
#include <fstream>
#include "AbstractClass.h"
using namespace std;

void AbstractClass::setSize(int coordinates[2]){
    this->size[0] = coordinates[0];
    this->size[1] = coordinates[1];
}

void AbstractClass::print(){   
    for (int i = 0; i < size[1]; i++){
        for (int j = 0; j < size[0]; j++) {
            int index = (*this)(j,i);
            if(index == -1) {           
                cout << "bb";
            }else if(index / 10 == 0) {
                cout << "0" << index;  
            }else if(index/ 10 >= 1){          
                cout << index;
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
int AbstractClass::getNumberOfBoards(){
    return numberOfBoards;
}
char AbstractClass::getLastMove(){
    return lastMove;
}
int AbstractClass::getNumberOfMoves(){
    return numberOfMoves;
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

void AbstractClass::findCoordinates(int number,int coordinates[2]){
    for (int i = 0; i < size[1]; i++) {
        for (int j = 0; j < size[0]; j++) {
            if((*this)(j,i) == number){
                coordinates[0] = j;
                coordinates[1] = i;
            }
        }
    }
}
int AbstractClass::convertStringToInt(string str) {

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

char AbstractClass::reverse(char input){
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

void AbstractClass::shuffle(int n ) {
    int i=0;
    while (i < n) {
        moveRandom();
        i++;
    }
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


void AbstractClass::moveRandom(){
    int moveTo;
    moveTo = rand()%4;
    while(!this->isValid(convertMoveIntToChar(moveTo))){
        moveTo = rand()%4;
    }
    move(convertMoveIntToChar(moveTo));
}
