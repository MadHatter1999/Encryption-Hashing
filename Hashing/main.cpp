#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <regex>
#include "AVL.h"
#include "LinkedList.h"
using namespace std;
/// Gets Dicionary
/// \return dictionary
void getDic(LinkedList &dictionary){
    vector<string> dic;
    ifstream stream("../dictionary.txt");
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
/// This is a util for the strip function to determin what is a char
/// \param input_char
/// \return true or false
bool charChecker(char input_char){
    regex S_re("[$&+,:;=?@#|'<>.^*()%!-]");
    regex N_re("[0-9]");
    string formated_char;
    formated_char.push_back(input_char);
    return regex_match(formated_char, S_re) || regex_match(formated_char,N_re) || input_char=='"';

}
/// Strips away nasty chars
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
void getData(string fileName,LinkedList& text){
    vector<string> data;
    ifstream stream("../"+fileName);
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
void preload(LinkedList &dic, LinkedList &data){
    getDic(dic);
    //Here is what file is being loaded in
    getData("mispelled.txt",data);
}

/// This will take a sample text and check for spelling errors
/// \param dic dictionary
/// \param data Sample text for comparing
void SpellChecker(LinkedList &dic, LinkedList &data){
    Node* root=NULL;
    AVL avl;
    //populates the tree with data
    for (int i = 0; i < dic.getLength()+1;++i) {
        root=avl.insert(root,i,dic.at(i,dic.root));
    }

    int count=0;
    for (int j = 0; j < dic.getLength(); ++j) {
        string word=data.at(j,data.root);

        //converts to lower case
        for_each(word.begin(), word.end(), [](char & c){
            c = tolower(c);
        });

        if(word!=""){
            int index= dic.indexOf(word,dic.root);
            if(avl.Search(index,root)==false){
                cout<<word<<" <-Is spelt incorrectly"<<endl;
                count++;
            }

        }
        else{
            continue;
        }
    }
    cout<<"There is "<<count<<" word(s) spelt wrong";
    //The Tree is printed side ways
    avl.printTree(root);
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
    preload(dic,data);
    SpellChecker(dic,data);








    return 0;
}
//  LinkedList x=LinkedList("hi");
//    x.add("test");
//    x.add("yo");
//    x.printAll(x.root);