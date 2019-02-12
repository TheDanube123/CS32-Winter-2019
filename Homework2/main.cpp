//
//  main.cpp
//  Homework3
//
//  Created by Daniel Miller on 05/02/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

#include <iostream>
#include "mazestack.cpp"
using namespace std;

int main()
{
    string maze[6] = {
        "XXXXXX",
        "X....X",
        "X....X",
        "X....X",
        "X....X",
        "XXXXXX"
    };
    


    
    if (pathExists(maze,6,6,1,1,4,4))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}
