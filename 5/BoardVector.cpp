#include <iostream>
#include <fstream>
#include "BoardVector.h"

using namespace std;

BoardVector::BoardVector(int size){
    int index=1,i = 0, j = 0;
    for ( i = 0; i < size; i++) {
        vector<int> temp;
        for ( j = 0; j < size; j++) {
            temp.push_back(index);
            index++;
        }
        vctr.push_back(temp);
    }
    vctr[j-1][i-1] = -1;           //overloadladıktan sonra () ile yap
}


void BoardVector::print(){
    int x = vctr[0].size(),y = vctr.size();
    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++) {
            if(vctr[i][j] == -1) {           //overloadladıktan sonra () ile yap
                cout << "bb";
            }else if(vctr[i][j] / 10 == 0) {
                cout << "0" << vctr[i][j];  
            }else if(vctr[i][j] / 10 >= 1){          //overloadladıktan sonra () ile yap
                cout << vctr[i][j];
            }
            cout << " ";
        }
        cout << "\n";
    }
}
void BoardVector::readFromFile(char *argv){
    int coordinates[2],k=0;
    ifstream infile(argv);
    if(!infile.is_open()){
        cout << "File couldn't be open." << "\n";
    }
     string pString;
     calculateXandY(argv,coordinates);
    for (int i = 0; i < coordinates[1]; i++) {
        vector<int> temp;
        for (int j = 0; j < (coordinates[0]/coordinates[1]) +1; j++) {
            infile >> pString;
            temp.push_back(convertStringToInt(pString));
            k++;
        }
        vctr.push_back(temp);
    }
}


bool BoardVector::isValid(const char direction){
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

void BoardVector::findCoordinates(int number,int coordinates[2]){
    for (int i = 0; i < vctr.size(); i++) {
        for (int j = 0; j < vctr[0].size(); j++) {
            if(vctr[i][j] == number){
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
bool BoardVector::move(char direction) {
    int temp,x,y;
    int coordinates[2];
    const int EMPTY = -1;
    findCoordinates(EMPTY,coordinates);
    x=coordinates[0];
    y=coordinates[1];
    if(direction == 'L' || direction == 'l'){
        if(isValid('L')){
            temp = vctr[y][x-1];
            vctr[y][x-1] = vctr[y][x];
            vctr[y][x] = temp;

        }else{
            return false;
        }
    }else if(direction == 'R' || direction == 'r'){
        if(isValid('R')){
            temp = vctr[y][x+1];
            vctr[y][x+1] = vctr[y][x];
            vctr[y][x] = temp;
        }else{
            return false;
        }
    }else if(direction == 'U' || direction == 'u'){
        if(isValid('U')){
            temp = vctr[y-1][x];
            vctr[y-1][x] = vctr[y][x];
            vctr[y][x]= temp;
        }else{
            return false;
        }
    }else if(direction == 'D' || direction == 'd'){
        if(isValid('D')){
            temp =vctr[y+1][x];
            vctr[y+1][x] = vctr[y][x];
            vctr[y][x] = temp;
        }else{
            return false;
        }
    }
    return true;
}