#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isRedundant(string s){
    stack<char> st;

    for(int i =0 ; i < s.length() ; i++){

        if(s[i] == '(' || s[i] == '[' || s[i] == '{' || 
           s[i] == '+' || s[i] == '-' || s[i] == '*' ||
           s[i] == '/' ){

            st.push(s[i]);
           }

        else if(s[i] == ')' || s[i] == ']' || s[i] == '}' ){

            if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/' ){
                
                while(!(st.top() == '(' || st.top() == '{' || st.top() == '[' )){
                    st.pop();
                }

                st.pop();
            }

            else{
                return true;
            }
        }

    }

    return false;
}

int main(){

    string s = "((a+b)*c)";

    cout << isRedundant(s);

}