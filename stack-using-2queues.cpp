#include <iostream>

using namespace std;

class node{

    public:

    int data ;
    node * next ;

    node(int x){
        data = x ; 
        next = NULL;
    }
};

class queue{

    public:

    node * front , * rear;

    queue(){
        front = NULL ;
        rear = NULL ;
    }

    void enqueue(int x){

        node * newNode = new node(x);

        if(front == NULL){
            front = newNode ;
            rear = newNode ;

            return;
        }

        else{
            rear->next = newNode;
            rear = newNode ;

            return ;
        }
    }

    int dequeue(){

        if(front == NULL){
            return -1;
        }

        int d = front->data;

        node * temp = front;

        front = front->next;

        delete temp;

        return d;
    }
    
};

class stack{

    queue q1 ;
    queue q2 ;

    public:

    void reStack(){

         while(q2.front != NULL){
            q1.enqueue(q2.dequeue());
        }

        return;
    }

    void push(int x){

        q1.enqueue(x);

        return;
    }

    void popFromQueue(){

        int front = q1.dequeue();

        if( q1.front != NULL){

            q2.enqueue(front);
            popFromQueue();
            return;
            
        }
        else{
            return;
        }

    }
    void pop(){

        popFromQueue();
        reStack();

        return;

    }

    void display(){

        if(q1.front == NULL){
            reStack();
            return;
        }

        int front = q1.dequeue();

        cout << front << " ";

            q2.enqueue(front);
            display();
            return;
        
    }

};

int main(){

    stack s1 ;

    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(6);
    s1.push(9);

    s1.pop();

    s1.push(10);
    s1.pop();
    s1.pop();

    s1.push(4);


    s1.display();

}

