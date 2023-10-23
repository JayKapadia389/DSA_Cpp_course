#include <iostream>
#include <stack>
// #include <string>

using namespace std;

void isBalanced(string s){

    stack<char> st ; 

    for(int i=0 ; i < s.length() ; i++){

        if(s[i] == '(' || s[i] == '{' || s[i] == '[' ){
            st.push(s[i]);
        }
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){

            if(s[i] == ')'){
                if(st.top() == '('){
                    st.pop();
                }
                else{
                    cout << "invalid string";
                    return;
                }
            }

            else if(s[i] == '}'){
                if(st.top() == '{'){
                    st.pop();
                }
                else{
                    cout << "invalid string";
                    return;
                }
            }

            else{
                if(st.top() == '['){
                    st.pop();
                }
                else{
                    cout << "invalid string";
                    return;
                }
            }

        }

        else{
            cout << "invalid character";
            return ; 
        }
    }

    cout << "valid string";
    return ; 
}

int main(){

    string s = "{[+)]}";

    isBalanced(s);
}