#include <stdio.h>

int main(){

    int arr[8] , i , key;

    for(i=0 ; i<8 ; i++){
        printf("enter %d number: " , i+1); 
        scanf("%d", arr+i);
    }

    printf("enter key : ");
    scanf("%d" , &key);

    for(i=0 ; i<8 ; i++){

        if(arr[i] == key){
            printf("element number is %d" , i+1);
            break;
        }
    }

    return 0;

}