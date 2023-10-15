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

void appendLastKAtFirst(node * &head , int k){

    node * first = NULL , * second = NULL;

    for(int i = 0; i < k ; i++){

        if(i == 0){
            second = head;
        }
        else{

            if(second == NULL){
                cout << "length is too short";
                return;
            }
            else{
                second = second -> next ;
            }
        }
    }

    while(second->next != NULL){

        if(first == NULL){
            first = head;
        }
        else{
            first = first->next;
        }

        second = second->next;

    }

    node * temp = first->next;
    first->next = NULL;
    second->next = head;
    head = temp;

    return;
}

void insertCommonNode(node * l1 , node* l2 , int val){

    node * newNode = new node(val);

    node * t1 = l1 , * t2 = l2;

    while(t1 -> next != NULL){
        t1 = t1 -> next;
    }

    while(t2 -> next != NULL){
        t2 = t2 -> next;
    }

    t1->next = newNode ;
    t2->next = newNode ;

    return ;
}

void findIntersection(node * l1 , node * l2){

    node * t1 = l1 , * t2 = l2;

    int c1 = 1 , c2 = 1 ;

    while(t1 -> next != NULL){
        c1++;
        t1 = t1 -> next;
    }

    while(t2 -> next != NULL){
        c2++;
        t2 = t2 -> next;
    }

    if(t1 != t2){
        cout << "no intersection point";
        return;
    }

    int d = (c1 > c2) ? c1 - c2 : c2 - c1 ; 

    t1 = l1 , t2 = l2;

    for(int i= 0 ;  i < d ; i++){

        if(c1> c2){
            t1 = t1 -> next ;
        }
        else{
            t2 = t2 -> next ;
        }
    }

    while(t1 -> next != t2 -> next){
        t1 = t1->next;
        t2 = t2->next;
    }

    cout << t1 -> next -> data ; 
}

node * merge ( node * l1 , node * l2){

    node * temp1 = l1 , * temp2 = l2; 
    node * prev = NULL;
    node * newHead = NULL;

    while(temp1 != NULL || temp2 != NULL){

        if(temp2 == NULL || (temp1 != NULL && (temp1->data < temp2->data)) ){

            if(newHead == NULL){
                newHead = temp1 ;
            }

            if(prev != NULL){
             prev -> next = temp1 ; 
            }
            prev = temp1 ;
            temp1 = temp1->next;
        }
        else if(temp1 == NULL || temp1->data >= temp2->data ){

            if(newHead == NULL){
                newHead = temp2 ;
            }

            if(prev != NULL){
             prev -> next = temp2 ; 
            }
            prev = temp2 ;
            temp2 = temp2->next;
        }
    }  
    return newHead;
}

int main(){

    node * l1 = NULL , * l2 = NULL;

    insertAtTail(l1,1);
    insertAtTail(l1,3);
    insertAtTail(l1,6);
    insertAtTail(l1,8);
    insertAtTail(l1,9);
    insertAtTail(l1,11);

    insertAtTail(l2,2);
    insertAtTail(l2,4);
    insertAtTail(l2,7);
    insertAtTail(l2,10);
    insertAtTail(l2,12);
    insertAtTail(l2,14);

    display(l1);
    display(l2);

    display(merge(l1 , l2));

    // node * newHead = rll( head , NULL , head );
    // findIntersection(l1 , l2);
    // insertCommonNode(l1 , l2 , 13);
    // insertCommonNode(l1 , l2 , 14);
    // insertCommonNode(l1 , l2 , 15);
    // appendLastKAtFirst(head , 8);
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