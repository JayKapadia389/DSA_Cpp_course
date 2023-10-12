#include <iostream>

using namespace std;

class node{
    public:

    int data;
    node * next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node * &head , int val ){

    node * newNode = new node(val);

    node * temp = head;

    if(head == NULL){
        head = newNode;
    }

    while(temp!= NULL){

        if(temp->next == NULL){
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return;
}

void display(node * head){

    cout << "dis";
    
    node * temp = head;

    while(temp != NULL){

        cout << temp->data << " ";
        temp = temp->next;
    }

    return;
}

void reverseInK(node * &head , int n , int k){

    cout << "i";

    node * temp = head;

    for(int i = 1 ; i< n ; i++){
        temp = temp -> next;
    }

    for(int i=1 ; i<k ; i++){
        if(temp->next == NULL){
            cout << "2";
            return;
        }
        temp = temp->next;
    }

    node * prev = NULL , * curr = head ,* next = NULL , * mark = NULL;

    for(int i = 1 ; i< n ; i++){
        curr = curr -> next;
    }

    next = curr ->next;

    for(int i = 1; i<=k ; i++){

        cout << "1";

        if(i==1){
            mark = curr;
        }

        if(n==1 && i==k){
            head = curr;
        }

        curr->next = prev; 

        prev = curr;
        curr = next;
        next = next->next;

    }

    if(next == NULL){
        cout << "3";
        return;
    } 
    else{
        mark->next = next;
    }


    reverseInK(head , n+k , k );

}

int main(){

    node* head =NULL;
    int k;

    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtTail(head,1);
    insertAtTail(head,8);

    display(head);

    cout << endl << "enter value of k:";
    cin >> k;

    reverseInK(head , 1 ,k);

    display(head);

}