#include <stdio.h>

int main(){

    int n , i ;

    printf("enter num of elements : ");
    scanf("%d" , &n);

    int a[n] ; 

    printf("enter elements in sorted order :");

    for( i = 0 ; i < n  ; i++){
        scanf("%d" , &a[i]);
    }

    int l = 0 , r = n-1 , mid ,ans ;

    printf("enter key :");

    while(l <= r){

        mid = (l+r)/2;

        if(a[mid] == key){
            ans = mid ;
            break ; 
        }
        else if(a[mid] > key ){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    if(l<= r){
        printf("the index is %d" , ans);
    }
    else{
        printf("not found");
    }
}