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

bool findPathCore(node * root , int n , vector<int> &path){

    if(root==NULL){
        return 0;
    }

    path.push_back(root->data);

    if(n == root->data || findPathCore(root->left , n , path) || findPathCore(root->right ,n , path)){
        return 1;
    }
    else {
        path.pop_back();
        return 0 ;
    }
}

vector<int> findPath(node * root , int n1){

    vector<int> path;

    if( findPathCore(root , n1 , path) ){
        return path;
    } 
    
}

int shortestDistance(node * root , int n1 , int n2){

    vector<int> v1 , v2;
    v1 = findPath(root , n1);
    v2 = findPath(root , n2);

    int c = 0 ;

    for(int i = 0 ; i < v1.size() && i < v2.size() ; i++){

        if(v1[i] == v2[i]){
            c++;
        }
        else{
            break;
        }

    }

    return (v1.size() + v2.size() - 2*c) ;

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

    cout << shortestDistance(root , 2,9 );
}