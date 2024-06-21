#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){

    int n ;
    map<int , int > m ;

    cout << "enter the number of elements :" ;

    cin >> n ;

    vector<int> v(n) ;

    cout << "enter the elements:" ;

    for(int i = 0 ; i< n ; i++){
        cin >> v[i] ;
    }

    for(int i = 0 ; i < n ; i++){
        m[v[i]]++ ;
    }

    map<int , int > :: iterator it ;

    for(it = m.begin() ; it != m.end() ; it++){
        cout << it->first << " " << it->second << endl ;
    }


}