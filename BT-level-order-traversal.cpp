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

void levelOrderPrint(node * root){

    queue<node *> q;
    node * front = NULL;

    q.push(root);
    q.push(NULL);

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
                q.push(NULL);
            }
        }
    }

}

int sumAtKLevel(node * root , int k){

    if(root == NULL){
        return -1;
    }

    int sum = 0 ;
    queue<node *> q1;
    int l = 0 ;
    node * front = NULL;

    q1.push(root);
    q1.push(NULL);

    while(l != k){

        front = q1.front();
        q1.pop();

        if(front == NULL){
            l++;
            q1.push(NULL);
        }
        else{
            if(front->left){
                q1.push(front->left);
            }
             if(front->right){
                q1.push(front->right);
            }
        }

    }

    while(q1.front() != NULL){

        sum += q1.front()->data;
        q1.pop();
    }

    cout << "sum->";

    return sum ; 
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

//    root->left->left = new node(2);
   root->left->right = new node(7);
   root->right->left = new node(8);
   root->right->right = new node(3);

   preOrderPrint(root);
   cout << endl << endl;
   levelOrderPrint(root);
   cout << endl << endl;
   cout << sumAtKLevel(root , 2);

}