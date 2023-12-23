#include <iostream>
#include <map>

using namespace std ;

class node{
    public :
    int data ;
    node * next ;

    node(int data){
        this->data = data ;
        next = NULL ;
    }
};

map<int ,int> fun(int n){

    static map<int , int > m ;

    if(n == 0){
        cout << "done";
        cout << m[1] ;
        return m;
    }

    m[n] = n ;

    fun(n-1);

    return m;
}

int main(){

    // map<pair<int , int> , int> m ;

    // node * newNode = new node(3) ;

    // m[{0,0}] = 1 ;
    // m[{0,1}] = 2 ;
    // m[{1,0}] = 3 ;
    // m[{1,1}] = 4 ;

    // map<pair<int , int> , int> :: iterator it ;
    map<int , int> :: iterator newit ;


    // for(it = m.begin() ; it != m.end() ; it++){
    //     cout << it->second << " " ;
    // }

    // cout << endl ;

    // cout << m[{1,2}] ;

    map<int , int> newMap = fun(5);

    // cout << " 3";

    cout << newMap.size();

    for(newit = newMap.begin() ; newit != newMap.end() ; newit++){
        cout << newit->second << " " ;
    }
}