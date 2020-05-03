//
// Created by Antho on 2020-04-28.
//

#ifndef HASHING_HASHTABLE_H
#define HASHING_HASHTABLE_H

#include <iostream>
#include "LinkedList.h"

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

    void printIndex(int key);

    void printAll();

    ~hashTable();


};


#endif //HASHING_HASHTABLE_H
