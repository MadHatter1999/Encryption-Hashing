//
// Created by Antho on 2020-04-28.
//

#include "hashTable.h"

hashTable::hashTable() {
    this->root= nullptr;
}


void hashTable::add(int key,string value) {
    if(this->root== nullptr){
        root=new hashNode();
        root->list->add(value);
    }else{

    }
}

void hashTable::remove(int key) {

}

LinkedList *hashTable::search(int key) {
    return nullptr;
}

hashTable::~hashTable() {

}
