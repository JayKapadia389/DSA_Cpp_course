#include <stdio.h>

int main(){

    int n , temp;

    printf("enter the size of array :");
    scanf("%d" , &n );

    int a[n] , i  ;

    printf("enter the elements to be sorted :");

    for( i = 0 ; i < n ; i++){
        scanf("%d" , &a[i]) ; 
    }

    bool flag = 1 ;

    while(flag == 1){

        flag = 0;

        for(int i = 0 ; i < n-1 ; i++){
            if(a[i] > a[i+1]){
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp ;
            }
        }
    }
}