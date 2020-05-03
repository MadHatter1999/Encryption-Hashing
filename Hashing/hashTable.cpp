//
// Created by Anthony on 2020-04-28.
//
//This is a Custom Hash Table class

#include "hashTable.h"

/// Constructor
/// \param num
/// \param data
hashTable::hashTable(const int num,LinkedList* data) {
    this->arr= new LinkedList[num];
    length=num;

    //Loading in the dictionary into a HashTable
    for (int i = 0; i < data->getLength(); ++i) {
        this->add(hashfn(data->at(i,data->root)),data->at(i,data->root));
    }
}
/// Hash Function
/// \param value
/// \return
int hashTable::hashfn(string value){
    int sum=0;
    int len = value.length();
    int address;

    for (int i = 0; i < len; i++){
        //Converting to ASCII, Then adding it to the sum
        //Sum could be used as check sums later to validate
        sum+=(int)value[i];
    }
    //Using modular division to standardize the sum data to allowed to be more predicable to allow faster usage
    address = sum%this->length;
    return address;
}

/// Adds to the key index
/// \param key int for index of selected
/// \param value string for
void hashTable::add(int key,string value) {
    //This uses my custom link list class to chain the collisions
    arr[key].add(value);
}

/// Removes list
/// \param key
void hashTable::remove(int key) {
    arr[key].root= nullptr;
}

/// Gets the list at
/// \param key
/// \return * to LinkedList at the index selected
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

/// Searches and finds value in table
/// \param value
/// \return true if word is found
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

///
/// \returns Length
int hashTable::getLength() {
    return length;
}

/// prints an list of an index
/// \param key
void hashTable::printIndex(int key) {
    LinkedList* li= nullptr;
    if(key<this->getLength()&&key>=0){
         li = this->at(key);
         //checking if not null
        if(li!= nullptr && li->root!= nullptr  ){
            cout<<key<<":";
            li->printAll(li->root);
        }
    }
}

///Prints all
void hashTable::printAll() {
    cout<<"Key:Word(s)"<<endl;
    for (int i = 0; i < this->length; ++i) {
        printIndex(i);
    }
}

hashTable::~hashTable() {
    delete(this->arr);
}












