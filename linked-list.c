#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ;
    struct node * next ;
};

void insertAtFirst(struct node ** headsPtr ,int val){

    struct node * newNode = malloc(sizeof(struct node));
    newNode->data = val ; 

    if(*headsPtr == NULL){
        *headsPtr = newNode ;
        (*headsPtr)->next = NULL ;
        return;
    }

    newNode->next = *headsPtr ;
    *headsPtr = newNode ;
    return ;

}

void insertAtLast(struct node ** headsPtr ,int val){

    struct node * newNode = malloc(sizeof(struct node));
    newNode->data = val ; 
    newNode->next = NULL ;

    if(*headsPtr == NULL){
        *headsPtr = newNode ;
        return;
    }

    struct node * temp = *headsPtr;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode ;
    return ;

}

void insOrder(struct node ** headsPtr , int val){

    struct node * newNode = malloc(sizeof(struct node));
    newNode->data = val ; 

    //if empty

    if(*headsPtr == NULL){
        newNode->next = NULL;
        *headsPtr = newNode ;
        return ;
    }

    //if first 
    if(val <= (*headsPtr)->data){
        newNode->next = *headsPtr;
        *headsPtr = newNode ; 
        return;
    }
    else{

    struct node * temp = *headsPtr ;

    while((temp->next->data < val) && (temp -> next != NULL)){
        temp = temp->next ;
    }

        if(temp->next == NULL){
            temp->next = newNode ;
            newNode->next = NULL ;
            return ;
        }
        else{

            newNode->next = temp->next;
            temp->next = newNode;
            return;

        }
    }

}

void printLL(struct node * head){
    
    struct node * temp = head ; 

    while(temp != NULL){
        printf("%d " , temp->data);
        temp = temp->next;
    }

    return;
}

int main(){

    struct node * head = NULL ;

    insertAtFirst(&head , 3);
    insertAtFirst(&head , 2);
    insertAtFirst(&head , 1);
    insertAtLast(&head , 6);
    insertAtLast(&head , 7);
    insOrder(&head , 4);
    insOrder(&head , 5);

    printLL(head);
}