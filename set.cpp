#include <iostream>
#include <set> //in set elements are stored in balanced bst 

using namespace std;

int main(){

    set<int> s ; 
    s.insert(1);
    s.insert(2);
    s.insert(2); // note : no duplicates will be added
    s.insert(6);
    s.insert(9);

    for(auto i : s){
        cout << i << " " ;
    }

    cout << endl ;

    s.erase(2);

    cout << *s.lower_bound(6);

    //multiset - same as set but duplicates are allowed 

}