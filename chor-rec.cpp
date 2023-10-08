#include <iostream>

using namespace std;

maxValue( int arr[][2] , int M , int n , int V){

    if(n == 0 || (M - arr[n-1][0] < 0)){
        return V;
    }

    return max(maxValue( arr , M-arr[n-1][0] , n-1 , V+arr[n-1][1]) , maxValue( arr , M , n-1 , V));

}

int main(){

    int arr[10][2] = {{200 , 100} ,
                     {200 , 100} ,
                    {200 , 150} ,
                    {200 , 100} ,
                    {200 , 100} ,
                    {200 , 100} ,
                    {200 , 100} ,
                    {200 , 3000} ,
                    {200 , 100} ,
                    {200 , 100} 
                     } ;

    cout << maxValue( arr , 1000 ,10 , 0);

}