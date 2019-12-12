#include <iostream>
#include <fstream>
#include "BoardArray1D.h"

using namespace std;

void BoardArray1D::setSize(int coordinates[2]){
    int index=1;
    AbstractClass::setSize(coordinates);
    (arr) = new int[size[1] * size[0]];
    for(int i = 0; i < size[1]; ++i){
        for(int j = 0; j < size[0]; ++j){
            (*this)(j,i) = index;
            index++;
        }
    }
    arr[(size[0] * size[1]) -1] = -1;
}


void BoardArray1D::readFromFile(char *argv){
    if(size[0] >0 || size[1]){
        delete [] arr;
    }
    int coordinates[2],k=0;
    ifstream infile(argv);
    if(!infile.is_open()){
        cout << "File couldn't be open." << "\n";
    }
    string pString;
    calculateXandY(argv,coordinates);
    setSize(coordinates);
    for (int i = 0; i < coordinates[1] * coordinates[0]; i++) {
        infile >> pString;
        arr[i] = convertStringToInt(pString);
    }
}

const int &BoardArray1D::operator()(int x,int y)const { /*rvalue*/
    if(x>=0 && x< size[0] && y>=0 && y< size[1]){
        return arr[size[0] * y + x];
    }else{
        cout << "This coordinate is not valid." << endl;
    }
}
int &BoardArray1D::operator()(int x,int y) {              /*lvalue*/
    if(x>=0 && x<size[0] && y>=0 && y< size[1]){
        return arr[size[0] * y + x];
    }else{
        cout << "This coordinate is not valid." << endl;
    }
}

void BoardArray1D::reset(){
    AbstractClass::reset();
    arr[(size[0] * size[1]) -1] = -1;
}

BoardArray1D::~BoardArray1D() {
    delete [] arr;
}

BoardArray1D::BoardArray1D()= default;
