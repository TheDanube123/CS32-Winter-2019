//
//  Game.h
//  Project1
//
//  Created by Daniel Miller on 10/01/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

#ifndef Game_h
#define Game_h

class Arena;

int decodeDirection(char dir);


class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nZombies);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Arena* m_arena;
};



#endif /* Game_h */
