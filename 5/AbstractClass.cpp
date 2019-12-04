#include <iostream>
#include <fstream>
#include "AbstractClass.h"
using namespace std;
/*
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
}*/
void AbstractClass::calculateXandY(char * argv,int coordinates[2]){
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
    coordinates[0] = counterForX;
    coordinates[1] = counterForY;
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

char AbstractClass::convertMoveIntToChar(int moveTo){
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

