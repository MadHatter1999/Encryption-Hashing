//
// Created by Antho on 2020-05-01.
//

#ifndef HASHING_LINKEDLIST_H
#define HASHING_LINKEDLIST_H

#include "string"
#include <iostream>
using namespace std;

class Node{
public:
    int key;
    string word;
    Node* next;
    Node* prev;

    Node(int key, string word){
        this->key=key;
        this->word=word;
        this->next= nullptr;
        this->prev= nullptr;

    }

    ~Node(){
        delete(this->next);
    }
};

class LinkedList {
    int length=0;
public:

    Node* root;
    //Functions
    LinkedList(string word);

    LinkedList();

    static int indexOf(string word, Node* node);

    static string at(int index, Node* node);

    void add(string word);

    void remove(int index);

    void printAll(Node *node);

    int getLength();

    ~LinkedList();
};


#endif //HASHING_LINKEDLIST_H
