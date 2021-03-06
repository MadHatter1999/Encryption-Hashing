//
// Created by Anthony Healy
// This is an Spell check using a custom hash table class
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <regex>
#include "LinkedList.h"
#include "hashTable.h"

using namespace std;

#define SIZE 29
#define smallSIZE 11

void printToScreen(string msg){
    cout<<msg<<endl;
}

/// This changes a string to all lower case
/// \param word
/// \returns The word that is put in but in lower case
string toLowerCase(string word){
    int length=word.length();
    string tmp;
    for (int i = 0; i < length; ++i) {
        tmp.push_back(tolower(word[i]));
    }
    return tmp;
}

/// Gets Dicionary
/// \return dictionary
void getDic(LinkedList &dictionary){
    vector<string> dic;
    ifstream stream("../Text/dictionary.txt");
    if(!stream){
        cout<<"cant open"<<endl;
    } else{
        string line;
        int iterator =0;
        while(getline(stream, line)){
            dic.push_back(line);
            iterator++;
        }
        sort(dic.begin(), dic.end());

        for (int i = 0; i < dic.size(); ++i) {
            dictionary.add(dic[i]);
        }

    }

}

/// This is a util for the strip function to determine what is an accepted char
/// \param input_char
/// \return true or false
bool charChecker(char input_char){
//regex
    regex S_re("[$&+,:;=?@#|'<>.^*()%!-]");
    regex N_re("[0-9]");
    string formated_char;
    formated_char.push_back(input_char);
    return regex_match(formated_char, S_re) || regex_match(formated_char,N_re) || input_char=='"';

}

/// Strips away some chars Regex inside
/// \param data
/// \return vector<string> of dictionary
vector<string> Strip(vector<string> &data){
    for (int i = 0; i < data.size(); ++i) {
        int numSpecials=0;
        for (int j = 0; j < data[i].length(); ++j) {
            //it checks the characters and sees if they are special or numbers
            if(charChecker(data[i][j])){
                //deleting unneeded
                data[i].erase(j);
                numSpecials++;
            }
            else{
                continue;
            }
        }
    }


    return data;
}

/// Gets data in file (REQUIED STRIP() TO FUNCTION)
/// \param fileName
/// \return words
void getData(string fileName,LinkedList& text, string dir){
    vector<string> data;
    ifstream stream("../"+dir);
    if(!stream){
        cout<<"cant open "+fileName<<endl;
        cout<<"make sure you check if file is there"<<endl;
    } else{
        string word;
        locale loc;
        while(stream >> word){
            data.push_back(word);
        }
        data=Strip(data);
        for (int j = 0; j < data.size(); ++j) {
            text.add(data[j]);
        }

    }

}

/// Loads the files needed for the Dictionary
/// \param dic
/// \param data
void preload(LinkedList &dic, LinkedList &data,string dir){
    getDic(dic);
    //Here is what file is being loaded in
    getData(dir,data,dir);
}



/// This will take a sample text and check for spelling errors
/// \param dic dictionary
/// \param data Sample text for comparing
void SpellChecker(LinkedList &dic, LinkedList &data){
    //Initiating the HashTable and assigning it to a pointer
    hashTable *hashTbl= new hashTable(SIZE,&dic);

    //LinkedList for errors words
    LinkedList* errors=new LinkedList();

  //  now we will loop throw the sample text to get
    for (int j = 0; j < data.getLength(); ++j) {
        //This is the active word
        string word=toLowerCase(data.at(j,data.root));
        //If word isnt nothing
        if(word!=""){
            if(hashTbl->search(word)){
                //If Word is in the list
            } else{
                //If the word is not in the
                errors->add(word);
                printToScreen(word+"<- Spelt Incorrect");
            }
        }
    }

    //Storing the HashTable for Errors
    printToScreen("");
    hashTable *ErrorTBL= new hashTable(smallSIZE,errors);
    printToScreen("Incorrect Spellings Hash Table:");
    ErrorTBL->printAll();
}

/// Main driver
/// \return
int main() {
    //Dictionary
    LinkedList dic;
    //Data
    LinkedList data;
    //Root Node and tree
    //Loads the dictionary and sample text
    preload(dic,data,"Text/mispelled.txt");

    //running spell checker
    SpellChecker(dic,data);

    return 0;
}
