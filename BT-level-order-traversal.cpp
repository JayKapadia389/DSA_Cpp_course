#include <iostream>
#include <queue>

using namespace std;

class node{
    public:

    int data;
    node * left ;
    node * right ; 

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL ;
    }
};

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

node * null = NULL ;

void levelOrderPrint(node * root){

    queue<node *> q;
    node * front = NULL;

    q.push(root);
    q.push(null);

    while(true){

        front = q.front();
        q.pop();

        if(front != NULL){

            cout << front->data << " ";

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        else{

            if(q.empty()){
                return; 
            }
            else{
                q.push(null);
            }
        }
    }


}

int main(){

    /*
         1
        / \
       2   3
      / \ / \
     4  5 6  7

    */

   node * root = new node(1);

   root->left = new node(2);
   root->right = new node(3);

   root->left->left = new node(4);
   root->left->right = new node(5);
   root->right->left = new node(6);
   root->right->right = new node(7);

   preOrderPrint(root);
   cout << endl ;
   levelOrderPrint(root);


}