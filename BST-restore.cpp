#include <iostream>
#include <vector>

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

void inOrderPrint(node * root){

    if(root == NULL){
        return ;
    }

    inOrderPrint(root->left);

    cout << root->data << " ";

    inOrderPrint(root->right);

    return ; 
}

void populateVector(node * root , vector<int> &inOrder){
    if(root == NULL){
        return ;
    }

    populateVector(root->left , inOrder);

    inOrder.push_back(root->data);

    populateVector(root->right , inOrder);

    return ; 
}

void verifyNodes(node * root , vector<int> inOrder){

    static int i = -1 ; 
    if(root == NULL){
        return ;
    }

     verifyNodes(root->left , inOrder);

     i++ ;
     
     if(root->data != inOrder[i]){
        root->data = inOrder[i];
     }

     verifyNodes(root->right , inOrder);

    return ; 
}

void restoreBST(node * root){

    vector<int> inOrder ;

    populateVector(root , inOrder);

    if(inOrder.size() <= 1){
        return ;
    }
    else{
        int first = -1 ;
        int mid = -1 ;
        int last = -1 ;
        bool f = true ;

        for(int i = 0 ; i < inOrder.size()-1 ; i++){

            if(inOrder[i] > inOrder[i+1]){

                if(f){
                    first = i;
                    mid = i+1 ;
                    f = 0 ; 
                }
                else{
                    last = i+1;
                }
            }
        }

        int temp ;

        if(last == -1){
            temp = inOrder[first];
            inOrder[first] = inOrder[mid];
            inOrder[mid] = temp;

        }
        else{
            temp = inOrder[first];
            inOrder[first] = inOrder[last];
            inOrder[last] = temp;
        }


    }

    verifyNodes(root , inOrder);
}

int main(){

    /*

          5
        /   \
       3      7
        \    / \
         8   6  4

          5
        /   \
       3      7
        \    / \
         4   6  8 

    */

   node * root = new node(5);

   root->left = new node(3);
   root->right = new node(7);

//    root->left->left = new node(2);
   root->left->right = new node(8);
   root->right->left = new node(6);
   root->right->right = new node(4);

   restoreBST(root);

   inOrderPrint(root);

}