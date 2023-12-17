#include <stdio.h>
#define N 5

struct node {
    int data;
    struct node * link ;
};

struct queue {
    struct node * front ;
    struct node * rear ;
    int count ;
};

void enqueue(struct queue * q , int val){

    if(q->count == N){
        printf("overflow\n");
        return ;
    }

    struct node * newNode = malloc(sizeof(struct node));
    newNode->data = val ;
    newNode->link = NULL ;

    (q->count)++ ;

    if(q->front == NULL){
        q->front = newNode ;
        q->rear = newNode ;

        return ;
    }

    q->rear->link = newNode ;
    q->rear = newNode ;
    return ; 
}

void dequeue(struct node * q ){

    if(q->count == 0){
        printf("underflow\n");
        return ;
    }

    struct node * temp = q->front ;

    printf("%d" , q->front->data);

    q->front = q->front->link ;

    free(temp);

    if(q->count == 1){
        q->rear = NULL ;
    }

    (q->count)-- ;

    return ;
}



int main(){

    struct queue q1 ;
    q1.front = NULL ;
    q1.rear = NULL ;
    q1.count = 0 ;

    enqueue(&q1 , 5 );


}