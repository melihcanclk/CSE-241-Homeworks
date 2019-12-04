#ifndef BOARDVECTOR_H
#define BOARDVECTOR_H
#include "AbstractClass.h"
#include <vector>

using std::vector;

class BoardVector:public AbstractClass {

    public:
    BoardVector(int size);
    void print()override;         
    void readFromFile(char * argv)override;  
    /*void writeToFile()override;   
    void reset()override;         
    void setSize(int size)override;   
    void move(char direction)override;
    void isSolved()override;          
    void operator()(int index1,int index2)override;
    friend bool operator==(const BoardVector & left,const BoardVector & right);*/
    private:
    vector<vector<int>> vctr;
};
#endif 