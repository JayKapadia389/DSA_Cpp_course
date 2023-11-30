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

bool findPathCore(node * root , node * key , vector<int> &path){

    if(root==NULL){
        return 0;
    }

    path.push_back(root->data);

    if(key == root || findPathCore(root->left , key , path) || findPathCore(root->right , key , path)){
        return 1;
    }
    else {
        path.pop_back();
        return 0 ;
    }
}

vector<int> findPath(node * root , node * key){

    vector<int> path;

    if( findPathCore(root , key , path) ){
        return path;
    } 
    
}

void nodesAtDisK(node * root , node * key , node * k ){

    vector<int> path;
    path = findPath(root , key );
    

    for(int i = 0 ; i < k   ; i++){

        if(i == path.size() - 1){
            fun(root ,-1 , k- i);
        }
        else{
            fun(root , v[v.size() - 1 -i] , k-i);
        }
    }

    return;

}

void fun(node * root , int avoid , int d){

    if(d == 0){
        cout << root->data << " ";
        return ;
    }
    else{

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

}