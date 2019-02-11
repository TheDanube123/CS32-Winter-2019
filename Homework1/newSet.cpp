//
//  Set.cpp
//  Homework1
//
//  Created by Daniel Miller on 22/01/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

#include "newSet.h"


Set::Set(){
    m_size = 0;
    arr = new ItemType[DEFAULT_MAX_ITEMS];
}

Set::Set(int size){
    arr = new ItemType[size];
    m_size = 0;
}

Set::~Set(){
    delete [] arr;
}

Set::Set(const Set &src){
    this->m_size = src.m_size;
    this->arr = new ItemType[this->m_size];
    for (int i = 0; i < this->m_size; i++){
        this->arr[i] = src.arr[i];
    }
}

Set& Set::operator=(const Set &src){
    if (&src == this){
        return *this;
    }
    delete [] this->arr;
    this->m_size = src.m_size;
    this->arr = new ItemType[this->m_size];
    for (int i = 0; i < this->m_size; i++){
        this->arr[i] = src.arr[i];
    }
    return *this;
}

bool Set::empty() const{
    if (m_size == 0){
        return true;
    }
    return false;
}

int Set::size() const{
    return m_size;
}

bool Set::insert(const ItemType& value){
    if (m_size == 250){
        return false;
    }
    for (int i = 0; i<m_size;i++){
        if (arr[i] == value){
            return false;
        }
    }
    if (this->empty()){
        arr[m_size] = value;
        m_size++;
        return true;
    }
    for (int j = 0; j<m_size; j++){
        if (value < arr[j]){
            for (int b = m_size-1; b>j-1;b--){
                arr[b+1] = arr[b];
            }
            arr[j] = value;
            m_size++;
            return true;
        }
    }
    arr[m_size] = value;
    m_size++;
    return true;
}

bool Set::erase(const ItemType& value){
    for (int i = 0; i < m_size; i++){
        if (arr[i]==value){
            for (int j = i; j<m_size;j++){
                if (j!=249){
                    arr[j] = arr[j+1];
                }
                else{
                    return false;
                }
            }
            m_size--;
            return true;
        }
    }
    return false;
}

bool Set::contains(const ItemType& value) const{
    for (int i = 0; i<m_size; i++){
        if (arr[i] == value){
            return true;
        }
    }
    return false;
}

bool Set::get(int i, ItemType& value) const{
    if (i>=0 && i<m_size){
        value = arr[i];
        return true;
    }
    return false;
}

void Set::swap(Set &other){
    
    int temp = this->m_size;
    this->m_size = other.m_size;
    other.m_size = temp;
    
    ItemType* temp2 =this->arr;
    this->arr = other.arr;
    other.arr = temp2;
}
