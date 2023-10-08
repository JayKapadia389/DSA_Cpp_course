#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v ; 

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int>::iterator it;

    it = v.begin() ; 

    cout << *it ;
    cout << *(it+1) ;

    // v.pop_back();
    // v.pop_back();
    // v.pop_back();

    // cout << v.size() << endl; 
    // cout << v[0] << " " << v[1]<< " " << v[2] << " " << v[3] << " " << v[4] << " " << v[5] << " " << v[6]; 

}