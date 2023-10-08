#include <iostream>
#include <string>

using namespace std;

string rev(string str , int n){

    if(n==0){
        return str.substr(0,1);
    }
    else{
        string prevStr = rev(str , n-1);
        return str[n]+prevStr;
    }
}

int main(){

    string s = "binod";

    cout << rev(s , 4); 
}