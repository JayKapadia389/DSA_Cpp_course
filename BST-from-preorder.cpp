#include <iostream>

using namespace std ;
class node{

    public :

    int data ;
    node * left ;
    node * right;

    node(int data){
        this->data = data ;
        left = NULL;
        right= NULL;
    }
};

void preOrderPrint(node * root){

    if(root == NULL){
        return ;
    }

    cout << root->data << " ";

    preOrderPrint(root->left);

    preOrderPrint(root->right);

    return ;

}

node * getBST(int arr[] , int f , int l){

    node * temp = new node(arr[f]);
    int i ;

    for(i = f + 1 ; i <= l ; i++){

        if(arr[i] > arr[f]){
            break ;
        }
    }


    if(i == f+1){
        temp->left = NULL ;
    }
    else{
        temp->left = getBST(arr , f+1 , i-1);
    }

    if(i == l + 1){
        temp->right = NULL ;
    }
    else{
        temp->right = getBST(arr , i , l);
    }

    return temp ; 

}

bool isBST(node * root , node * min , node * max){

    if(root == NULL){
        return true ;
    }

    if(min != NULL && root->data <= min->data){
        return false ;
    }

    if(max != NULL && root->data >= max->data){
        return false ;
    }

    return (isBST(root->left , min , root) && isBST(root->right , root , max));
}

int main(){

    int arr[] = {7,5,4,6,8,9};

    node * head = getBST(arr , 0 , 5);

    cout << isBST(head , NULL , NULL );

    // preOrderPrint(head) ; 

}