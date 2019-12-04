#include "AbstractClass.h"
#include "BoardVector.h"

int main(){
    BoardVector bv(3);
    AbstractClass * c = &bv;
    c->print();
}