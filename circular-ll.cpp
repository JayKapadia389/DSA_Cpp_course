#include <iostream>

using namespace std;

class node{

    public : 

    int data;
    node * next;

    node(int val){
        data = val;
        next = NULL;
    }
} ;

void insertNode(node * &head , int val){

    node * newNode = new node(val);

    if(head == NULL){
        head = newNode;
        head ->next = head;
        return;
    }

    node * temp = head ; 

    while(temp->next != head){
        temp = temp ->next;
    }

    temp->next = newNode ;
    newNode->next = head;
    return;
}

void display(node * head){

    node * temp = head ;

    do{
        cout << temp->data << " ";
        temp = temp->next ;
    }while(temp != head);

    cout << endl;

    return ;
}

void deleteNode(node * &head ,int key ){

    node * prev = head ,* curr = head ;

    if(head->data == key){

        if(head->next == head){
            delete head ;
            head = NULL;
            return; 
        }
        else{
            node * temp = head;

            while(temp->next != head){
                temp = temp->next;
            }

            temp->next = head->next ; 
            head = head->next ;
            return;
        }

    }

    while(curr->data != key){
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next ;

    delete curr ;
}

int main(){

    node * head = NULL ;

    insertNode(head , 3);
    insertNode(head , 2);
    insertNode(head , 7);
    insertNode(head , 9);
    insertNode(head , 8);
    insertNode(head , 1);

    display(head);

    deleteNode(head , 3);
    display(head);
    deleteNode(head , 2);
    display(head);
    deleteNode(head , 7);
    display(head);
    deleteNode(head , 9);
    display(head);
    deleteNode(head , 8);
    display(head);
    deleteNode(head , 1);
    display(head);

}