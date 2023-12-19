#include <iostream>
#include <stack>

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

void zigzagPrint(node * root ){

    bool leftToRight = 1 ;

    stack<node *> currLevel , nextLevel;
    node * temp = NULL;

    if(root ==NULL){
        cout << "BST is empty";
        return ;
    }

    currLevel.push(root);

    while(!currLevel.empty()){

        while(!currLevel.empty()){

            temp = currLevel.top();
            currLevel.pop();

            cout << temp->data << " " ;

            if(leftToRight){
                // cout << "1";
                if(temp->left){
                nextLevel.push(temp->left);
                }
                if(temp->right){
                nextLevel.push(temp->right);
                }
            }
            else{
                // cout << "2";
                if(temp->right){
                nextLevel.push(temp->right);
                }
                if(temp->left){
                nextLevel.push(temp->left);
                }
            }
            
        }

        currLevel.swap(nextLevel);

        leftToRight = leftToRight? 0 : 1 ;
    }

}

int main(){

    node * root = new node(1) ; 

    root->left = new node(2); 
    root->left->right = new node(4); 

    root->left->right->left = new node(6); 
    root->left->right->right = new node(7); 

    root->right = new node(3);
    root->right->right = new node(5);

    zigzagPrint(root);

}