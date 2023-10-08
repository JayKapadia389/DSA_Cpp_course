#include <iostream>
#include <string>

using namespace std;

string xatend(string str){


    if(str == ""){
        return "";
    }
    else{

        string prevStr = xatend(str.substr(1));

        if(str[0] != 'x'){
            return str[0] + prevStr;
        }
        else{
            xatend(str.substr(1));
            return prevStr + 'x';
        }
    }
}

int main(){

    string s = "sxadxxhxwdix";

    cout << xatend(s);
}