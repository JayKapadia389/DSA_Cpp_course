#include <stdio.h>

int main(){

    int n ;

    printf("enter the length of array : ");
    scanf("%d" , &n);

    int a[n] , i , j;

    printf("enter elements to be sorted : ");

    for(i = 0 ; i < n ; i++){
        scanf("%d" , &a[i]);
    }

    int start , min , temp;

    for( i = 0 ; i < n-1 ; i++){

        min = start ;

        for(j = min +1 ; j <n ; j++){
            if(a[j] < a[min]){
                min = j ;
            }
        }

        temp = a[start] ;
        a[start] = a[min] ;
        a[min] = temp ;

        start++ ;
    }

    for(i = 0 ; i < n ; i++ ){
        printf("%d " , a[i]);
    }

}