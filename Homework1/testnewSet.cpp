//
//  testnewSet.cpp
//  Homework1
//
//  Created by Daniel Miller on 22/01/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

#include "newSet.h"
#include <cassert>

int main(){
    Set test(100);
    Set test2;
    test.insert("hi");
    test.insert("no");
    std::string value;
    assert(test.get(1,value));
    assert(value=="no");
    Set test3 = test;
    test3.get(0,value);
    assert(value=="hi");
    test3.get(1,value);
    assert(value=="no");
    test2 = test3;
    test2.get(0,value);
    assert(value=="hi");
    test2.get(1,value);
    assert(value=="no");
    assert(test.size()==2);
    Set testSwap(5);
    testSwap.insert("Daniel");
    testSwap.insert("Miller");
    Set testSwap2;
    testSwap2.insert("Eva");
    testSwap2.insert("Prieto");
    testSwap.swap(testSwap2);
    return 0;
}


