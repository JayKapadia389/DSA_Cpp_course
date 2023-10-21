#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isHigh(char top , char curr){

    int n1 , n2 ; 

    switch(top){
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

                    cout << st.top();
                    st.pop();
                    // cout << " " << st.empty() << " ";
                }

                cout << "4" ; 

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

    cout << "3";

    return sol; 
}

int main(){

    string s = "(a-b/c)*(a/k-l)";

    cout << infixToPostfix(s);

}
