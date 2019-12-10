#ifndef ABSTRACTCLASS_H
#define ABSTRACTCLASS_H
#include <string>
class AbstractClass {
    public:
    bool isValid(const char direction);
    virtual void print();         //changes
    virtual void readFromFile(char* argv)=0;  //changes
    virtual void writeToFile()=0;   //changes
    virtual void reset()=0;         //changes
    virtual void setSize(int coordinates[2]);   //changes
    virtual bool move(char direction);//changes
    virtual bool isSolved();           //changes
    virtual const int & operator()(int index1,int index2)const =0;
    virtual int & operator()(int index1,int index2)=0;
    virtual bool operator==(const AbstractClass & right);         
    void shuffle(int n); 
    static char reverse(char movement);
    protected:
    int numberOfBoards;
    char lastMove;
    int numberOfMoves;
    int size[2];
    void findCoordinates(int number,int coordinates[2]);
    virtual void moveRandom();
    void calculateXandY(std::string argv,int coordinates[2]);
    int getNumberOfBoards();//doesnt change
    char getLastMove();     //doesnt change
    int getNumberOfMoves(); //doesnt change
    int convertStringToInt(std::string str);
    char convertMoveIntToChar(int moveTo);      // Convert 1,2,3,4 to U,D,L,R
    
};

#endif