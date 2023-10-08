#include <iostream>

using namespace std;

int getPivot(int arr[] , int f , int l){

    int pivot = arr[l];
    int i=f-1 , temp ;

    cout << "1 ";

    for(int j = f ; j < l; j++){

        if(arr[j] < pivot){
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[i] = temp;

        }

    }
        temp = arr[i+1];
        arr[i+1] = arr[l];
        arr[l] = temp;

        return i+1;

}

void quicksort(int arr[] , int f , int l){

    if( f<l){
        int pi = getPivot(arr , f, l);

        quicksort(arr , f , pi-1);
        quicksort(arr , pi+1 , l);
    }

}

int main(){

    int arr[]= { 4,6,3,8,2,9,1,7};

    quicksort(arr , 0 , 7);

    for( int i=0 ; i< 8 ; i++){
        cout << arr[i] << " ";
    }

    
}
