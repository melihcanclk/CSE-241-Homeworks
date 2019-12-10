#include "AbstractClass.h"
#include "BoardVector.h"
#include "BoardArray2D.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

int main(int argc,char **argv){
    int index = 1;
    typedef AbstractClass* AbsPtr;
    AbsPtr * absPtr = new AbsPtr[3];
    absPtr[0] = new BoardVector;
    absPtr[1] = new BoardArray2D;
    absPtr[2] = new BoardVector;
    BoardVector final;
    char decission = 'S';
    srand(time(nullptr));
    if(argc == 1){
        int size[2] = {0,0};
        while(size[0]<3 && size[1] < 3){
            cout << "Please enter x size of your NPuzzle: ";
            cin >> size[0];
            cout << endl;
            cout << "Please enter y size of your NPuzzle: ";
            cin >> size[1];
            cout << endl;
        }
        for (int i = 0; i < 3; ++i) {
            absPtr[i]->setSize(size);
        }
        for (int i = 0; i < 3; ++i) {
            char lastMove;
            lastMove = absPtr[0]->moveRandom();
            for (int j = 1; j < 3 ; ++j) {
                absPtr[j]->move(lastMove);
            }
        }
        final.setSize(size);        //create finalboard
    }else{
        for (int i = 0; i < 3; ++i) {
            absPtr[i]->readFromFile(argv[1]);
        }
        final.readFromFile(argv[1]);
        final.reset();
    }
    while (decission != 'Q' && decission != 'q') {
        for (int i = 0; i < 3; ++i) {
            absPtr[i]->print();
            cout << "\n";
        }
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
        cout << "Q,q->Quit from the game" << "\n\n\n\n";
        cout << "Selection:";
        cin >> decission;
         if (decission == 'E' || decission == 'e') {
             absPtr[index]->writeToFile();
        } else if (decission == 'O' || decission == 'o') {
            std::string nameOfFile;
            cout << "Please enter name of file: ";
            cin >> nameOfFile;
            nameOfFile = nameOfFile + ".txt";
            char *cstr = new char[nameOfFile.length() + 1];
            strcpy(cstr, nameOfFile.c_str());
            //acp->readFromFile(cstr);
            delete [] cstr;
        } else if (decission == 'Q' || decission == 'q') {
            return 0;
        } else if (decission == 'S' || decission == 's') {
            int coordinates[2];
            //acp->calculateXandY(argv[1],coordinates);
            //acp->shuffle(coordinates[1] * coordinates[0]);
        } else {
             for (int i = index; i < 3; ++i) {
                 absPtr[i]->move(decission);
             }
        }
        index++;
    }

}
