#include <iostream>

using namespace std;

void wavesort(int * arr , int n){

    for(int i =0; i<n-1 ; i++){

        if( ((i%2==0) && (*(arr+i) < *(arr+i+1))) || ((i%2!=0) && !(*(arr+i) < *(arr+i+1))))
        swap(*(arr+i), *(arr+i+1));
    }

    return;
}

int main(){

    int arr[] = {4,8,2,3,4,6,3,2,6,3};

    wavesort(arr, 10);

    for(int i= 0 ; i<10 ; i++){
        cout << arr[i] << " ";
    }

}



