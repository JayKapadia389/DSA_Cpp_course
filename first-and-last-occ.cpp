#include <iostream>

using namespace std;

void flocc( int arr[] , int n , int m, int*pa , int*pb){

    if(n == 1 ){

        if(arr[0] == m){
            *pa = 0;
            *pb = 0;
        }
        else{
            *pa = -1;
            *pb = -1;
        }
        
    }
    else{

        flocc(arr ,n-1 , m , pa , pb);

        if(arr[n-1] == m){

            if(*pa == -1){
                *pa = n-1;
                *pb = n-1;
                return;
            }
            else{
                *pb = n-1;
                return ;
            }
        }

        else{
            return;
        }
    }
}

int main(){

    int arr[8] = {4 ,2 ,5 ,6 ,2 ,4 ,2 , 4} ; // 1 6
    int a,b ;
    int * pa = &a, * pb = &b;

    flocc( arr , 8 , 2 , &a , &b);

    cout << a <<" " << b;

}