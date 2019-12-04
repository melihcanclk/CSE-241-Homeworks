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