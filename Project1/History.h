//
//  History.h
//  Project1
//
//  Created by Daniel Miller on 14/01/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

#ifndef History_h
#define History_h

class Arena;
#include "globals.h"

struct histStruct{
    int m_rows;
    int m_cols;
};

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
    ~History();
    
    
private:
    struct histStruct *history[MAXZOMBIES];
    int m_rows;
    int m_cols;
    int m_nhist;
};

#endif /* History_h */
