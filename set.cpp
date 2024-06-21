#include <iostream>
#include <vector>
#include <set> //in set elements are stored in balanced bst 

using namespace std;

int main(){

    set<vector<int>> s ; 
    s.insert({86,324});
    s.insert({32,2374});
    s.insert({424,34}); // note : no duplicates will be added
    s.insert({6,23});
    s.insert({9,242424});

    for(auto i : s){
        cout << i[0] << " " << i[1] << endl ;
    }

    //multiset - same as set but duplicates are allowed 

}