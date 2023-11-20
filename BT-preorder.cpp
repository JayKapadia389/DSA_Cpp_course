#include <iostream>

using namespace std;

class node{

    public:

    int data ;
    node * left ;
    node * right;

    node(int x){
        data = x ; 
        left = NULL;
        right = NULL;
    }

};

/*
        1
       / \
      2   3
     / \ / \
    4  5 6  7
*/

void preorder(node * root){

    cout << root->data << " "; 

    if(root->left != NULL){
        preorder(root->left);
    }

    if(root->right != NULL){
        preorder(root->right);
    }

    return ;
}

void inorder(node * root){

    if(root->left != NULL){
        inorder(root->left);
    }

    cout << root->data << " ";

    if(root->right != NULL){
        inorder(root->right);
    }

    return ; 

}

void postorder(node * root){

    if(root->left != NULL){
        postorder(root->left);
    }

    if(root->right != NULL){
        postorder(root->right);
    }
    
    cout << root->data << " ";

    return ; 

}

int main(){

    node * root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
}