#include <iostream>

using namespace std;

class node {

    public:

    int data;
    node * next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node * &head , int val){

    node * newNode = new node(val);

     if(head == NULL){
        head = newNode;
        return;
    }

    node * temp = head;
    // cout << temp << " " << temp->data << " ";

    while(temp->next!=NULL){
        temp = temp->next;
        // cout << temp << " " << temp->data << " ";

    }

    temp->next=newNode;

    // cout << temp->next << " " << temp->next->data << " ";
    // cout << endl;

    return;
}

void insertAtHead(node * &head , int val){

    node * newNode = new node(val);

    newNode->next = head;

    head = newNode;

}

bool search(node * head , int key){

    node * temp = head;

    while(temp!=NULL){
        if(temp->data == key){
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

void display(node * head){

    node * temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

}

void deleteNode(node * &head , int val){

    node *temp1 = head , *temp2 = head;

    if(temp2->data == val){
        head = head->next;
        return;
    }

    else{

        temp1 = temp2;
        temp2 = temp2->next;

        while(temp2 != NULL){

            if(temp2->data == val){
                temp1->next = temp2->next;
                return;
            }

            temp1 = temp2;
            temp2 = temp2->next;

        }

        cout << "given node does not exist";
        return;


    }
}

void reverseLL(node* &head){

    node *t1 = head ;
    node *t2 = t1->next ;
    node *s = t2->next ;

    head->next = NULL;

    while(t2!=NULL){
        t2->next = t1;
        t1 = t2;
        t2 = s;
        if(s != NULL){
          s = s->next;
        }

    }

    head = t1;

    return;

}


node * rll(node * head , node * prev , node * curr){

    node * newHead ;

    if(curr == NULL){
        return prev;
    }

    newHead = rll(head , curr , curr->next);

    curr->next = prev;

    return newHead;
}

int main(){

    node * head = NULL;

    insertAtTail(head,7);
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,1);
    insertAtTail(head,8);

    display(head);

    node * newHead = rll( head , NULL , head );

    display(newHead);

    // reverseLL(head);
    // deleteNode(head , 2);
    // insertAtHead(head , 48);
    // cout << head << " ";
    // insertAtHead(head , 8);
    // cout << head << " ";
    // insertAtHead(head , 442);
    // cout << head << " ";

    // cout << search(head , 7) << endl;
    // cout << search(head , 3) << endl;
    // cout << search(head , 5) << endl;




}