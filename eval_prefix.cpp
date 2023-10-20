#include <iostream>
#include <stack>
#include <string>
#include <math.h>

using namespace std;

int evalPrefix(string s){

    stack<int> st ;

    int o1 ,o2 , res;

    for(int i = s.length()-1 ; i>= 0 ; i--){

        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' ){
            o1 = st.top();
            st.pop();

            o2 = st.top();
            st.pop();

            switch(s[i]){
                case '+':
                res = o1 + o2;
                break; 
                case '-':
                res = o1 - o2;
                break; 
                case '*':
                res = o1 * o2;
                break; 
                case '/':
                res = o1 / o2;
                break; 
                case '^':
                res = pow(o1, o2);
                break; 

                
            }

            st.push(res);
        }

            else{

                st.push(s[i] - '0');
            }
        }

    return st.top();
    }



int main(){

    string s = "-+7*45+20";

    cout << evalPrefix(s);

}