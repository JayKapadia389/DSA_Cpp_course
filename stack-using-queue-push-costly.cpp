#include <iostream>
#include <queue>
#define N 5

using namespace std;

class stack{

    queue<int> q1 ;
    queue<int> q2 ; 

    public:

    void display(){

        if(q1.size() == 0){
            cout << endl << "stack is empty" << endl ; 
            return;
        }

        while(!q1.empty()){
            cout << q1.front() << " ";

            q2.push(q1.front());

            q1.pop();
        }

        cout << endl ; 

        while(!q2.empty()){
            q1.push(q2.front());

            q2.pop();
        }

        return;
    }

    void push(int x){

        if(q1.size() == 5){
            cout << endl << "stack overflow" << endl ; 
            return; 
        }

        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());

            q1.pop();
        }

        while(!q2.empty()){

            q1.push(q2.front());
            q2.pop();
        }

        return;

    }

    void pop(){

        if(q1.size() == 0){
            cout << endl << "stack underflow" << endl ; 
            return;
        }
        q1.pop();

        return;
    }

};

int main(){

    stack s1;

    s1.push(2);
    s1.display();

    s1.push(2);
    s1.display();

    s1.push(2);
    s1.display();

    s1.push(2);
    s1.display();

    s1.push(2);
    s1.display();

    s1.push(2);

    s1.pop();
    s1.display();

    s1.pop();
    s1.display();

}