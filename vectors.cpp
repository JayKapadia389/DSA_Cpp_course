#include <iostream>
#include <vector>

using namespace std;

int main(){

    // vector is expandable
    // if length is predefined 
    vector<int> v; 

   v.push_back(1);
   cout << v[0];
   v.pop_back(); // data can be added at defined spots
  
    // length is not defined

    // vector<int> a;

    // a.push_back(1); // data can be added by push_back
    // a.push_back(2);
    // a.push_back(3);
    // a.push_back(7);

    // vector<int>::iterator it;

    // it = v.begin() ; 

    // cout << *it ;
    // cout << *(it+1) ;

    // a.pop_back();
    // a.pop_back();

    cout << v.size()  ;

    // v.pop_back();
    // v.pop_back();

    // cout << v.size() << endl; 
    // cout << v[0] << " " << v[1]<< " " << v[2] << " " << v[3] << " " << v[4] << " " << v[5] << " " << v[6]; 

}