#include <iostream>
#include <fstream>
#include "BoardArray2D.h"

using namespace std;

void BoardArray2D::setSize(int coordinates[2]){
    int index=1;
    AbstractClass::setSize(coordinates);
    (arr) = new int*[size[1]];
    for(int i = 0; i < size[1]; ++i)
        arr[i] = new int[size[0]];
    for(int i = 0; i < size[1]; ++i){
        for(int j = 0; j < size[0]; ++j){
            arr[i][j] = index;
            index++;
        }
    }
    arr[size[1]-1][size[0]-1] = -1;
}


void BoardArray2D::readFromFile(char *argv){
    if(size[0] >0 || size[1]){
        for(int i = 0; i < size[1]; i++)
            delete [] arr[i];
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
}

const int &BoardArray2D::operator()(int x,int y)const { /*rvalue*/
    if(x>=0 && x< size[0] && y>=0 && y< size[1]){
        return arr[y][x];
    }else{
        cout << "This coordinate is not valid." << endl;
    }
}
int &BoardArray2D::operator()(int x,int y) {              /*lvalue*/
    if(x>=0 && x<size[0] && y>=0 && y< size[1]){
        return arr[y][x];
    }else{
        cout << "This coordinate is not valid." << endl;
    }
}

void BoardArray2D::reset(){
    AbstractClass::reset();
    arr[size[1]-1][size[0]-1] = -1;
}

BoardArray2D::BoardArray2D() {

}
