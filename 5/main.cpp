#include "AbstractClass.h"
#include "BoardVector.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

int main(int argc,char **argv){
    BoardVector bv;
    BoardVector final;
    AbstractClass * acp = &bv;
    char decission = 'S';
    srand(time(nullptr));
    int counter=0;
    if(argc == 1){
        int size=0;
        while(size<3){
            cout << "Please enter size of your NPuzzle: ";
            cin >> size;
            cout << endl;
        }
        acp->setSize(size);
        acp->shuffle(size * size);
        final.setSize(size);        //create finalboard
    }else{
        acp->readFromFile(argv[1]);
        final.readFromFile(argv[1]);
        final.reset();
    }
    while (decission != 'Q' && decission != 'q') {
        acp->print();
        final.print();
        cout << "Please select one of the selection below:" << "\n";
        cout << "U,u->Moves up." << "\n";
        cout << "D,d->Moves down" << "\n";
        cout << "L,l->Moves left" << "\n";
        cout << "R,r->Moves right" << "\n";
        cout << "I,i->Moves intelligent" << "\n";
        cout << "E,e->Asks a file name and saves the current board \n"
                "configuration as a loadable shape file.." << "\n";
        cout << "O,o->Asks a file name and loads the current board "
                "configuration from the shape file." << "\n";
        cout << "S,s->Shuffle board" << "\n";
        cout << "Q,q->Quit from the game" << "\n";
        cout << "Selection:";
        cin >> decission;
         if (decission == 'E' || decission == 'e') {
            //bv.writeToFile();
        } else if (decission == 'O' || decission == 'o') {
            std::string nameOfFile;
            cout << "Please enter name of file: ";
            cin >> nameOfFile;
            nameOfFile = nameOfFile + ".txt";
            char *cstr = new char[nameOfFile.length() + 1];
            strcpy(cstr, nameOfFile.c_str());
            acp->readFromFile(cstr);
            delete [] cstr;
        } else if (decission == 'Q' || decission == 'q') {
            return 0;
        } else if (decission == 'S' || decission == 's') {
            int coordinates[2];
            acp->calculateXandY(argv[1],coordinates);
            acp->shuffle(coordinates[1] * coordinates[0]);
        } else {
            acp->move(decission);
        }
    }

}