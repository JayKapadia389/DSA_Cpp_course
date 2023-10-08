#include <iostream>
#include <cmath>

using namespace std;

int unique( int arr[] , int n){

    int bits[64] = {0};
    int ans = 0 ;

    for(int i = 0 ; i < n ;i++){

        for( int j = 0 ; j < 64 ; j++){

            if(arr[i] & ( 1 << j)){
                bits[j]+=1;
            }
        }
    }

    for(int i=0 ; i < 64 ;i++){

        ans += (bits[i]%3) * pow(2 , i);
        cout << ans << " " ;
    }

    cout << endl;

    return ans;
}

int main(){

    int arr[10] = { 2,9,6,2,9,2,7,6,9,6} ;
    int a = pow(2 , 32 );

    // cout << unique( arr , 10);

    cout << a;

}