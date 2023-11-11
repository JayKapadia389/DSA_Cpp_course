#include <iostream>
#include <limits.h>

using namespace std;

class stack
{
    int *arr;
    // int arr[3];
    int capacity;
    int top;

public:
    stack(int capacity)
    {
        this->capacity = capacity ;
        arr = new int[capacity];
        this->top = -1;
    }
    void push(int data)
    {
        if (top < capacity -1 )
        {
            this->top = this->top + 1;
            arr[this->top] = data;
            return;
        }
        else
        {
            cout << "Stack overflow!" << endl;
            return;
        }
    }
    int pop()
    {
        if (top > -1)
        {
            top--;
            return arr[top + 1];
        }
        cout << "Stack Underflow!" << endl;
        return INT_MIN;
    }
    int topElem()
    {
        return arr[top];
    }
    int size()
    {
        return top + 1;
    }
    bool empty()
    {
        if (top < 0)
        {
            return true;
        }
        return false;
    }
};

int main(){
    stack st(3);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);                   // overflow
    cout << st.size() << endl;    // 3
    cout << st.empty() << endl;   // 0
    cout << st.topElem() << endl; // 3
    cout << st.pop() << endl;     // 3
    cout << st.topElem() << endl; // 2
    cout << st.size() << endl;    // 2
    cout << st.pop() << endl;     // 2
    cout << st.pop() << endl;     // 1
    cout << st.pop() << endl;     // underflow int min

    return 0;

}