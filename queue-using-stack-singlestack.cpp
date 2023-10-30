#include <iostream>
#include <stack>

using namespace std;

class queue{

    stack<int> st ; 

    public:

    void enqueue(int x){

        st.push(x);
        return;
    }

    void dequeue(){


        int top = st.top();
        cout << top << " 1";

        st.pop();

        if(st.empty()){
            cout << "2";
            return;
        }

        dequeue();

        st.push(top);

        return;
    }

    void peep(){
        int top = st.top();

        st.pop();

        if(st.empty()){
            cout << top << endl;
            return;
        }

        dequeue();

        st.push(top);

        return;
    }
};

int main(){

    queue q;

    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(1);
    q.enqueue(0);

    q.dequeue();

    q.peep();
    
}