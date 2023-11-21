#include <iostream>

using namespace std;

class node{
    public:

    int data;
    node * left;
    node * right;

    node(int x){
        data = x;
        left = NULL;
        right = NULL;

    }
};

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

void inorder(node * root){

    if(root->left != NULL){
        inorder(root->left);
    }
    cout << root->data << " " ;
    if(root->right != NULL){
        inorder(root->right);
    }

    return ; 

}

int search(int arr[] , int start , int end , int curr){

    for ( int i = start; i <= end; i++)
    {
        if(arr[i] == curr){
            return i ; 
        }
    }
    
}

node * buildBT(int postOrder[] , int inOrder[] , int start , int end) {

    if(start > end){
        return NULL;
    }

    static int idx = 6 ;

    int curr = postOrder[idx]; 
    idx--;

    node * newNode = new node(curr);

    int currIdx = search(inOrder , start , end ,curr);

    newNode->right = buildBT(postOrder , inOrder ,currIdx + 1 , end);
    newNode->left = buildBT(postOrder , inOrder ,start , currIdx - 1);
    
    return newNode;

} 

int main(){

    int postOrder[] = {8,9,2,5,7,3,1};
    int inOrder[] = {1,8,2,9,3,5,7};

    node * root = buildBT(postOrder , inOrder , 0 , 6);

    postorder(root);
    cout << endl;
    inorder(root); 
}