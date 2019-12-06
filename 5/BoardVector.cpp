#include <iostream>
#include <fstream>
#include "BoardVector.h"

using namespace std;

void BoardVector::setSize(int coordinates[2]){
    int index=1,i,j;
    AbstractClass::setSize(coordinates);        //set size
    for ( i = 0; i < coordinates[1]; i++) {
        vector<int> temp;
        for ( j = 0; j < coordinates[0]; j++) {
            temp.push_back(index);
            index++;
        }
        vctr.push_back(temp);
    }
    vctr[i-1][j-1] = -1;         
}

void BoardVector::readFromFile(char *argv){
    if(size[0] >0){
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

const int &BoardVector::operator()(int x,int y)const { /*rvalue*/
    if(x>=0 && x< size[0] && y>=0 && y< size[1]){
      return vctr[x][y];
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


void BoardVector::reset(){
    AbstractClass::reset();
    vctr[size[1]-1][size[0]-1] = -1;
}
 