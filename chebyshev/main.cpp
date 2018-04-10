#include <iostream>
#include <cstdlib>
#include <fstream>

#include "maze.h"

using namespace std;

int main()
{
    int NR,NC;
    string file_name;
    ifstream info("info.txt");
    if( info.is_open()==0 ) return 0;
    info >> NR >> NC >> file_name;
    
	Maze  m(NR,NC,file_name);
    m.InitialSearch(); /// nadi put od S do E

    return EXIT_SUCCESS;
}

/*
Koristimo deque STL container za priority deque za A*.
h=Manhattan distance od trenutne pozicije do END.

Maze istrazujemo t.d. dodajemo FREE cvorove okolo trenutne pozicije u otvorenu 'listu'.
Jednom kad ti cvorovi dodu na vrh reda izbacujemo ih te ih dodajemo u zatvorenu 'listu' kako bi nasli put kad dodemo do kraja.
Istrazivanje je gotovo kad dodemo do END ili kad vise nemamo cvorova u otvorenoj 'listi'(sto znaci da nemamo rjesenja).
*/
