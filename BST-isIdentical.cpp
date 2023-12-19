#include <iostream>

using namespace std;

class node{
    public :

    int data ;
    node * left;
    node * right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL ;
    }

};

bool isIdentical(node * r1 , node * r2){

    if(r1 == NULL && r2 == NULL){
        return 1;
    }
    else if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)){
        return 0;
    }

    if(r1->data == r2->data && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    node * r1 = new node(1) ; 

    r1->left = new node(2); 
    r1->left->right = new node(4); 

    r1->left->right->left = new node(6); 
    r1->left->right->right = new node(7); 

    r1->right = new node(3);
    r1->right->right = new node(5);

    node * r2 = new node(1) ; 

    r2->left = new node(2); 
    r2->left->right = new node(4); 

    r2->left->right->left = new node(6); 
    r2->left->right->right = new node(7); 

    r2->right = new node(3);
    // r2->right->right = new node(5);

    cout << isIdentical(r1 , r2);
}