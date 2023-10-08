#include <iostream>

using namespace std;

int gcd( int a , int b){

    int c = 1, gcd = 0;

    while(c!=0){

        gcd = c; 
        c = a%b ;
        a = b;
        b = c ; 
    }

    return gcd ;
}

int main(){

    int n , m ;
    cin >> n >> m;

    cout << gcd(n,m);
}