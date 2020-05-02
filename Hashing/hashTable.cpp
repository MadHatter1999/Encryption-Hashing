//
// Created by Antho on 2020-04-28.
//

#include "hashTable.h"

hashTable::hashTable() {
    this->root= nullptr;
}

//TODO
//Work on adding then try and finish the spell checker
//
//
//
//Adding node to end of linked list
void hashTable::add(hashNode *node,int key,string value) {
    if(node->next!= nullptr){
        add(node->next,key,value);
    }else{
        node->list->add(value);
    }
}

void hashTable::add(int key,string value) {
    //Base case if empty
    if(this->root== nullptr){
        root=new hashNode(key);
        root->list->add(value);
    }else{
        add(this->root,key,value);
}
}

void hashTable::remove(int key) {

}

LinkedList *hashTable::search(int key) {
    return nullptr;
}

hashTable::~hashTable() {

}


