#ifndef ABSTRACTCLASS_H
#define ABSTRACTCLASS_H
#include <string>
class AbstractClass {
    public:
    virtual bool isValid(const char direction )=0;
    virtual void print()=0;         //changes
    virtual void readFromFile(char* argv)=0;  //changes
    /*virtual void writeToFile()=0;   *///changes
    virtual void reset()=0;         //changes
    virtual void setSize(int size)=0;   //changes
    virtual bool move(char direction)=0;//changes
    //virtual void isSolved()=0;           //changes
    virtual const int & operator()(int index1,int index2)const =0;
    virtual int & operator()(int index1,int index2)=0;
    //virtual bool operator==(const AbstractClass & right)=0;           //?
    virtual void findCoordinates(int number,int coordinates[2])=0;
    virtual void moveRandom()=0;  
    void shuffle(int n); 
    void calculateXandY(std::string argv,int coordinates[2]);
    protected:
    int numberOfBoards;
    char lastMove;
    int numberOfMoves;

    int getNumberOfBoards();//doesnt change
    char getLastMove();     //doesnt change
    int getNumberOfMoves(); //doesnt change
    int convertStringToInt(std::string str);
    char convertMoveIntToChar(int moveTo);      // Convert 1,2,3,4 to U,D,L,R
    char reverse(char input);
    
};

#endif