//
// Created by Anthony Healy on 2020-05-01.
//  This
//

#include "LinkedList.h"

//Constructor
LinkedList::LinkedList(string word) {
    this->root=new Node(length, word);
    this->length=1;
}

LinkedList::LinkedList() {
    this->root= nullptr;
    this->length=0;
}
//Utility functions

int LinkedList::indexOf(string word, Node *node) {
    if(node!=nullptr){
        if(node->word==word){
            return node->key;
        }else if(node->next!= nullptr){
            return indexOf(word,node->next);
        } else{
            return -1;
        }
    }else{
        return -1;
    }
}

string LinkedList::at(int index, Node *node) {
    if(node !=nullptr){
        if(node->key==index){
            return node->word;
        } else{
            if(node->next!= nullptr) {
                return at(index, node->next);
            }
        }
    } else{
        return "";
    }
}

void LinkedList::add(string word) {
    Node *tmp=new Node(length,word);
    if(root!=nullptr){
        Node* start=this->root;
        while(start->next!= nullptr){
            start=start->next;
        }
        tmp->prev=start;
        start->next=tmp;
    }else{//handling if list is empty
        root=tmp;
    }
    length++;
}

void LinkedList::remove(int index) {
    Node* start=this->root;
    while(start->key!=index){
        start=start->next;
    }
    Node* tmp=start->next;
    start->prev->next=tmp;
    length--;
}

void LinkedList::printAll(Node *node) {
    if(node == nullptr){
        cout<<endl;
    }else{
        cout<<node->word<<" ";
        printAll(node->next);
    }
}

LinkedList::~LinkedList() {
    root->next= nullptr;
    delete(root);
}

int LinkedList::getLength() {
    return this->length;
}
