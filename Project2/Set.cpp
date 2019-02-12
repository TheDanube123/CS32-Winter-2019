//
//  Set.cpp
//  Project2
//
//  Created by Daniel Miller on 28/01/2019.
//  Copyright © 2019 Daniel Miller. All rights reserved.
//

#include "Set.h"




Set::Set():m_size(0),head(nullptr),tail(nullptr)
{}

Set::~Set(){
    Node *p = head;
    while (p!=nullptr){
        Node *q = p;
        p = p->next;
        delete q;
    }
}

Set::Set(const Set &src){
    this->head = nullptr;
    this->tail = nullptr;
    this->m_size = 0;
    
    Node *p = src.head;
    while (p!=nullptr){
        this->insert(p->value);
        p = p->next;
    }
}

Set& Set::operator=(const Set &src){
    if (this == &src){
        return *this;
    }
    Set temp(src);
    this->swap(temp);
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
    Node *r = head;
    
    while (r!=nullptr){                     //check for repeated item
        if (r->value == value){
            return false;
        }
        r = r->next;
    }
    
    if (empty()){                           //empty list
        Node *q = new Node;
        q->next = nullptr;
        q->value = value;
        q->prev = nullptr;
        head = q;
        tail = q;
        m_size++;
        return true;
    }
    
    Node *p = head;
    
    while (p != nullptr){
        if (value < p->value){
            if (p->prev == nullptr){        //insert at front of non empty list
                Node *q = new Node;
                q->value = value;
                p->prev = q;
                q->next = p;
                q->prev = nullptr;
                head = q;
                m_size++;
                return true;
            }
            if (p->next ==nullptr){
                tail = p;
            }
            Node *q = new Node;             //insert at middle of list
            q->value = value;
            q->next = (p->prev)->next;
            q->prev = p->prev;
            (p->prev)->next = q;
            p->prev = q;
            m_size++;
            return true;
        }
        p = p->next;
    }
    
    Node *q = new Node;                     //insert at end of the list
    q->value = value;
    q->prev = tail;
    q->next = nullptr;
    tail->next = q;
    tail = q;
    m_size++;
    return true;
}

bool Set::contains(const ItemType& value) const{
    Node *p = head;
    while (p!=nullptr){
        if (p->value == value){
            return true;
        }
        p = p->next;
    }
    return false;
}

bool Set::erase(const ItemType &value){
    if (empty()){                       //empty list
        return false;
    }
    if (!contains(value)){              //not found in list
        return false;
    }
    Node *p = head;
    while (p->next != nullptr){
        if (p->value == value){
            if (p->prev == nullptr){    //delete first element of non-one element list
                head = p->next;
                head->prev = nullptr;
                m_size--;
                delete p;
                return true;
            }
            (p->prev)->next = p->next;      //delete from middle of list
            (p->next)->prev = p->prev;
            m_size--;
            delete p;
            return true;
        }
        p=p->next;
    }
    if (p->prev == nullptr){            //one element list
        head = nullptr;
        tail = nullptr;
        m_size--;
        delete p;
        return true;
    }
    tail = p->prev;                     //delete from end of list
    tail->next = nullptr;
    m_size--;
    delete p;
    return true;
}

bool Set::get(int i,ItemType& value) const{
    if (i >= 0 && i < m_size){
        
        int counter = 0;
        Node *p = head;
        while (i!=counter){
            counter++;
            p = p->next;
        }
        value = p->value;
        return true;
    }
    return false;
}

void Set::swap(Set &other){
    int tempVal = this->m_size;
    this->m_size = other.m_size;
    other.m_size = tempVal;
    
    Node *temp = head;
    head = other.head;
    other.head = temp;
    
    Node *temp2 = tail;
    tail = other.tail;
    other.tail = temp2;
    
    return;
}

void unite(const Set& s1, const Set& s2, Set& result){
    bool setS1NotEqual = !(&s1 == &result);
    bool setS2NotEqual = !(&s2 == &result);
    
    if (setS1NotEqual && setS2NotEqual){
        result = s1;
        int size = s2.size();
        int i = 0;
        ItemType value;
        while (i < size){
            s2.get(i,value);
            result.insert(value);
            i++;
        }
        return;
    }
    if (!(setS1NotEqual)){
        int i = 0;
        int size = s2.size();
        ItemType value;
        while (i < size){
            s2.get(i,value);
            result.insert(value);
            i++;
        }
        return;
    }
    if (!(setS1NotEqual)){
        int i = 0;
        int size = s2.size();
        ItemType value;
        while (i<size){
            s2.get(i,value);
            result.insert(value);
            i++;
        }
        return;
    }
}

void subtract(const Set& s1, const Set& s2, Set& result){
    result = s1;
    int i = 0;
    int size = s1.size();
    ItemType value;
    while (i<size){
        s1.get(i,value);
        if (s2.contains(value)){
            result.erase(value);
        }
        i++;
    }
}

