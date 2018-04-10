#include <ctime>
#include <random>
#include <iostream>
#include <fstream>
#include <set>
#include <utility>
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
    int OBSTICLES;       /// broj polja s preprekama
    int ROWS;
    int COLS;
    int startX, startY;
    int endX, endY;
    cout << "ROWS = ";
    cin >> ROWS;
    cout << "COLS = ";
    cin >> COLS;
    cout << "OBSTICLES = ";
    cin >> OBSTICLES;
    cout << "startX = ";
    cin >> startX;
    cout << "startY = ";
    cin >> startY;
    cout << "endX = ";
    cin >> endX;
    cout << "endY = ";
    cin >> endY;
            
    std::default_random_engine r_engine;  // Generator slucajnih brojeva
    r_engine.seed( std::time(nullptr) );  // seed = trenutno vrijeme, osigurava da ne generiramo uvijek isti niz brojeva
    uniform_int_distribution<> r(0,ROWS-1);
    uniform_int_distribution<> c(0,COLS-1);
    
    for(int i=1; i<=20; i++)
    {
        set< pair<int,int> > skup;
        pair<int,int> pocetak(startX,startY);
        pair<int,int> kraj(endX,endY);
        
        skup.insert(pocetak);
        skup.insert(kraj);
        while(skup.size() != OBSTICLES+2)
            skup.insert( pair<int,int> ( r(r_engine),c(r_engine) ) );  
        skup.erase(pocetak);
        skup.erase(kraj);
        
        string s; 
        s += "randomMaze" + toString(i) + ".txt";
        ofstream file(s);
        if(file.is_open() == 0)
        {
            cout << "Unable to open file " << s << endl;
            return -1;
        }
        for(int m=0; m<ROWS; m++)
        {
            for(int n=0; n<COLS; n++)
            {
                pair<int,int> temp(m,n);
                if(m==startX && n==startY) file << "4 ";
                else if(m==endX && n==endY) file << "8 ";
                else if(skup.find(temp) != skup.end()) file << "5 ";
                else file << "1 ";
            }
            file << endl;
        }
    }
    
    return 0;
}
