#include <iostream>

using namespace std;

int count = 0 ;

void fun( int n){

    if(n==0 || n==1){
        count ++;
        return ;
    }
    else{
        fun(n-1);
        fun(n-2);
    }
}

int main(){

    fun( 4 );

    cout << count ;
}