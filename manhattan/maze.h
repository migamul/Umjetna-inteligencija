#include <iostream>
#include <deque>

#include "cell.h"

using namespace std;

///Definicije razlicitih stanja celija u tablici
static const int FREE 		= 1; 	///Prazna celija,moguce kretanje
static const int START 		= 4;	///Pocetna pozicija(START)
static const int BLOCK 		= 5;	///Zid,nemoguce kretanje
static const int OPEN 		= 6;	///Cvor dodan u otvorenu listu,ali nije jos istrazen
static const int CLOSED 	= 7;	///Nakon sto ga pogledamo stavljamo ga u zatvorenu listu i istrazujemo oko njega
static const int END        = 8;    ///Krajnja pozicija(END)


class Maze
{
private:
    int TABLEROW, TABLECOL;
    int** mazeMap;		///2D polje koje biljezi pocetni,dobiveni labirint
    int** mazeRoute; 	///2D polje koje biljezi otvorene i zatvorene cvorove

    int startRow, startCol;     ///Pocetna pozicija
    int endRow, endCol;			///Krajnja pozicija

    ///deques su implementirani jer se koriste kao red i stog->pogledaj c++ refrence ( nije mi htjelo s obicnim queuom)
    deque<Cell *> openDeque;
    deque<Cell *> closedDeque;

public:
    Maze(int NR, int NC, string file_name);
    void InitialSearch(); ///tu cemo inicijalizirati maze, i koristiti AStar i AStarSort i Print
    ~Maze();
private:
    void AStar( int, int );
    void AStarSort( int, int, int, Cell * );
    bool isClosed(int r, int c);
    void Print();
    void PrintToFile();

};


