#include <iostream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

int evalPostfix(string s){

    stack<int> st ; 

    int o1, o2 , ans;

    for(int i = 0 ; i < s.length() ; i++){

        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){

            o1 = st.top();
            st.pop();

            o2 = st.top();
            st.pop();

            switch(s[i]){
                case '+':
                ans = o1 + o2 ;
                break;
                case '-':
                ans = o1 - o2 ;
                break;
                case '*':
                ans = o1 * o2 ;
                break;
                case '/':
                ans = o1 / o2 ;
                break;
                case '^':
                ans = pow(o1 , o2) ;
                break;

            }

            st.push(ans);
        }
        else{
            st.push(s[i] - '0');
        }
    }

    return st.top();
    
}

int main(){

    string s = "46+2/5*7+";

    cout << evalPostfix(s) ; 
}
