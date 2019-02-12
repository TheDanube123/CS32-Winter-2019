//
//  main.cpp
//  Project1
//
//  Created by Daniel Miller on 10/01/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

// zombies.cpp

#include <iostream>
using namespace std;

#include "Game.h"



int main()
{
    // Create a game
    // Use this instead to create a mini-game:   Game g(3, 4, 2);
    Game g(7, 8, 25);
    
    // Play the game
    g.play();
}


