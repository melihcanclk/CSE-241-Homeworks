#ifndef BOARDARRAY1D_H
#define BOARDARRAY1D_H

#include "AbstractClass.h"

class BoardArray1D : public Puzzle::AbstractClass{
    public:
        BoardArray1D();
        void readFromFile(char * argv)override;
        void reset()override;
        void setSize(int coordinates[2])override;
        const int & operator()(int index1,int index2)const override;
        int & operator()(int index1,int index2)override;

    private:
     int * arr{};
};


#endif //BOARDARRAY1D_H
