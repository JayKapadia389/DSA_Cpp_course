#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverse(string str){

    stack<string> st;
    int f = 0;
    int len = 0;

    for(int i=0 ; i <= str.length() ; i++){

        if(str[i] == ' ' || i == str.length()){
            st.push(str.substr(f,len));
            f = i+1;
            len = 0;
        }
        else{
            len++;
        }
    }

    str = "";

    while(!st.empty()){

        str += st.top() + " ";
        st.pop();
    }

    return str;

}


int main(){
    string s = "hello, how are you?";

    cout << reverse(s);
}