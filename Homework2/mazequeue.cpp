//
//  mazequeue.cpp
//  Homework2
//
//  Created by Daniel Miller on 06/02/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

//
//  mazestack.cpp
//  Homework2
//
//  Created by Daniel Miller on 05/02/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

using namespace std;
#include <queue>
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
    queue<Coord> coordStack;
    coordStack.push(Coord(sr,sc));
    maze[sr][sc] = '#';
    while(!(coordStack.empty())){
        Coord curr = coordStack.front(); // why does this work
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

//First 12 (r,c) popped off queue:
// (3,5),(4,5),(3,4),(3,6),(5,5),(2,4),(3,3),(6,5),(5,4),(1,4),(7,5),(5,3)

//The stack and queue implementations are similar. However, they differ in that the stack goes depth first
//whereas the queue goes breadth first. As can be seen by the values popped, the values are moving in
//concentric circles around the first value whereas the stack explores a path as far as it can go
//and then backtracks.



