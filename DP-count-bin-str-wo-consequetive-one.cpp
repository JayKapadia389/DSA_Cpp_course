#include <iostream>
#include <map>

using namespace std;

int count(int n , map <int , int > &c){

    if(n == 1){
        return 2 ;
    }
    if(n == 2){
        return 3 ;
    }

    if(c[n]){
        return c[3] ;
    }
    else{
        return c[n] = count(n-1 , c) + count(n-2 , c) ;     
    }

}

int main(){

    map <int , int> c ;
    c[1] = 2;
    c[2] = 3 ;

    int n ;
    cin >> n ;

    cout << count(n , c) ; 


}