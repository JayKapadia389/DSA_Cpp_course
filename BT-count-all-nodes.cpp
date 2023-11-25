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

void preOrderPrint(node * root){

    cout << root->data << " "; 

    if(root->left != NULL){
        preOrderPrint(root->left);
    }

    if(root->right != NULL){
        preOrderPrint(root->right);
    }

    return ;
}

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

    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    else if(root->left == NULL){
        return heightOfBTRecc(root->right) + 1;
    }
    else if(root->right == NULL){
        return heightOfBTRecc(root->left) + 1 ;
    }
    else{
        return max(heightOfBTRecc(root->left), heightOfBTRecc(root->right)) +1 ;
    }

}

int diameterOfBT(node * root){

    static int dia = 0;

    if((root->left == NULL && root->right == NULL) || root == NULL){
        return 0 ;
    }

    int lh = 0;
    int rh = 0;

    if(root->left != NULL){
        lh = heightOfBTRecc(root->left) + 1;
    }
    if(root->right != NULL){
        rh = heightOfBTRecc(root->right) + 1;
    }

    dia = max(dia , lh + rh);

    diameterOfBT(root->left);
    diameterOfBT(root->right);

    return dia ;

}

void SumReplacement(node * root){

    int lt = 0;
    int rt = 0;

    if(root->left){
    SumReplacement(root->left);
    lt = root->left->data ; 
    }
    if(root->right){

    SumReplacement(root->right);
    rt = root->right->data ;
    }

    root->data =  lt + rt + root->data;

    return ;

}

// bool isBalanced(node * root){

//     // if(){

//     // }

//     if(isBalanced(root->left) && isBalanced(root->right)){

//         int lh = heightOfBTRecc(root->left);
//         int rh = heightOfBTRecc(root->right);

//         if((abs(lh , rh) <= 1)){
//             return 1;
//         }
//         else{
//             return 0; 
//         }

//     }
//     else{
//         return 0;
//     }

// }

void rightViewOfBT(node * root){

    if(root == NULL){
        cout << "binary tree is empty";
        return ; 
    } 

    queue<node *> q;
    node * front = NULL ; 

    q.push(root);
    q.push(NULL);

    while(true){
        front = q.front();
        q.pop();

        if(front != NULL){

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }

            if(q.front() == NULL){
                cout << front->data << " ";
            }
        }
        else{
            if(q.empty()){
                return ;
            }
            else{
                q.push(NULL);
            }
        }
    }
}

void leftViewOfBT(node * root){

    if(root == NULL){
        cout << "binary tree is empty";
        return ;
    }

    queue<node *> q;
    node * front = NULL ;

    q.push(NULL);
    q.push(root);

    while(true){

        front = q.front();
        q.pop();

        if(front == NULL){
            if(q.empty()){
                return;
            }
            else{
                cout << q.front()->data << " ";

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

int main(){

    /*
        1
        /\
       2   3
      / \  / 
     4  5  6  
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

    // cout << countNodes(root);
    // cout << endl;
    // cout << sumOfAllNodes(root);
    // cout << endl;
    // cout << heightOfBTRecc(root);
    // cout << endl ;
    // cout << diameterOfBT(root);

    rightViewOfBT(root);
    cout << endl ;  
    leftViewOfBT(root);

}