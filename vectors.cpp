#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v(3) ; 

    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    // vector<int>::iterator it;

    // it = v.begin() ; 

    // cout << *it ;
    // cout << *(it+1) ;

    cout << v[0] << v[1] << v[2] << v[3];

    // v.pop_back();
    // v.pop_back();
    // v.pop_back();

    // cout << v.size() << endl; 
    // cout << v[0] << " " << v[1]<< " " << v[2] << " " << v[3] << " " << v[4] << " " << v[5] << " " << v[6]; 

}