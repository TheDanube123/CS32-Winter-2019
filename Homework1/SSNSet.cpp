//
//  SSNSet.cpp
//  Homework1
//
//  Created by Daniel Miller on 22/01/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

#include "SSNSet.h"
#include <iostream>


SSNSet::SSNSet(){
}

bool SSNSet::add(unsigned long ssn){
    if (m_SSNS.insert(ssn)){
        return true;
    }
    return false;
}

int SSNSet::size() const{
    return m_SSNS.size();
}

void SSNSet::print() const{
    unsigned long value;
    for(int i = 0;i<this->size();i++){
        m_SSNS.get(i,value);
        std::cout << value << std::endl;
    }
}

