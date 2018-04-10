#include <iostream>

#include "cell.h"

using namespace std;

Cell::Cell( int row, int col, int distance, int f, Cell * parent)
{
    this->row = row;
    this->col = col;
    this->distance = distance;
    this->f = f;
    this->parent = parent;
}

int Cell::getRow() { return row; }
int Cell::getCol() { return col; }
int Cell::getDistance() { return distance; }
int Cell::getF() { return f; }
Cell* Cell::getParent() { return parent; }

///brise pointer na roditelja
Cell::~Cell() { delete parent; }


