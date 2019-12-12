/*------------------GEBZE TECHNICAL UNIVERSITY---------------------*
*                    Name : Melihcan Çilek                         *
*                    Student Number : 1801042092                   *
*------------------------------------------------------------------*/
#include "BoardVector.h"
#include "BoardArray2D.h"
#include "BoardArray1D.h"
#include <iostream>
#include <cstring>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

//Setting numberOfBoards static variable to 0
int Puzzle::AbstractClass::numberOfBoards =0 ;

int main(){
    typedef Puzzle::AbstractClass* AbsPtr;
    auto * absPtr = new AbsPtr[3];
    //Initiliazing AbstractClass ** to boards
    absPtr[0] = new BoardVector;
    absPtr[1] = new BoardArray2D;
    absPtr[2] = new BoardArray1D;

    cout << "Number Of board created so far is "<< Puzzle::AbstractClass::getNumberOfBoards()<< endl;
    //Names of files
    char *fileName[30];

    for(int i=0 ;i<Puzzle::AbstractClass::getNumberOfBoards();i++){
        cout << "Please enter name of " << i+1 << " th board(with txt name extention):";
        cin >> fileName[i] ;
    }
    //Reading Files
    //You have to add file names if you want to read more boards
    for(int i=0 ;i<Puzzle::AbstractClass::getNumberOfBoards();i++){
        absPtr[i]->readFromFile(fileName[i]);
    }
    for(int i=0;i<Puzzle::AbstractClass::getNumberOfBoards();++i){
        absPtr[i]->print();
        cout << endl;
    }
    //Moving all boards
    for(int i=0;i<Puzzle::AbstractClass::getNumberOfBoards();++i){
        absPtr[i]->move('l');
        absPtr[i]->move('u');
        absPtr[i]->move('l');
        absPtr[i]->move('r');
    }
    for(int i=0;i<Puzzle::AbstractClass::getNumberOfBoards();++i){
        absPtr[i]->print();
        cout << endl;
    }
    //writing boards to fileName variables
    //You have to add file names if you want to read more boards
    for(int i=0 ;i<Puzzle::AbstractClass::getNumberOfBoards();i++){
        absPtr[i]->writeToFile(fileName[i]);
    }

    //Controlling if boards solved or not
   for(int i=0;i<Puzzle::AbstractClass::getNumberOfBoards();i++){
       if(absPtr[i]->isSolved()){
            cout << i << " index board is solved" << endl;
       }else{
           cout << i << " index board is not solved" << endl;
       }
   }

    //Controlling if any of
    for(int i=0;i<Puzzle::AbstractClass::getNumberOfBoards();i++){
        for(int j = i+1; j<Puzzle::AbstractClass::getNumberOfBoards();j++){
            if(*absPtr[j] == *absPtr[i]){
                cout << i << " index equal to " << j << " index." << endl;
            }else{
                cout << i << " index not equal to " << j << " index." << endl;
            }
        }
    }
    //we can send how many boards we want to compare to the function.
    //we can use Puzzle::AbstractClass::getNumberOfBoards() to compare all boards created so far.
    if(isValid(absPtr,3)){
        cout << "Board sequence is valid"<< endl;
    }else{
        cout << "Board sequence is not valid"<< endl;
    }
    
    delete [] absPtr;
}
