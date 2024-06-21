/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <map>
#include <vector>

class node{
public :
    int val ;
    node * next ;

    node(int val){
        this->val = val ;
        next = NULL ;
    }
};

map< pair<int ,int> , node *> createHM(TreeNode * root , int c , int r  ){

    static map< pair<int ,int> , node *> m ;

    if(root == NULL){
        return m ;
    }

    node * newNode = new node(root->val) ;
    cout << root->val << endl;

    if(m[{c , r}] == NULL){
        m[{c , r}] = newNode ;
    }
    else{
        node * temp = m[{c , r}] ;

        if(temp->val >= newNode->val){
            m[{c , r}]=newNode ;
            newNode->next = temp ;
        }
        else{

            while( temp->next != NULL && temp->next->val < newNode->val){
                temp = temp->next ;
            }

            if(temp->next == NULL){
                temp->next = newNode ;
            }
            else{
                newNode->next = temp->next ;
                temp->next = newNode ;
            }

        }

    }

    createHM(root->left , c-1 , r+1);
    createHM(root->right , c+1 , r+1);

    return m;

}


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        vector<int> col ;

        map<pair<int , int> , node *> m = createHM(root , 0 , 0) ;

        map<pair<int , int> , node *> :: iterator it ;

        int prev ;

        for(it = m.begin() ; it != m.end() ; it++){

            if(it == m.begin()){
                prev = it->first.first ;
            }

            else if(it != m.begin() && it->first.first != prev){
                ans.push_back(col);

                col.clear();

                prev = it->first.first ;
            }

            node * temp = it->second ;

            while(temp != NULL){

                cout << "{" << it->first.first << "," << it->first.second <<"}" << "  " << temp->val<< endl ;

                col.push_back(temp->val);
                temp = temp->next ;
            }

        }

            if(!col.empty()){
                ans.push_back(col);
            }

        return ans ;   

    }
};

