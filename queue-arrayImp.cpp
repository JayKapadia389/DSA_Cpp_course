#include <iostream>

using namespace std;

class queue{

    int arr[100] ; 
    int front = -1 , back = -1 ; 

    public:

    void enqueue(int x){

        if(front == -1)
        front++;

        if(back != 99){
            arr[++back] = x;
        }
        else{
            cout << "queue is full";
        }
        return ; 
    }

    void dequeue(){

        front ++;
        return;
    }

    int peep(){

        return arr[front];
    }

    bool isEmpty(){

        if((front == -1 && back == -1) || (front > back)){
            return 1;
        }
        else{
            return 0;
        }
    }

};

int main(){

    queue q1 ;

    q1.enqueue(2);
    q1.enqueue(4);
    q1.enqueue(6);
    q1.enqueue(9);

    cout << q1.peep() << " ";
    q1.dequeue();
    cout << q1.peep() << " ";
    q1.dequeue();
    cout << q1.peep() << " ";
    q1.dequeue();
    // cout << q1.peep() << " ";
    // q1.dequeue(); 

    cout << endl << q1.isEmpty();

}