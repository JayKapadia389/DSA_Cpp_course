#include <stdio.h>
#define N 5

struct stack
{
    int a[N] ;
    int top ;
};

void push(struct stack *s , int val){

    if(s->top == N-1){
        printf("stack overflow");
        return ;
    }

    (s->top)++ ;  

    (s->a)[s->top] = val ;
    return ; 
}

void pop (struct stack *s ){

    if(s->top == -1){
        printf("stack underflow");
        return ;
    }

    printf("%d" , (s->a)[s->top]) ; 

    (s->top)-- ;
    return ; 
}

void display(struct stack s){

    for(int i = 0 ; i <= s.top ; i++){

        printf("%d " ,s.a[i]);
    }

    return ;
}

int main(){

    struct stack s1 ; 
    s1.top = -1 ;

    push(&s1 , 1);
    push(&s1 , 2);
    pop(&s1);
    printf("\n");
    pop(&s1);
    printf("\n");
    pop(&s1);
    printf("\n");

    display(s1);


}