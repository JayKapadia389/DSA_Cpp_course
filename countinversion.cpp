#include <iostream>

using namespace std;

void merge(int arr[] , int a , int b , int c , int d , int * pc ){

    int temp=0;
    int diff = b-a;
    int diff2 = d-a;
    int x= 0;
    int y=0 ;

    int arr1[diff+1] , arr2[diff+1];

    for(int i = 0 ; i <= diff ; i++){
        arr1[i] = arr[a+i];
    }

    for(int i = 0 ; i <= diff ; i++){
        arr2[i] = arr[c+i];
    }

     for(int i = 0 ; i <= diff2 ; i++){

        if(x > diff){
            arr[a+i] = arr2[y];
            y++;
        }
        else if (y > diff){
            arr[a+i] = arr1[x];
            x++;
        }
        else{

            if(arr1[x] <= arr2[y]){
                arr[a+i] =  arr1[x];
                x++;
            }
            else{
                arr[a+i] =  arr2[y];
                *pc += (b - x + 1);
                cout << *pc << " ";
                y++;
            }

        }

    }

    return;
}

void mergesort(int arr[] , int f ,int l , int * pc){

    if(f == l){
        return;
    }

    else{

        int mid = (f+l)/2;

        mergesort( arr , f , mid , pc );
        mergesort( arr , mid+1 , l , pc );

        merge( arr , f , mid , mid+1 , l , pc);

    }



}

int main(){

    int arr[] = {6,3,9,5,2,8,7,1};
    int c = 0;

    mergesort(arr , 0 , 7 , &c);
    cout << endl;

    cout << c << endl; 

    for(int i =0  ; i< 8 ; i++){
        cout << arr[i] << " ";
    }

}

