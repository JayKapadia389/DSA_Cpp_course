#include <iostream>
#include <vector>

using namespace std;

class node{

    public:

    int data;
    node * left ;
    node * right ;

    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; 

vector<int> LCAcore(node * root , int n1 , int n2){

    vector<int> ans(3) ;

    if(root == NULL){
        ans = {0, 0 , -1};
        return ans ;
    }

    vector<int> lv(3); 
    lv = LCAcore(root->left , n1 ,n2) ;
    vector<int> rv(3); 
    rv = LCAcore(root->right ,n1 ,n2) ; 

    if(lv[2] == -1 && rv[2] == -1){
        if(((lv[0] || lv[1]) && (rv[0] || rv[1])) 
        || ((lv[0] || lv[1]) && (root->data == n1 || root->data == n2)) 
        || ((rv[0] || rv[1]) && (root->data == n1 || root->data == n2))){
            
            ans = {1,1,root->data};

        } 

        else{

            ans = {(lv[0] || rv[0] || root->data == n1) , (lv[1] || rv[1] || root->data == n2) , -1 };

        }

        return ans ;

    }
    else{
        return (lv[2] == -1)? rv : lv ; 
    }

}

int LCA(node * root , int n1 , int n2){

    return LCAcore(root , n1 , n2)[2];

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

    cout << LCA(root , 4 , 9);
}