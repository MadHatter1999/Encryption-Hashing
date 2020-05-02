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
    hashNode* root;
    int length=0;
public:
    hashTable();

    int hash();

    void add(int key,string value);

    void remove(int key);

    LinkedList* search(int key);

    ~hashTable();
};


#endif //HASHING_HASHTABLE_H
