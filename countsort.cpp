#include <iostream>
#include <algorithm>

using namespace std;

int * countsort(int arr[] , int n , int sorted[]){

    int mx = 0;

    for(int i =0 ; i < n - 1 ; i++ ){
         mx = max(arr[i],arr[i+1]);
    }

    int countArr[mx+1] = {0};

    for(int i =0 ; i < n ; i++ ){

        countArr[arr[i]]++;
    }

    for(int i = 1 ; i <= mx ; i++ ){

        countArr[i] += countArr[i-1] ;
    }

    for(int i = n - 1 ; i >=0  ; i-- ){

         sorted[--countArr[arr[i]]] = arr[i];
    }


    return sorted;
}

int main(){

    int arr[] = {1 ,3 ,5 ,6 ,2 ,3 ,1 ,8 ,9 , 2};
    int sorted[sizeof(arr)/sizeof(arr[0])] = {0} ;

    int * p = countsort(arr , sizeof(arr)/sizeof(arr[0]) , sorted);

     for(int i =0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++ ){

        cout << *(p++) << " ";
    }

}