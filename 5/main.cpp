#include "AbstractClass.h"
#include "BoardVector.h"

int main(int argc,char **argv){
    BoardVector bv(3);
    AbstractClass * c = &bv;
    bv.print();
    bv.move('L');
    c->print();
}