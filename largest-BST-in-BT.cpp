#include <iostream>
#include <climits>

using namespace std ;

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

class info{

    public : 

    int size ;
    int min ;
    int max ;
    int ans ;
    bool isBST ;
};

info largestBSTcore( node * root){

    if(root == NULL){
        return {0 , INT_MIN , INT_MAX , 0 , true} ;
    }

    if(root->left == NULL && root->right == NULL ){
        return {1 , root->data , root->data , 1 , true} ;
    }

    info leftInfo = largestBSTcore(root->left);
    info rightInfo = largestBSTcore(root->right);

    info curr ;
    curr.size = 1 + leftInfo.size + rightInfo.size ; 

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.min = min(leftInfo.min , rightInfo.min);
        curr.max = min(leftInfo.max , rightInfo.max);
        curr.ans = curr.size ; 
        curr.isBST = true ;

        return curr ;

    }

    curr.ans = max(leftInfo.ans , rightInfo.ans) ;
    curr.isBST = false ;

    return curr ;

}

int largestBST(node * root){

    return largestBSTcore(root).ans ; 
}

int main(){

     /*
         1
        / \
       5   4
        \ / \
        7 8  3
    */

   node * root = new node(1);

   root->left = new node(5);
   root->right = new node(4);

   root->left->left = new node(2);
   root->left->right = new node(7);
   root->right->left = new node(8);
   root->right->right = new node(3);

   cout << largestBST(root);

}