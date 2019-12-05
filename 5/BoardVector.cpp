#include <iostream>
#include <fstream>
#include "BoardVector.h"

using namespace std;

void BoardVector::setSize(int size){
    int index=1,i = 0, j = 0;
    for ( i = 0; i < size; i++) {
        vector<int> temp;
        for ( j = 0; j < size; j++) {
            temp.push_back(index);
            index++;
        }
        vctr.push_back(temp);
    }
    (*this)(i-1,j-1) = -1;           
}

void BoardVector::print(){
    int x = vctr[0].size(),y = vctr.size();
    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++) {
            if((*this)(i,j) == -1) {           
                cout << "bb";
            }else if((*this)(i,j) / 10 == 0) {
                cout << "0" << (*this)(i,j);  
            }else if((*this)(i,j)/ 10 >= 1){          
                cout << (*this)(i,j);
            }
            cout << " ";
        }
        cout << "\n";
    }
}
void BoardVector::readFromFile(char *argv){
    if(vctr.size() >0){
        vctr.clear();
        print();
    }
    int coordinates[2],k=0;
        ifstream infile(argv);
        if(!infile.is_open()){
            cout << "File couldn't be open." << "\n";
        }
        string pString;
        calculateXandY(argv,coordinates);
        for (int i = 0; i < coordinates[1]; i++) {
            vector<int> temp;
            for (int j = 0; j < coordinates[0]; j++) {
                infile >> pString;
                temp.push_back(convertStringToInt(pString));
                k++;
            }
            vctr.push_back(temp);
        }
}
void BoardVector::writeToFile() {
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


bool BoardVector::isValid(const char direction){
    int coordinates[2];
    const int EMPTY = -1;
    findCoordinates(EMPTY,coordinates);
    if((direction == 'L' || direction == 'l') && coordinates[0]-1 >= 0 && (*this)(coordinates[1],coordinates[0] - 1) != 0){
        return true;
    }else if((direction == 'R' || direction == 'r') && coordinates[0]+1 < vctr[0].size() && (*this)(coordinates[1],coordinates[0]+ 1) != 0){
        return true;
    }else if((direction == 'U' || direction == 'u') && coordinates[1]-1 >= 0 && (*this)(coordinates[1] -1,coordinates[0]) != 0){
        return true;
    }else if((direction == 'D' || direction == 'd') && coordinates[1]+1 < vctr.size() && (*this)(coordinates[1] +1,coordinates[0]) != 0){
        return true;
    }else {
        return false;
    }
}

void BoardVector::findCoordinates(int number,int coordinates[2]){
    for (int i = 0; i < vctr.size(); i++) {
        for (int j = 0; j < vctr[0].size(); j++) {
            if((*this)(i,j) == number){
                coordinates[0] = j;
                coordinates[1] = i;
            }
        }
    }
}
int &BoardVector::operator()(int x,int y) {              /*lvalue*/
    if(x>=0 && x<vctr.size() && y>=0 && y<vctr.size()){
        return vctr[x][y];
    }else{
        cout << "This coordinate is not valid." << endl;
    }
}
const int &BoardVector::operator()(int x,int y)const { /*rvalue*/
    if(x>=0 && x< vctr[0].size() && y>=0 && y< vctr.size()){
      return vctr[x][y];
    }else{
        cout << "This coordinate is not valid." << endl;
    }
}
/*
bool BoardVector::operator==(const BoardVector & right) {
    int x = vctr[0].size(),y = vctr.size();
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {                                                            ?
            if(this->vctr[i][j] != right.vctr[i][j]){
                return false;
            }
        }
    }
    return true;
}*/

bool BoardVector::move(char direction) {
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

void BoardVector::moveRandom(){
    int moveTo;
    moveTo = rand()%4;
    while(!this->isValid(convertMoveIntToChar(moveTo))){
        moveTo = rand()%4;
    }
    move(convertMoveIntToChar(moveTo));
}

void BoardVector::reset(){
    int index=1,i=0, j = 0,x,y;
    x=vctr[0].size();
    y=vctr.size();
    for (i = 0; i < y ; i++) {
        for (j = 0; j < x; j++) {
            if((*this)(i,j) != 0) {
                (*this)(i,j) = index;
                index++;
            }
        }

    }
    vctr[i-1][j-1] = -1;
}
 