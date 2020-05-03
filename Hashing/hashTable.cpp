//
// Created by Antho on 2020-04-28.
//

#include "hashTable.h"




hashTable::hashTable(const int num,LinkedList* data) {
    this->arr= new LinkedList[num];
    length=num;

    //Loading in the dictionary into a HashTable
    for (int i = 0; i < data->getLength(); ++i) {
        this->add(hashfn(data->at(i,data->root)),data->at(i,data->root));
    }
}

int hashTable::hashfn(string value){
    int i, sum, address;

    sum = 0;
    int len = value.length();
    for (i = 0; i < len; i++){
    sum += (int)value[i]; // cast each character of the string as int to get ascii value
    }
    // the modulus, or remainder, of integer division gives a result between 0 and SIZE-1, perfect for an index
    address = sum % this->length;

    return address;

}


void hashTable::add(int key,string value) {
    //This uses my custom link list class to chain the colisions
    arr[key].add(value);
}

void hashTable::remove(int key) {
    arr[key].root= nullptr;
}

LinkedList* hashTable::at(int key) {
    //Grabbing the List at that index/Key
    LinkedList *li= &arr[key];
    //Checking if its not empty
    if(li->root!= nullptr){
        return li;
    } else{
        return nullptr;
    }

}

bool hashTable::search(string value) {
    //if you have the key it would be sorted into you can just check that list
    int key=hashfn(value);
    //getting the list
    LinkedList* li=this->at(key);
    //Checking if list is null
    if(li!=nullptr){
        //Creating a tmp start node to loop through the list
        Node* Start= li->root;
        while(Start!= nullptr){
            //word Matches
            if(Start->word==value){
                return true;
            }
            else{
                //Assigns the next node to be used in next rotation
                Start=Start->next;
            }
        }
    }else{
        return false;
    }
}

int hashTable::getLength() {
    return length;
}

hashTable::~hashTable() {

}








