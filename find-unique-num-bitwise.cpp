#include <iostream>

using namespace std;

int main(){

    int arr[] = {2,4,6,3,4,6,2,7};

    bool flag = 0;

    for(int i=0 ; i< 8 ; i++){

        flag = 0;
        for(int j=0 ; j< 8 ; j++){
            if(i == j){

            }
            else{
                if((arr[i] ^ arr [j]) == 0){
                    flag = 1;
                    break;
                }
            }
        }

        if(flag == 0){
            cout << arr[i] << " ";
        }
    }

    // int xorsum = 0;
    // for(int i= 0 ; i< 7 ; i++){
    //     xorsum += arr[i];
    // }
    // cout << xorsum ; 

}