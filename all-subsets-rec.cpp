#include <iostream>
#include <string>

using namespace std;

void subsets( string str , string currStr , int n){

    if(n == str.length()){

        cout << currStr << " ";
        return ;

    }

    subsets(str , currStr+str[n] , n+1);
    subsets(str , currStr , n+1);
}

int main(){

    string s = "abc";

    subsets(s , "" ,0 );
}