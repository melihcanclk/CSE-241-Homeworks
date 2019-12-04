#ifndef BOARDVECTOR_H
#define BOARDVECTOR_H
#include "AbstractClass.h"
#include <vector>

using std::vector;

class BoardVector:public AbstractClass {

    public:
    BoardVector(){}
    BoardVector(int size);
    void print()override;         
    void readFromFile(char * argv)override;  
    /*void writeToFile()override;   
    void reset()override;         
    void setSize(int size)override;   
    */
   bool move(char direction)override;
   /*
    void isSolved()override;          
    friend bool operator==(const BoardVector & left,const BoardVector & right);*/
    bool isValid(const char direction)override;
    void findCoordinates(int number,int coordinates[2])override;
    const int & operator()(int index1,int index2)const override;
    int & operator()(int index1,int index2)override;
    private:
    vector<vector<int>> vctr;
};
#endif 