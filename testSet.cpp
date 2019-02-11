
  main.cpp
  Homework1

  Created by Daniel Miller on 22/01/2019.
  Copyright © 2019 Daniel Miller. All rights reserved.


#include "Set.h"
#include <iostream>
#include <cassert>


int main() {
    Set test;
    assert((test.empty()));
    assert((test.size()==0));
    test.insert("hi");
    test.insert("hi");
    test.insert("ao");
    test.insert("wow");
    test.insert("id");
    assert((test.erase("hi")));
    assert((!(test.erase("he"))));
    assert((test.erase("id")));
    assert((test.contains("ao")));
    assert(!(test.contains("he")));
    test.insert("how");
    test.insert("vow");
    test.insert("eow");
    std::string x;
    assert(test.get(0,x));
    assert(x=="ao");
    std::string y;
    assert(test.get(2,y));
    assert(y=="how");
    assert(!(test.get(7,y)));
    assert(test.size()==5);
    Set test2;
    test2.insert("hi2");
    test2.insert("bye2");
    test2.swap(test);
    assert(test2.size()==5);
    assert(test.size()==2);
    assert(test2.contains("wow"));
    assert(test.contains("hi2"));
    return 0;


}

