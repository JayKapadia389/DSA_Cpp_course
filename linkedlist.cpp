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
    cout << endl;

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

int main(){

    node * head = NULL;

    insertAtTail(head,7);
    insertAtTail(head,2);
    insertAtTail(head,5);

    display(head);

    deleteNode(head , 2);

    display(head);

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