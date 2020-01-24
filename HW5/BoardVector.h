#ifndef BOARDVECTOR_H
#define BOARDVECTOR_H
#include "AbstractClass.h"
#include <vector>

using std::vector;

class BoardVector:public Puzzle::AbstractClass {

    public:
        BoardVector();
        void readFromFile(char * argv)override;
        void reset()override;
        void setSize(int coordinates[2])override;
        const int & operator()(int index1,int index2)const override;
        int & operator()(int index1,int index2)override;

    private:
        vector<vector<int>> vctr;
};
#endif 