#include <iostream>
#include <stack>
#include <string>
#include <math.h>

using namespace std;

void reverse(string &s){

    stack<char> st;
    int l = s.length() ; 

    for(int i=0 ;i < l ; i++){
        st.push(s[0]);
        s = s.erase(0,1);
    }

    for(int i=0 ;i < l ; i++){
        cout << "2" << endl ;
        s += st.top() ;
        st.pop();
    }

    return ; 

}

void changeBrackets(string &s){

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '('){
            s[i] = ')';
            continue;
        }
        if(s[i] == ')'){
            s[i] = '(';
            continue;

        }
    }
}

bool isHigh(char top , char curr){

    int n1 , n2 ; 

    switch(top){
        case '(':
        n1 = 0 ;
        break;
        case '-':
        n1 = 1 ; 
        break;
        case '+':
        n1 = 2 ; 
        break;
        case '*':
        n1 = 3 ; 
        break;
        case '/':
        n1 = 4 ; 
        break;
    }

    switch(curr){
        case '(':
        n2 = 0 ;
        break;
        case '-':
        n2 = 1 ; 
        break;
        case '+':
        n2 = 2 ; 
        break;
        case '*':
        n2 = 3 ; 
        break;
        case '/':
        n2 = 4 ; 
        break;
    };

    return n1 <= n2 ;
}

string infixToPostfix(string s){

    string sol = "";
    stack<char> st ; 

    reverse(s);
    changeBrackets(s);

    for(int i = 0 ; i < s.length() ; i++){

        if(s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')' ){

            if(s[i] == '('){
                st.push(s[i]);
                // cout << "(" ;
            }
            else if(s[i] == ')'){

                // cout << "1";

                while(st.top() != '('){

                    sol += st.top();

                    // cout << st.top();
                    st.pop();
                    // cout << " " << st.empty() << " ";
                }

                // cout << "4" ; 

                st.pop();
            }
            else{

                if(!st.empty() && !isHigh(st.top() , s[i])){
                    sol += st.top();
                    st.pop();
                }

                st.push(s[i]);
            }

        }
        else{
            sol += s[i];
        }
    }

    while(!st.empty()){
        sol += st.top();
        st.pop();
    }

    // cout << "3";

    reverse(sol);

    return sol; 
}


int main(){

    string s = "(a-b/c)*(a/k-l)";

    // cout << infixToPrefix(s);

    
    cout << infixToPostfix(s); 

}
