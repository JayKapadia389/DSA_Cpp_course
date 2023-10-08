#include <iostream>

using namespace std;

int main(){

    int i=0;
    int n;
    char s[100] ;
    bool flag = 1;
    
    cin >> s ;

    while(s[i] != '\0'){
        i++;
    }

    if(i % 2 == 0){
        n=i/2;
    }
    else{
        n = (i+1)/2 ;
    }

    for(int j=0 ; j<n ; j++){

        if(s[n] != s[i-(n+1)]){
            flag = 0;
            break;
        }
    }

    if(flag){
        cout << "palindrome";
    }
    else{
        cout << "not palindrome";
    }
    
}