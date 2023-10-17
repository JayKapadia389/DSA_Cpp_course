#include <iostream>

using namespace std;

#define n 5

class stack {

    int arr[n];
    int top = -1 ;

    public:

    void push(int val){

        if(top == n-1){
            cout << "stackoverflow";
            return;
        }

        arr[++top] = val ;
        return;
    }

    int pop(){

        if(top == -1){
            cout << "no elements to return";
            return 0;
        }

        return arr[top--];
    }

    bool isEmpty(){

        return top == -1;
            
    }

    int Top(){

        if(top == -1){
            cout << "stack is empty";
            return 0 ;
        }
        else{
            return arr[top];
        } 
    }

};

int main(){

    stack s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    cout << s1.pop() ;
    cout << s1.pop() ;
    cout << s1.pop() ;

    cout << s1.isEmpty();

    cout << s1.pop();
    cout << s1.pop();

    cout << s1.isEmpty();

    cout << s1.pop();



}