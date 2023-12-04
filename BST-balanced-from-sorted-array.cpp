#include <iostream>

using namespace std;

class node{
    public:

    int data;
    node * left ;
    node * right ;

    node(int data){
        this->data = data ;
        left = NULL;
        right = NULL;
    }
}; 

void inOrderPrint(node * root ){

    if(root == NULL){
        return ;
    }

    inOrderPrint(root->left);

    cout << root -> data << " ";

    inOrderPrint(root->right);

    return ; 

}

node * getBST(int arr[] , int f , int l){

    if(f > l){
        return NULL ; 
    }

    int mid = (f+l)/2; 

    node * temp = new node(arr[mid]);

    temp -> left = getBST(arr , f , mid-1);
    temp -> right = getBST(arr , mid+1 , l);

    return temp ;

}

int main(){

    int arr[] = {1,2,3,4,5 , 6};

    node * root = getBST(arr , 0 , 5 );

    inOrderPrint(root);

}