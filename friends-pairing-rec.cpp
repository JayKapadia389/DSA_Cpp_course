#include <iostream>

using namespace std;

int count = 0;

void pairing(int n){

    if(n==0){
        count=0;
        return;
    }
    else if( n==1){
        count =1;
        return;
    }
    else if( n==2 || n==3){
        count= count + 2;
        return;
    } 
    else{

        pairing(n-1);

        for(int i=0 ; i<n-1 ; i++){
            pairing(n-2);
        }
    }
}

int main(){

    pairing( 4 );

    cout << count ; 
}