#include <iostream>

using namespace std;

///sadrzi koordinate i informacije o celijama/pozicijama u labirintu
class Cell
{
private:
    int row, col;    ///pozicija "igraca" ... redak i stupac u tablici
    int distance;		///udaljenost od STARTA ... znaci koliko koraka smo napravili od STARTA da bi dosli do tren pozicije
    int f;				///f(n)=g(n)+h(n) , g(n)=distance , h(n)=Manhattan distance
    Cell * parent;		///roditelj od celije(od kud smo dosli)
public:
    ///konstruktor za A*
    Cell( int row, int col, int distance, int f, Cell * parent );
    ///destruktor
    ~Cell();

    int getRow();
    int getCol();
    int getDistance();
    int getF();
    Cell * getParent();
};











