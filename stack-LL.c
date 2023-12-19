#include <stdio.h>
#include <stdlib.h>
#define N 5

struct node{
    int data ;
    struct node * next ;
};

struct stack{

    struct node * top ;
    int count ;  
};

void push(struct stack * s , int val){

    if (s->count == N){
        printf("stack overflow");
        return ;
    }
    
    struct node * newNode = malloc(sizeof(struct node));

    newNode->data = val ;
    newNode->next = s->top ;
    s->top = newNode ; 
    (s->count)++ ;
    return ;
}

void pop(struct stack *s ){

    if(s->top == NULL){
        printf("stack underflow");
        return ;
    }

    printf("%d " , s->top->data) ; 
    struct node *del = s->top ;
    s->top = s->top->next ;
    free(del);
    (s->count)-- ;
    return ;
}

void display(struct stack s){

    struct node * temp = s.top ;

    while(temp != NULL){
        printf("%d " , temp->data);
        temp = temp->next ;
    }

    return ;
}

int main(){

    struct stack s1 ;
    s1.top = NULL ;
    s1.count = 0 ;

    push(&s1 , 1);
    push(&s1 , 2);
    pop(&s1);
    printf("\n");
    push(&s1 , 3);
    push(&s1 , 4);

    display(s1);


}