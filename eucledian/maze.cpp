#include <cstdlib>
#include <iostream>
#include <math.h>
#include <deque>
#include <string>
#include <fstream>

#include "maze.h"

using namespace std;

Maze::Maze(int NR, int NC, string file_name) : TABLEROW(NR), TABLECOL(NC) ///stvara maze (tj, 2d polje) iz .txt file (pisano u Notepadu)
{
    ifstream mazeFile;
    mazeFile.open( file_name, ios::in );
    if ( mazeFile.is_open() )
    {
        mazeMap = (int**)malloc(NR*sizeof(int*));
        for(int i=0; i<NR; i++)
            mazeMap[i] = (int*)malloc(NC*sizeof(int));

        mazeRoute = (int**)malloc(NR*sizeof(int*));
        for(int i=0; i<NR; i++)
            mazeRoute[i] = (int*)malloc(NC*sizeof(int));

		///inicijalizira mazove
		for ( int i = 0; i < TABLEROW; i++ )
        {
			for ( int j = 0; j < TABLECOL; j++ )
			{
				mazeFile >> mazeMap [i][j];
				mazeRoute [i][j] = mazeMap [i][j];

				///zabiljezava START i END
				if ( mazeMap[i][j] == START )
                {
					startRow = i;
					startCol = j;
				}
				else if ( mazeMap[i][j] == END)
                {
					endRow = i;
					endCol = j;
				}
            }
        }
		mazeFile.close();
    }
    else ///u slucaju neke greske
    {
        cout << "Error:Unable to open file";
    }
}

void Maze::InitialSearch()
{
    ///fja f ... posto je ona def kao f=g+h, a u pocetku nam je g=0,pa f=h ... h=Manhattan distance
    //int f = abs( startRow - endRow ) + abs( startCol - endCol ); ///Manhattan
    int f = sqrt(((startRow-endRow)*(startRow-endRow))+((startCol-endCol)*(startCol-endCol))); ///Eucledian
    //int f = max(abs(endRow - startRow),abs(endCol - startCol)); ///Cheby

    //int f = 0;

    ///stavlja pocetnu poziciju(START) u otvorenu listu(red)
    openDeque.push_back( new Cell( startRow, startCol, 0, f, 0 ) );

    ///postavljamo ga da je taj cvor(mjesto) tipa OPEN
	mazeRoute[startRow][startCol] = OPEN;

	///trow i tcol su trenutne pozicije
	int trow = 0;
	int tcol = 0;

	///upit dal smo dosli do kraja(END) ... ako false=nismo,idemo dalje ... ako true=dosli smo do kraja,gotova igra
	bool win = false; ///prvo ga postavimo na false jer smo tek na pocetku

	///dalje trazimo izlaz(END) ... znaci ili cemo doc do te tocke ili uopce nema rjesenja
	while( openDeque.size() != 0 )
    {
		///ucitavamo trenutnu poziciju(i to t.d. izbacujemo iz otvorene 'liste')
		trow = openDeque.front()->getRow();
		tcol = openDeque.front()->getCol();

		mazeRoute[trow][tcol] = CLOSED; ///sada smo trenutnu poziciju otvorili i istrazili pa ju postavljamo na CLOSED (necemo ju vise gledat)

        ///gledamo jel ta pozicija trazeni END
		if( mazeMap[trow][tcol] == END )
		{
			closedDeque.push_back( openDeque.front() );
			openDeque.pop_front();
			while(openDeque.size() && isClosed( openDeque.front()->getRow(),openDeque.front()->getCol() ) ) openDeque.pop_front();
			win = true; ///ako je stavljamo true i izlazimo van
			break;
		}
		else ///znaci trenutna pozicija nije cilj pa gledamo okolne,susjedne celije (ali samo gore,dolje,lijevo,desno. nema dijagonala)
        {
			closedDeque.push_back( openDeque.front() );
			openDeque.pop_front(); 				///micemo prvi element u dequeu
            while(openDeque.size() && isClosed( openDeque.front()->getRow(),openDeque.front()->getCol() ) ) openDeque.pop_front();

			AStar( trow, tcol );
		}
	}

	if ( !win ) { cout << "This maze has no solution!" << endl; } ///ako nikad ne nademo kraj samo saljemo poruku da labirint nema rjesenja

	//Print();
	PrintToFile();
}

void Maze::AStar( int row, int col )
{

	int distance = ( closedDeque.back()->getDistance() ) + 1; 	///Distance sljedece Cell ce biti +1 od trenutne Cell koja je dodana u zavorenu listu
	Cell * parent = closedDeque.back();					///Parent nam je prijasnji Cell (iz kojeg smo dosli)

	///Lijevo od trenutnog polozaja
	if ( ( col - 1 > -1 ) && mazeRoute[row][col - 1] != BLOCK && mazeRoute[row][col - 1] != CLOSED)
    {
		mazeRoute[row][col - 1] = OPEN;
        AStarSort( row, col - 1, distance, parent );
	}

	///Iznad trenutnog polozaja
	if ( ( row - 1 > -1 ) && mazeRoute[row - 1][col] != BLOCK && mazeRoute[row - 1][col] != CLOSED)
	{
		mazeRoute[row - 1][col] = OPEN;
        AStarSort( row - 1, col, distance, parent );
	}

	///Desno od trenutnog polozaja
	if ( ( col + 1 < TABLECOL ) && mazeRoute[row][col + 1] != BLOCK && mazeRoute[row][col + 1] != CLOSED)
    {
		mazeRoute[row][col + 1] = OPEN;
        AStarSort( row, col + 1, distance, parent );
	}

	///Ispod trenutnog polozaja
	if ( ( row + 1 < TABLEROW ) && mazeRoute[row + 1][col] != BLOCK && mazeRoute[row + 1][col] != CLOSED)
    {
		mazeRoute[row + 1][col] = OPEN;
        AStarSort( row + 1, col, distance, parent );
	}
}

void Maze::AStarSort( int row, int col, int distance, Cell * parent )
{
	///A* koristi prioritetni red pa dodajemo elemente u deque ovisno o prioritetu
	int g = distance; ///za fju g stavimo da je cijena od jednog cvora do drugog(to je zapravo pomak,te svaki pomak vrijedi 1)
	//int h = abs( endRow - row ) + abs( endCol - col ); ///Manhattan distance
	int h = sqrt(((row-endRow)*(row-endRow))+((col-endCol)*(col-endCol))); ///Eucledian
	//int h = max(abs(endRow - row),abs(endCol - col)); ///Cheby

	int f = g + h;

	//int f = g;

	bool insertSuccess = false;

	///Koristimo insertion sort da bi dodali elemente u deque ovisno o najvecem prioritetu (tj, najmanjoj vrijednosti od f)
	if ( openDeque.size() == 0 )
    {
		openDeque.push_back( new Cell( row, col, distance, f, parent ) );
	}
	else
    {
		deque<Cell *>::iterator it;
		for ( it = openDeque.begin(); it != openDeque.end(); it++ )
			if ( f < (*it)->getF() )
            {
				openDeque.insert( it, new Cell( row, col, distance, f, parent ) );
				insertSuccess = true;
				break;
			}

		if ( !insertSuccess ) openDeque.push_back( new Cell( row, col, distance, f, parent ) );
	}
}

bool Maze::isClosed(int r, int c)
{
    deque<Cell *>::iterator it;
    for ( it = closedDeque.begin(); it != closedDeque.end(); it++ )
        if( r == (*it)->getRow() && c == (*it)->getCol())  return true;
    return false;
}

///funkcija koja zapravo ispisuje maze(zajedno s zidovima,dobivenim putom i ostalim slobodnim mjestima)
void Maze::Print()
{
	///gradi put t.d. se penje po stablu(po roditeljima) u rikverc,od END
	Cell *treeIterator;
	deque<Cell *> path;
	///sece po zatvorenoj listi i to t.d. uzima roditelje(put unatrag) sve dok ne dode do STARTA koji nema roditelja(=0)
	for ( treeIterator = closedDeque.back(); treeIterator->getParent() != 0; treeIterator = treeIterator->getParent() )
		path.push_front( treeIterator ); ///puni listu put

	path.push_front( treeIterator ); ///ovdje jos ubacuje startnu poziciju(jer u for petlji se zaustavi na startu,ali ga ne ubaci

	///crta maze
	cout << "\nMaze:\n" << endl;

    cout <<"°";
	for(int i = 0; i < TABLECOL; i++)   cout << "°";
	cout <<"°";
    cout << "\n";

	for ( int i = 0; i < TABLEROW; i++ )
    {
        cout << "°";
        for ( int j = 0; j < TABLECOL; j++ )
        {
			if( mazeMap [i][j] == BLOCK ) cout << "°"; ///zidovi
            else if(mazeMap [i][j] == START) cout << "S"; ///S=START
            else if( mazeMap [i][j] == END ) cout << "E"; ///E=END
            else
            {
                 bool on_the_path = false; ///prvo postavimo var "na putu" na false,pa ako nade neku poziciju koja je onda postavi na true
                 for( unsigned int k = 0; k < path.size(); k++ ) ///prolazimo kroz listu(red) put
                 {
                      if( path[k]->getRow() == i && path[k]->getCol() == j ) on_the_path = true;
                 }
                 if( on_the_path ) cout << "."; ///ako je to dio puta onda .
                 else cout << " ";      ///ako nije ostavi prazno
            }
        }
        cout << "°";
        cout << "\n";
    }

    cout <<"°";
    for(int i = 0; i < TABLECOL; i++)   cout << "°";
    cout <<"°";
    cout << "\n";

    ///put po koordinatama (ovdje onaj ispis vrijednosti po koordinatama)
    /*
	cout << "\nPath: \n" << endl;
	//cout << "START=";
	for ( unsigned int k = 0; k < path.size(); k++ )
    {
         //cout << "(" << ( path[k] -> getCol() ) << "," <<  TABLE - ( path[k] -> getRow() ) - 1 << ")";
         //if ( k == path.size() - 1 ) cout << "END=";
         if ( k == 0 ) cout << "(" << (path[k] -> getRow() +1) << "," << (path[k] -> getCol() +1) << ")" << ",f=" << (path[k] -> getF()) << ",g=" << (path[k] -> getDistance()) << ",h=" << (abs(endRow - path[k] -> getRow()) + abs(endCol - path[k] -> getCol()));
         if ( k != 0 && k != path.size() - 1 )
         cout << "(" << (path[k] -> getRow() +1) << "," << (path[k] -> getCol() +1) << ")" << ",f=" << (path[k] -> getF()) << ",g=" << (path[k] -> getDistance()) << ",h=" << (abs(endRow - path[k] -> getRow()) + abs(endCol - path[k] -> getCol()));
         if ( k == path.size() - 1 ) cout << "  (" << (path[k] -> getRow() +1) << "," << (path[k] -> getCol() +1) << ")" << ",f=" << (path[k] -> getF()) << ",g=" << (path[k] -> getDistance()) << ",h=" << (abs(endRow - path[k] -> getRow()) + abs(endCol - path[k] -> getCol()));
         //cout <<"\n";
         if( k < path.size() - 1 ) cout << " -> ";

         //cout << "\n";
    }
    cout << endl;
    */
}

void Maze::PrintToFile()
{
    ofstream out("output.txt");

	///gradi put t.d. se penje po stablu(po roditeljima) u rikverc,od END
	Cell *treeIterator;
	deque<Cell *> path;
	///sece po zatvorenoj listi i to t.d. uzima roditelje(put unatrag) sve dok ne dode do STARTA koji nema roditelja(=0)
	for ( treeIterator = closedDeque.back(); treeIterator->getParent() != 0; treeIterator = treeIterator->getParent() )
		path.push_front( treeIterator ); ///puni listu put

	path.push_front( treeIterator ); ///ovdje jos ubacuje startnu poziciju(jer u for petlji se zaustavi na startu,ali ga ne ubaci

	for ( int i = 0; i < TABLEROW; i++ )
    {
        for ( int j = 0; j < TABLECOL; j++ )
        {
			if( mazeMap[i][j] == BLOCK ) out << "1 "; ///zidovi
            else if(mazeMap[i][j] == START) out << "2 "; ///S=START
            else if( mazeMap[i][j] == END ) out << "3 "; ///E=END
            else
            {
                 bool on_the_path = false; ///prvo postavimo var "na putu" na false,pa ako nade neku poziciju koja je onda postavi na true
                 for( unsigned int k = 0; k < path.size(); k++ ) ///prolazimo kroz listu(red) put
                      if( path[k]->getRow() == i && path[k]->getCol() == j ) on_the_path = true;
                 if( on_the_path ) out << "4 "; ///ako je to dio puta onda .
                 else if( mazeRoute[i][j] == 7) out << "5 ";      ///ako nije ostavi prazno
                 else out << "0 ";
            }
        }
        out << endl;
    }
}

Maze::~Maze()
{
    for(int i=0; i<TABLEROW; i++)
        free(mazeMap[i]);
    free(mazeMap);
    for(int i=0; i<TABLEROW; i++)
        free(mazeRoute[i]);
    free(mazeRoute);
}

