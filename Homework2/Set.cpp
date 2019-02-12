//
//  Set.cpp
//  Homework1
//
//  Created by Daniel Miller on 22/01/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

#include "Set.h"


Set::Set(){
    m_size = 0;
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
    int loop;
    if (other.m_size>this->m_size){
        loop = other.m_size;
    }
    else{
        loop = this->m_size;
    }
    for (int i = 0; i< loop; i++){
        ItemType temp2 = other.arr[i];
        other.arr[i] = this->arr[i];
        this->arr[i] = temp2;
        if (other.m_size - 1 == i && this->m_size - 1 != i){
            for (int j = i+1; j<this->m_size;j++){
                other.arr[j] = this->arr[j];
            }
            break;
        }
        else if (this->m_size - 1 == i && other.m_size - 1 != i){
            for (int b = i+1; b<other.m_size;b++){
                this->arr[b] = other.arr[b];
            }
            break;
        }
        else if (this->m_size - 1 == i && other.m_size - 1 == i){
        break;
        }
    }

    int temp = this->m_size;
    this->m_size = other.m_size;
    other.m_size = temp;


}



