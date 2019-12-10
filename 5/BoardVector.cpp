#include <iostream>
#include <fstream>
#include "BoardVector.h"

using namespace std;

void BoardVector::setSize(int coordinates[2]){
    int index=1,i,j;
    AbstractClass::setSize(coordinates);        //set size
    for ( i = 0; i < size[1]; i++) {
        vector<int> temp;
        for ( j = 0; j < size[0]; j++) {
            temp.push_back(index);
            index++;
        }
        vctr.push_back(temp);
    }
    vctr[i-1][j-1] = -1;
}

void BoardVector::readFromFile(char *argv){
    if(size[0] >0 || size[1]){
        vctr.clear();
    }
    int coordinates[2],k=0;
        ifstream infile(argv);
        if(!infile.is_open()){
            cout << "File couldn't be open." << "\n";
        }
        string pString;
        calculateXandY(argv,coordinates);
        setSize(coordinates);
}

const int &BoardVector::operator()(int x,int y)const { /*rvalue*/
    if(x>=0 && x< size[0] && y>=0 && y< size[1]){
      return vctr[y][x];
    }else{
        cout << "This coordinate is not valid." << endl;
    }
}
int &BoardVector::operator()(int x,int y) {              /*lvalue*/
    if(x>=0 && x<size[0] && y>=0 && y< size[1]){
        return vctr[y][x];
    }else{
        cout << "This coordinate is not valid." << endl;
    }
}

void BoardVector::reset(){
    AbstractClass::reset();
    vctr[size[1]-1][size[0]-1] = -1;
}
 