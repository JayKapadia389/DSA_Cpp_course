#include <iostream>

using namespace std;

void swap(int * a , int * b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b ;
}

void dnfsort(int * arr , int n){

    int low = 0;
    int mid = 0;
    int high = n;

    while(mid != high){

        switch (*(arr+mid)){

            case 0:
            swap(arr+low , arr+mid);
            low++;
            mid++;
            break;

            case 1:
            mid++;
            break;

            case 2:
            --high;
            swap(arr+mid , arr+high);
            break;

        }
         
    }

}

int main(){

    int arr[] = {2,2,2,2,0,0,2,1,0,1};

    dnfsort( arr , 10);

    for(int i=0 ; i<10 ;i++){
        cout << arr[i] << " ";
    }

}