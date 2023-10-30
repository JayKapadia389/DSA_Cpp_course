#include <iostream>
#include <stack>

using namespace std;

class queue{

    stack<int> s1 , s2;

    public:

    void enqueue(int x){
        s1.push(x);
        return;
    }

    void dequeue(){

        while(!s1.empty()){
            s2.push(s1.top());

            s1.pop();
        }

        s2.pop();

        while(!s2.empty()){
            s1.push(s2.top());

            s2.pop();
        }

        return ; 
    }

    void peep(){

        while(!s1.empty()){
            s2.push(s1.top());

            s1.pop();
        }

        cout << s2.top();
        
         while(!s2.empty()){
            s1.push(s2.top());

            s2.pop();
        }

        return;

    }

} ;

int main(){

    queue q ;

    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(1);
    q.enqueue(0);

    q.dequeue();

    q.peep();


}