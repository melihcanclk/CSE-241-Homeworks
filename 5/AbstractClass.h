#ifndef ABSTRACTCLASS_H
#define ABSTRACTCLASS_H
class AbstractClass {
    public:
    /*char convertMoveIntToChar(int moveTo);
    void moveRandom();
    bool isValid(const char direction );*/
    virtual void print()=0;         //changes
   /* virtual void readFromFile()=0;  //changes
    virtual void writeToFile()=0;   //changes
    virtual void reset()=0;         //changes
    virtual void setSize(int size)=0;   //changes
    virtual void move(char direction)=0;//changes
    virtual void isSolved()=0;          //changes
    virtual void operator()(int index1,int index2)=0;//changes
    friend bool operator==(const AbstractClass & left,const AbstractClass & right);//doesnt change
    int getNumberOfBoards();//doesnt change
    char getLastMove();     //doesnt change
    int getNumberOfMoves(); //doesnt change*/

    private:
    int numberOfBoards;
    char lastMove;
    int numberOfMoves;

};

#endif