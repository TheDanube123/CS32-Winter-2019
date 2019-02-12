//
//  History.cpp
//  Project1
//
//  Created by Daniel Miller on 14/01/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

#include <iostream>
using namespace std;

#include "History.h"
#include "Arena.h"
#include "globals.h"



History::History(int nRows, int nCols){
    m_rows = nRows;
    m_cols = nCols;
    m_nhist = 0;
}

bool History::record(int r, int c){
    if (r <= 0  ||  c <= 0  ||  r > MAXROWS  ||  c > MAXCOLS)
    {
        return false;
    }
    history[m_nhist] = new histStruct;
    history[m_nhist]->m_rows = r;
    history[m_nhist]->m_cols = c;
    m_nhist++;
    return true;
}


void History::display() const
{
    // Position (row,col) of the arena coordinate system is represented in
    // the array element grid[row-1][col-1]
    char grid[MAXROWS][MAXCOLS];
    int r, c;
    
    // Fill the grid with dots
    for (r = 0; r < m_rows; r++)
        for (c = 0; c < m_cols; c++)
            grid[r][c] = '.';
    
    for (int k = 0; k < m_nhist; k++)
    {
        const struct histStruct* hs = history[k];
        char& gridChar = grid[hs->m_rows-1][hs->m_cols-1];
        switch (gridChar)
        {
            case '.':  gridChar = 'A'; break;
            case 'Z':  gridChar = 'Z'; break;
            default:   gridChar++; break;
        }
    }
    
    // Draw the grid
    clearScreen();
    for (r = 0; r < m_rows; r++)
    {
        for (c = 0; c < m_cols; c++)
            cout << grid[r][c];
        cout << endl;
    }
    cout << endl;
    
}
    
History::~History(){
    for (int k = 0; k < m_nhist; k++)
        delete history[k];
}


