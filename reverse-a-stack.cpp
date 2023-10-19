#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &st , int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }

    int stackTop = st.top();
    st.pop();

    insertAtBottom(st , ele);
}

void reverseStack(stack<int> &st){

    if(st.empty()){
        return;
    }

    int stackTop = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st , stackTop);

}

int main(){

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    for(int i=0 ; i<5 ; i++){
        cout << st.top() ;
        st.pop(); 
    }

}