
  testSSNSet.cpp
  Homework1

  Created by Daniel Miller on 22/01/2019.
  Copyright © 2019 Daniel Miller. All rights reserved.



#include "SSNSet.h"
#include <cassert>

int main(){
    SSNSet test;
    test.add(22);
    test.add(21);
    assert(test.size()==2);
    test.print();
    return 0;
}

