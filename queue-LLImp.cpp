#include <iostream>

using namespace std;

class node{

    public :

    int data;
    node * next ; 

    node(int x){

        data = x;
        next = NULL;
    }

};

class queue {

    node * front  , * back  ;

    public :

    queue(){
        front = NULL ; 
        back = NULL ; 
    }

    bool isEmpty(){
        return front == NULL;
    }

    void enqueue(int x){

        node * newNode = new node(x);

         if(isEmpty()){
            front = newNode;
            back = newNode;
        }
        else{

            back->next = newNode ;
            back = newNode ;
        }

        return;

    }

    void dequeue(){

        if(isEmpty()){
            cout << "no elements";
        }
        else if(front == back){
            delete front;

            front = NULL;
            back = NULL;

        }
        else{
            node *prev =front;
            front = front->next;
            delete prev;
        }

        return;

    }

    void peep(){

        if(isEmpty()){
            cout << "queue is empty";
            return ;
        }
        else{
            cout << front->data << " ";
        }
    }
};

int main(){

    queue q ;

    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(9);

    q.peep();
    q.dequeue();
    q.peep();
    q.dequeue();
    q.peep();
    q.dequeue();
    q.peep();
    q.dequeue();
    q.peep();



}