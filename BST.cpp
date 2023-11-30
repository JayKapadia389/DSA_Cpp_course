#include <iostream>

using namespace std;

class node{
    public:

    int data;
    node * left;
    node * right;

    node(int data){
        this->data = data ;
        left = NULL;
        right = NULL;

    }
};

void insertBST(node * &root , int val){

    if(root == NULL){
        root = new node(val) ;
        return ;
    }

    if(val < root->data){
        if(root->left == NULL){
            root->left = new node(val) ; 
            return ; 
        }
        else{
            insertBST(root->left , val);
        }
    }
    else{
        if(root->right == NULL){
            root->right = new node(val) ; 
            return ; 
        }
        else{
            insertBST(root->right , val);
        }
    }
}

void preOrderPrint(node * root){

     cout << root->data << " ";

    if(root->left){
        preOrderPrint(root->left);
    }
    if(root->right){
        preOrderPrint(root->right);
    }

    return ;

}

int main(){

    node * head = NULL;

    insertBST(head , 5 );
    insertBST(head , 1 );
    insertBST(head , 3 );
    insertBST(head , 4 );
    insertBST(head , 2 );
    insertBST(head , 7 );

    preOrderPrint(head);

}