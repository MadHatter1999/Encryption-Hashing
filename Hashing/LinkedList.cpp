//
// Created by Anthony Healy on 2020-05-01.
//  This is a linked list class
//

#include "LinkedList.h"

//constructors
///Default Constructor
LinkedList::LinkedList() {
    this->root= nullptr;
    this->length=0;
}

///
/// \param word to be added at root
LinkedList::LinkedList(string word) {
    this->root=new Node(length, word);
    this->length=1;
}
//Utility functions

/// Finds the index of a word
/// \param word
/// \param node
/// \return if -1 index is not found else returns the index of wanted word
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

/// Returns the string at a certain index
/// \param index
/// \param node
/// \return  string of selected index
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

/// Add string to end of list
/// \param word
void LinkedList::add(string word) {
    Node *tmp=new Node(length,word);
    //This will add to the end of the list
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

/// removes a certain index
/// \param index
void LinkedList::remove(int index) {
    Node* start=this->root;
    while(start->key!=index){
        start=start->next;
    }
    Node* tmp=start->next;
    start->prev->next=tmp;
    length--;
}

/// Prints all to screen
/// \param node
void LinkedList::printAll(Node *node) {
    if(node == nullptr){
        cout<<endl;
    }else{
        cout<<node->word<<",";
        printAll(node->next);

    }

}

///
/// \return Length of this list
int LinkedList::getLength() {
    return this->length;
}
LinkedList::~LinkedList() {
    root->next= nullptr;
    delete(root);
}


