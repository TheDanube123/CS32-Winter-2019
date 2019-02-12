//
//  main.cpp
//  Project2
//
//  Created by Daniel Miller on 28/01/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

#include "Set.h"
#include <cassert>
#include <iostream>




int main() {
    Set test;
    assert((test.empty()));
    assert((test.size()==0));
    assert(test.insert("bi")); //insert empty
    assert(test.insert("ai")); //insert front
    assert(test.insert("zo")); //insert end
    assert(test.insert("wow"));//insert middle
    assert(!(test.insert("bi")));
    assert((test.size()==4));
    assert(test.contains("ai"));
    assert(test.contains("wow"));
    assert(test.contains("zo"));
    assert(!(test.contains("hi")));
    assert(test.insert("miller"));
    
    Set test2;
    assert(!(test2.erase("hi")));
    assert(test2.insert("bi")); //insert empty
    assert(test2.erase("bi"));  //delete only item in list
    assert(test2.insert("bi")); //insert empty
    assert(test2.insert("ai")); //insert front
    assert(test2.insert("zo")); //insert end
    assert(test2.insert("wow"));//insert middle
    assert(test2.erase("ai"));  //delete first item in non-one element list
    assert(test2.insert("ai")); //insert front
    assert(test2.erase("zo"));  //delete last item in list
    assert(test2.erase("bi"));  //delete middle item in list
    assert(!(test2.erase("hi"))); //element not in list
    assert(test2.insert("daniel"));
    std::string value;
    assert(test2.get(0,value));
    assert(value=="ai");
    
    test.swap(test2);           //test swap
    assert(test.contains("daniel"));
    assert(test2.contains("miller"));
    Set test3(test2);           //test copy constructor
    assert(test3.size()==5);
    assert(test3.contains("miller"));
    test3 = test;               //test assignment operator
    assert(test3.size()==3);
    assert(test3.contains("daniel"));
    
    Set test4;                  //try unite
    test4.insert("daniel");
    test4.insert("is");
    test4.insert("so amazing");
    
    Set test5;
    test5.insert("daniel");
    test5.insert("is");
    test5.insert("and");
    test5.insert("cool");
    
    Set result;
    result.insert("garbage");
    result.insert("values");
    
    unite(test4,test5,result);
    
    Set result2 = test5;
    
    unite(test4,test5,result2);
    
    Set test6;
    test6.insert("unique1");
    test6.insert("unique2");
    test6.insert("unique3");
    test6.insert("garbage");
    test6.insert("values");
    
    Set test7;
    test7.insert("garbage");
    test7.insert("values");
    test7.insert("and");
    test7.insert("other");
    test7.insert("stuff");
    
    Set result3;
    
    subtract(test6,test7,result3);
    
    
    
    
    
    
}
