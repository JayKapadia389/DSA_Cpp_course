#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <stack>

using namespace std ;

set<int> fun(vector <int> v){

   set<int> s;

   for(int i = 0 ; i < v.size() ; i++){

       s.insert(v[i]);       
   }

   return s ;

}

int main(){

    stack<string> st ;

   // cout << static_cast<int>('-') << static_cast<int>('+') << static_cast<int>('*') << " " << static_cast<int>('/');

   // string s = "jay";

   // int i = -1 ; 

   // int  arr[] = {0};
   // int  arr[7];

   // queue<int> q ;

   // q.push(2);
   // q.push(3);
   // q.push(5);

   // cout << q.size();

   // int * arr = new int[20];

   // *arr = 10;
   // arr[] = {10};

   // for(int i = 0 ; i < 10 ; i++){
   //    cout << arr[i] << " ";
   // }

   // for(int i = 0 ; i < 256 ; i++){

   //    cout << static_cast<char>(i) << endl;
   // }

   vector<int> v = {1,2,3,7,8};

   set<int> s = fun(v);
   set<string> num= {"1" , "s" , "dh"};

   for(auto i : s){
        cout << i << " " ;
    }

    cout << endl ;

    s.erase(7);

    for(auto i : s){
        cout << i << " " ;
    }

}