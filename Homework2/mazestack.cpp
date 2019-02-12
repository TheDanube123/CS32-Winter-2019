//
//  mazestack.cpp
//  Homework2
//
//  Created by Daniel Miller on 05/02/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

using namespace std;
#include <stack>
#include <iostream>

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    stack<Coord> coordStack;
    coordStack.push(Coord(sr,sc));
    maze[sr][sc] = '#';
    while(!(coordStack.empty())){
        Coord curr = coordStack.top(); // why does this work
        coordStack.pop();
        int currR = curr.r();
        int currC = curr.c();
        bool isEndpoint = (currR == er && currC == ec);
        if (isEndpoint){
            return true;
        }
        if (maze[currR-1][currC] == '.'){               //NORTH
            maze[currR-1][currC] = '#';
            coordStack.push(Coord(currR-1,currC));
            }
        if (maze[currR+1][currC] == '.'){               //SOUTH
            maze[currR+1][currC] = '#';
            coordStack.push(Coord(currR+1,currC));
            }
        if (maze[currR][currC-1]== '.'){                //WEST
            maze[currR][currC-1] = '#';
            coordStack.push(Coord(currR,currC-1));
            }
        if (maze[currR][currC+1]=='.'){                 //EAST
            maze[currR][currC+1] = '#';
            coordStack.push(Coord(currR,currC+1));
            }
    }
    return false;
}

int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X....X...X",
        "X.XX.XX..X",
        "XXX....X.X",
        "X.XXX.XXXX",
        "X.X...X..X",
        "X...X.X..X",
        "XXXXX.X.XX",
        "X........X",
        "XXXXXXXXXX"
    };
    
    if (pathExists(maze, 10,10, 3,5, 8,8))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}

//First 12 (r,c) popped off stack:
// (3,5),(3,6),(3,4),(3,3),(2,4),(1,4),(1,3),(1,2),(1,1),(2,1),(4,5),(5,5)


