#include <iostream>
#include <vector>

using namespace std;

class node{

    public:

    int data;
    node * left ;
    node * right ;

    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printLL(node * head){

    while(head != NULL){
        cout << head->data << " " ;
        head = head -> right ;  
    }

    return;
}

void flatenBT(node * root){

    if(root == NULL){
        return  ;
    }

    node * l = root->left;
    node * r = root->right;

    flatenBT(l);
    flatenBT(r);

    root->left = NULL ;

    if(l != NULL){

        root->right = l ;

        while(l->right != NULL){
            l = l-> right ;
        }

        l -> right = r; 
    }
    else{

        if(r != NULL){
            root->right = r;
        }

    }

    return ; 
}

int main(){

    /*
        1
        /\
       2   3
      / \  / 
     4  5  6  
       /
      9
    */

    node * root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(9);
    root->right->left = new node(6);

    flatenBT( root );

    printLL( root );
}