#include <iostream>
#include <map>

using namespace std;

int fibonnaci(int n , map<int, int> &fib){

    if(n == 1){
        return 0; 
    }
    if(n == 2){
        return 1 ;
    }

    if(fib[n-1] == 0){
        fib[n-1] = fibonnaci(n-1,fib) ;
    }
    if(fib[n-2] == 0){
        fib[n-2] = fibonnaci(n-2 ,fib) ;
    }

    return (fib[n-1] + fib[n-2]) ;
}

int main(){

    map<int,int> fib ;
    fib[1] = 0;
    fib[2] = 1;
    
    int n ; 

    cin >> n ;

    cout << fibonnaci(n , fib);
}