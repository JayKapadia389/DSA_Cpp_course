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

int search(int inOrder[] , int start , int end , int curr){

    for(int i = start ; i <= end ; i++){
        if(inOrder[i] == curr){
            return i ;
        }
    }
}

node * buildBT(int preOrder[] , int inOrder[] , int start , int end ){

    if(start > end){
        return NULL; 
    }

    static int idx = 0  ;

    int curr = preOrder[idx];
    idx++;

    node * newNode = new node(curr);

    int currIdx = search(inOrder , start , end , curr );  //

    newNode->left = buildBT(preOrder , inOrder , start , currIdx - 1 );
    newNode->right = buildBT(preOrder , inOrder , currIdx + 1 , end );

    return newNode ;


}

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


int main(){

    int preOrder[] = {1,2,4,3,5};
    int inOrder[] = {4,2,1,5,3};

    node * root = buildBT(preOrder , inOrder , 0 , 4 ) ;

    preorder(root);

    cout << endl ;

    inorder(root);



}