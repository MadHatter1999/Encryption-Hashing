//
// Created by Antho on 2020-04-24.
//

#ifndef PARTTWO_AVL_H
#define PARTTWO_AVL_H
#include <string>
#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
    string word;
    ~Node(){
        delete(left);
        delete(right);
    }

};

class AVL {
public:
    int height(Node *N);

    int max(int a, int b);

    Node *newNode(int key, string word);

    Node *rightRotate(Node *y);

    Node *leftRotate(Node *node);

    int getBalance(Node *node);

    Node *insert(Node *node, int key, string word);

    void inOrder(Node *node);

    bool Search(int key, Node *node);


    void printTreeUtil(Node *root, int pos);

    void printTree(Node *root);
};


#endif //PARTTWO_AVL_H
