#include <iostream>

using namespace std ;

int main(){

    int arr[8] = {1,4,3,1,3,4,5,2};

    int n=8 ,i=0 , xorsum=0 ,newxor=0;

    for(int x=0 ; x<n ; x++){

        xorsum = xorsum ^ arr[x];
    }

    while(true){

        if(xorsum & (1 << i)){
            break;
        }

        i++;
    }

    for(int j=0 ; j<n ; j++){

        if(arr[j] & (1 << i)){
            newxor = newxor ^ arr[j];
        }

    }

    cout << newxor << " " << (newxor ^ xorsum); 

}
