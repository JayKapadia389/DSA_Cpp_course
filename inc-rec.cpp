#include <iostream>

using namespace std ;

void dec( int n){

    cout << n << " ";

    if(n != 1){
        dec(n-1);
    }
}

void inc( int n){


    if( n != 1){
        inc(n-1);
    }

    cout << n << " " ; 
}

int main(){

    int n ;

    cin >> n ;

    inc(n);
    cout << "\n";
    dec( n );
}