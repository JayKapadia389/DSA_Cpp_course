#include <iostream>
#include <string>

using namespace std;

int main(){

    //a = 97

    int arr[26] = {0} ;
    int max = 0;
    char maxChar = 'a';

    string s = "wnnnfnnnfnnfnfk";

    for(int i=0 ; i<s.length() ;i++){
        static_cast<char>(arr[s[i]-97]++);
    }

    for(int i=0 ; i<26 ; i++){

        if(arr[i] > max){
            max = arr[i];
            maxChar = static_cast<char>(i + 'a');
        }
    }

    cout << max << " " << maxChar ;



}