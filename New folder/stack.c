#include <stdio.h>

int arr[5] ={0};
int * top =arr-1;
int * ls = arr + 4 ; 
int * ft = arr ; 

void PUSH(int value){

    int i;

    if( top+1 > ls ){
        printf("stack overflow\n");
    }
    else{
        *(++top) = value;

        for( i=0 ; i < 5 ; i++ ){
        printf("%d " , arr[i]);
          }
         printf("\n");
    
    }

    return;

}

void POP(){
    int i;

    if( top-1 < ft-1 ){
        printf("stack underflow\n");
    }

    else{
        *(top--) = 0 ;

        for( i=0 ; i < 5 ; i++ ){
        printf("%d " , arr[i]);
          }
         printf("\n");
    }

    return;
    
}

void PEEP(){

        printf("%d",*top);

}

int main(){

    PUSH(6);
    PUSH(18);
    PUSH(17);
    PEEP();
    POP();
    POP();

    
    
}