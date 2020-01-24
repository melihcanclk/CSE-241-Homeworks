#ifndef BOARDARRAY2D_H
#define BOARDARRAY2D_H
#include "AbstractClass.h"

class BoardArray2D:public Puzzle::AbstractClass {

    public:
        BoardArray2D();
        void readFromFile(char * argv)override;
        void reset()override;
        void setSize(int coordinates[2])override;
        const int & operator()(int index1,int index2)const override;
        int & operator()(int index1,int index2)override;
        ~BoardArray2D();
    private:
        int **arr;
};
#endif 