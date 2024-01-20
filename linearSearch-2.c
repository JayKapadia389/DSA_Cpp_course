#include <stdio.h>

int main(){

    int n , i;

    printf("enter the nnumber of elements : ");
    scanf("%d" , &n);

    int arr[n] ;

    for(i = 0 ; i < n ; i++){
        scanf("%d" , &arr[i]);
    }

    int key ;

    printf("enter key");
    scanf("%d" , &key);

    for(i = 0 ; i < n ; i++){
        if(arr[i] == key){
            printf("index is : %d" , i) ;
            break ;           
        }
    }

    if(i == n){
        printf("not found");
    }

}