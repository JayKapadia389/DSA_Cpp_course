#include <iostream>

using namespace std;

void merge(int arr[] ,int a , int b , int c , int d){

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
                y++;
            }

        }

    }
    
    for(int i=0 ; i<8 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return;
}

void ms( int arr[] , int  f , int  l){

    int mid = (f + l)/2;

    if(f == l){
        return;
    }

    else{
        ms(arr , f , mid);
        ms(arr , mid+1 , l);
    
        cout << f << " " << mid << " " << mid+1 << " " << l << endl;
        merge(arr ,f,mid,mid+1,l); 

        return;   
    }

}

int main(){

    int arr[8] = {1,4,1,3,9,2,2,5};

    ms(arr , 0 , 7);

    for(int i=0 ; i<8 ; i++){
        cout << arr[i] << " ";
    }


}