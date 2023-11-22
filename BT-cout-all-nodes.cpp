#include <iostream>
#include <queue>

using namespace std;

class node {
    public :

    int data ;
    node * left;
    node * right;

    node(int data){
        this->data = data;
        left =NULL;
        right =NULL;
    }
};

int countNodes(node * root){

    if(root == NULL){
        return 0 ;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumOfAllNodes(node * root ){

    if(root == NULL){
        return 0 ;
    }

    return sumOfAllNodes(root->left) + sumOfAllNodes(root->right) + root->data;
}

int heightOfBT(node * root){

    if(root == NULL){
        return 0 ;
    }

    queue<node *> q;
    node * front = NULL ;
    int c = 0;

    q.push(root);
    q.push(NULL);

    while(true){

        front = q.front();
        q.pop();

        if(front == NULL){
            c++;
            if(q.empty()){
                return c;
            }
            else{
                q.push(NULL);
            }
        }
        else{

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }

        }

    }

}

int heightOfBTRecc(node * root){

    if(root == NULL){
        return 0;
    }

    return max(heightOfBTRecc(root->left), heightOfBTRecc(root->right)) + 1;
}

int main(){

    /*
        1
        /\
       2  3
      / \ / 
     4  5 6  
       /
      9
    */

    node * root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(9);
    root->right->left = new node(6);

    cout << countNodes(root);
    cout << endl;
    cout << sumOfAllNodes(root);
    cout << endl;
    cout << heightOfBTRecc(root);

}