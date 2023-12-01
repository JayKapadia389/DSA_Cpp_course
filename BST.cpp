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
        cout << val << " " << root << endl;
        return ;
    }

    if(val < root->data){
        if(root->left == NULL){
            root->left = new node(val) ; 
            cout << val << " " << root->left << endl;
            return ; 
        }
        else{
            insertBST(root->left , val);
        }
    }
    else{
        if(root->right == NULL){
            root->right = new node(val) ; 
            cout << val << " " << root->right << endl;
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

node * searchBST(node * temp , int key){

    return (temp == NULL || temp->data == key ) ? temp  : ((temp->data > key)? searchBST(temp->left , key) : searchBST(temp->right , key)) ;

}

node *deleteNode(node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data < x)
    {
        root->right = deleteNode(root->right, x);
    }
    else if (root->data > x)
    {
        root->left = deleteNode(root->left, x);
    }
    else
    {
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            return root->right;
        }
        else if (root->right == NULL)
        {
            return root->left;
        }
        else
        {
            node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main(){

    node * head = NULL;

    insertBST(head , 5 );
    insertBST(head , 1 );
    insertBST(head , 3 );
    insertBST(head , 4 );
    insertBST(head , 2 );
    insertBST(head , 7 );


    cout << searchBST(head , 3) ; 
    cout << deleteNode(head , 3) ; 

    preOrderPrint(head);

}