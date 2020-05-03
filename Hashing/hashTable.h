//
// Created by Antho on 2020-04-28.
//

#ifndef HASHING_HASHTABLE_H
#define HASHING_HASHTABLE_H

#include <iostream>
#include "LinkedList.h"
class hashNode{

public:
    int key;
    LinkedList* list;
    hashNode* next;
    hashNode* prev;
    hashNode(int key){
        this->key=key;
        this->list = new LinkedList();
        this->next= nullptr;
        this->prev= nullptr;
    }
    ~hashNode(){
        delete(list);
        delete(next);
    }

};
class hashTable {
    LinkedList* arr= nullptr;
    int length=0;
public:
    hashTable(const int num,LinkedList* data);
    int hashfn(string value);
    void add(int key,string value);

    void remove(int key);

    LinkedList *at(int key);

    bool search(string value);



    int getLength();

    ~hashTable();


};


#endif //HASHING_HASHTABLE_H
