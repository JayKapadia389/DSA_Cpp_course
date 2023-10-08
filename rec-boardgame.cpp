#include <iostream>

using namespace std;

int count = 0;

void fun(int m ,int n){

    int diff = n-m;

    if(!diff){
        count++;
        return ;
    }
    else{

        for(int i=1 ; i<=diff ; i++){
            fun(m , n-i);
        }
    }
}

int main(){

    fun( 0 , 8);
    cout << count ;  
}
