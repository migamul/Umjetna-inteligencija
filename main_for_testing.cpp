#include <iostream>
#include <cstdlib>
#include <fstream>
#include "maze.h"
#include <string>

using namespace std;

// funkcija to_string ne radi na windowsima
string toString(int n)
{
    if(n == 1) return "1";
    if(n == 2) return "2";
    if(n == 3) return "3";
    if(n == 4) return "4";
    if(n == 5) return "5";
    if(n == 6) return "6";
    if(n == 7) return "7";
    if(n == 8) return "8";
    if(n == 9) return "9";
    if(n == 10) return "10";
    if(n == 11) return "11";
    if(n == 12) return "12";
    if(n == 13) return "13";
    if(n == 14) return "14";
    if(n == 15) return "15";
    if(n == 16) return "16";
    if(n == 17) return "17";
    if(n == 18) return "18";
    if(n == 19) return "19";
    if(n == 20) return "20";
}

int main()
{
    int NR = 25,NC = 25;
    string file_name;
    for(int i=1; i<=20; i++)
    {
        file_name = "testTxt/randomMaze" + toString(i) + ".txt";
        cout << endl << endl << file_name << endl;
        Maze m(NR,NC,file_name);
        m.InitialSearch(END,START); ///nadi put od S do E
    }

    return EXIT_SUCCESS;
}

/*
Koristimo deque STL container za priority deque za A*.
h=Manhattan distance od trenutne pozicije do END.

Maze istrazujemo t.d. dodajemo FREE cvorove okolo trenutne pozicije u otvorenu 'listu'.
Jednom kad ti cvorovi dodu na vrh reda izbacujemo ih te ih dodajemo u zatvorenu 'listu' kako bi nasli put kad dodemo do kraja.
Istrazivanje je gotovo kad dodemo do END ili kad vise nemamo cvorova u otvorenoj 'listi'(sto znaci da nemamo rjesenja).
*/
