#include <iostream>

using namespace std;

class node {
    public:

    int data ;
    node * next;

    node(int val){
        data = val;
        next = NULL;
    }
}; 

void insertAtTail(node * &head , int val ){

    node * newNode = new node(val);

    if(head == NULL){
        head = newNode;
        return;
    }

    node * temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    return;
}
void display(node * head){

    node * temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next; 
    }

    return;
}

void createCycle(node * head , int key){

    node * knot = NULL , * temp = head;

    while(temp->next != NULL ){

        if(temp->data == key){
            knot = temp;
        }
        temp = temp ->next;
    }

    if(knot == NULL){
        cout << "key not found";
    }
    else{
        temp->next = knot;
    }

    return;

}

void removeCycle(node * head){

    node * slow = head , * fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast);

    fast = head ;

    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;

    cout << "cycle removed";
}

void detectCycle(node * head){

    node * slow = head->next , * fast =head->next->next;

    while(fast != NULL && fast->next != NULL){

        if(fast == slow){
            cout << "detected a cycle";

            removeCycle(head);
            return;
        }

        fast = fast->next->next;
        slow = slow->next;

    }

    cout << "cycle not detected";

    return;
}

int main(){

    node * head = NULL;

    insertAtTail(head , 3); 
    insertAtTail(head , 4); 
    insertAtTail(head , 8); 
    insertAtTail(head , 1); 
    insertAtTail(head , 9); 
    insertAtTail(head , 0);


    display(head) ;

    createCycle(head , 1);

    detectCycle(head);

    display(head);



}