//
// Created by Antho on 2020-04-24.
//

#include "AVL.h"
using namespace std;
/// Gets the hight form node
/// \param N
/// \return
int AVL::height(Node *N){
    if (N==NULL){
        return 0;
    }
    return N->height;
}

int AVL::max(int a, int b){
    return (a > b)? a : b;
}

/// This makes a new node with null left and right pointers
/// \param key
/// \param word
/// \return
Node* AVL::newNode(int key,string word){
    Node* node=new Node();
    node->key=key;
    node->word=word;
    node->left=NULL;
    node->right=NULL;
    node->height=1;//Default height
    return(node);
}

/// Right rotate
/// \param y
/// \return
Node* AVL::rightRotate(Node *y){
    Node *x=y->left;
    Node *T2=x->right;

    // Performing rotation
    x->right=y;
    y->left=T2;

    // Update the heights
    y->height=max(height(y->left),height(y->right)) + 1;
    x->height=max(height(x->left),height(x->right)) + 1;

    // Return new root
    return x;
}

/// Left rotate utility
/// \param node
/// \return
Node* AVL::leftRotate(Node *node){
    Node *y=node->right;
    Node *tmp=y->left;

    // Performing Rotation
    y->left=node;
    node->right=tmp;

    // Updates the heights
    node->height= max(height(node->left), height(node->right)) + 1;
    y->height=max(height(y->left),height(y->right)) + 1;
    //Returns the new root node
    return y;
}

/// Gets the balance factor needed for determing if the tre is balanced
/// \param node
/// \return
int AVL::getBalance(Node *node){
    if (node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

/// Recusive function for inserts it handles the four cases
/// \param node
/// \param key
/// \param word
/// \returns modified node
Node* AVL::insert(Node* node,int key,string word){
    /* 1. Perform the normal BST insertion */
    if (node == NULL){
        return(newNode(key,word));
    }

    if (key < node->key) {
        node->left = insert(node->left, key, word);
    }else if (key > node->key){
        node->right = insert(node->right, key,word);
    }else{
        return node;
    }


    // updating the height of ansestor node
    node->height=1+max(height(node->left),height(node->right));

    //gets the ansestor nodes balance so it can detect if unbalenced
    int balance = getBalance(node);

    // rotation cases
    // Left Left Case
    if (balance>1 && key<node->left->key){
        return rightRotate(node);
    }

    // Right Right Case
    if (balance<-1 && key>node->right->key){
        return leftRotate(node);
    }

    // Left Right Case
    if (balance>1 && key>node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance<-1 && key<node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
//In order traversal starting bottom left moving up then right recursively
void AVL::inOrder(Node *node) {
    if (node == NULL){
        return;
    }

    inOrder(node->left);
    cout << node->word << " ";
    inOrder(node->right);
}
bool AVL::Search(int key,Node* node){
    if(node!=NULL){
        if(key==node->key){
            return true;
        }else{
            if(key>node->key && node->right!=NULL){
                return Search(key,node->right);
            }else if(key<node->key && node->left!=NULL){
                return Search(key,node->left);
            }
            else{
                return false;
            }
        }
    } else{
        return false;
    }
}
/// Prints tree sideways
/// \param root
/// \param pos
void AVL::printTreeUtil(Node *root, int pos)
{
    //In case of NULL
    if (root == NULL){
        return;
    }

    //Distance between levels
    pos+=10;

    // Process right child first
    printTreeUtil(root->right, pos);

    // Print current node after pos
    // count
    cout<<endl;
    for (int i=10; i<pos; i++){
        cout<<" ";
    }
    cout<<root->word<<"\n";

    // do left child
    printTreeUtil(root->left, pos);
}

// Prints tree
void AVL::printTree(Node *root)
{
    //initial pos count as 0
    printTreeUtil(root, 0);
}

