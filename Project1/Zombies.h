//
//  Zombies.h
//  Project1
//
//  Created by Daniel Miller on 10/01/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

#ifndef Zombies_h
#define Zombies_h

class Arena;  // This is needed to let the compiler know that Arena is a
// type name, since it's mentioned in the Zombie declaration.

class Zombie
{
public:
    // Constructor
    Zombie(Arena* ap, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    
    // Mutators
    void move();
    bool getAttacked(int dir);
    
private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_health;
};

#endif /* Zombies_h */
